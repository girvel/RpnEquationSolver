#include <utility>

//
// Created by Nika on 24.02.2019.
//

#ifndef RPNEQUATIONSOLVER_OPERATION_H
#define RPNEQUATIONSOLVER_OPERATION_H

#include <string>
#include <functional>
#include "../Modeling/Evaluable.h"

using namespace std;


template<int power>
class Operator {
public:
    string Name;
    function<Evaluable *(Evaluable **)> CreateFunction;

    Operator(string Name, function<Evaluable *(Evaluable **)> CreateFunction)
            : CreateFunction(std::move(CreateFunction)), Name(std::move(Name)) {}
};


#endif //RPNEQUATIONSOLVER_OPERATION_H
