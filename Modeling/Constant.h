//
// Created by Nika on 13.02.2019.
//

#ifndef RPNEQUATIONSOLVER_CONSTANT_H
#define RPNEQUATIONSOLVER_CONSTANT_H


#include "Evaluable.h"

class Constant : public Evaluable {
public:
    double Value;

    explicit Constant(double value);

    bool ContainsVariable() override;
    double _calculate() override;
};


#endif //RPNEQUATIONSOLVER_CONSTANT_H
