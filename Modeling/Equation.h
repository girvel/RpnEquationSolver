//
// Created by Nika on 12.02.2019.
//

#ifndef RPNEQUATIONSOLVER_EQUATION_H
#define RPNEQUATIONSOLVER_EQUATION_H


#include "Evaluable.h"

class Equation {
public:
    Evaluable *Left, *Right;
    ~Equation();
};


#endif //RPNEQUATIONSOLVER_EQUATION_H
