//
// Created by Nika on 12.02.2019.
//

#ifndef RPNEQUATIONSOLVER_PARSER_H
#define RPNEQUATIONSOLVER_PARSER_H


#include "../Modeling/Equation.h"
#include "Operator.h"
#include <string>
#include <map>
#include <vector>

using namespace std;

class Parser {
public:
    vector<Operator<2>*> Operators;

    ~Parser();

    Equation *ParseEquation(string str);
    Evaluable *ParseEvaluable(string str);

private:
    Evaluable *_parseEvaluable(string str, string &remainder);
};

class ParsingException : public exception {};


#endif //RPNEQUATIONSOLVER_PARSER_H
