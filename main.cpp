#include <iostream>
#include <stdlib.h>
#include "Parsing/Parser.h"
#include "Parsing/Operator.h"
#include "Modeling/Operation.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    Parser *parser = new Parser();
    parser->Operators = {
            new Operator("+", [](Evaluable *arguments) {return new Operation<2>()})
    };

    string expression;

    while (true) {
        cout << " > ";
        getline(cin, expression);

        if (expression.empty())
        {
            cout << "До свидания!" << endl;
            break;
        }

        Evaluable *evaluable;
        try {
            evaluable = parser->ParseEvaluable(expression);
        }
        catch (ParsingException&) {
            cout << "Строка, которую вы ввели, некорректна." << endl;
            continue;
        }

        cout << evaluable->Calculate() << endl;
        delete evaluable;
    }

    delete parser;

    return 0;
}
