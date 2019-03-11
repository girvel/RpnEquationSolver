//
// Created by Nika on 12.02.2019.
//

#include <regex>
#include "Parser.h"
#include "../Modeling/Constant.h"

using namespace std;

const regex empty_regex(R"(^\s*$)");

Equation *Parser::ParseEquation(string str) {
    return new Equation { ParseEvaluable(str), new Constant(0) };
}

Evaluable *Parser::ParseEvaluable(string str) {
    string remainder;
    auto result = _parseEvaluable(str, remainder);

    if (remainder.empty() || regex_search(str, empty_regex)) {
        return result;
    }

    throw ParsingException();
}

Evaluable *Parser::_parseEvaluable(string str, string &remainder) {
    smatch match;

    const regex constant_regex(R"(^([\S\s]*)(\d+)\s*$)");

    if (regex_search(str, match, constant_regex)) {
        remainder = match[1];
        return new Constant(stod(match[2]));
    }

    const regex operation_regex(R"(^([\S\s]*)(\+|\-|\*|\/)\s*$)");

    if (regex_search(str, match, operation_regex)) {
        Evaluable *arguments[2] = {
            _parseEvaluable(match[1], remainder),
            _parseEvaluable(remainder, remainder)
        };

        for (auto &Operator : Operators) {
            if (match[2] == Operator->GetName()) {
                return Operator->Create(arguments);
            }
        }
    }

    throw ParsingException();
}

Parser::~Parser() {
    for (auto &Operator : Operators) {
        delete Operator;
    }
}
