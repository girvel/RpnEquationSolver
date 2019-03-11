//
// Created by Nika on 13.02.2019.
//

#include "Constant.h"

bool Constant::ContainsVariable() {
    return false;
}

double Constant::_calculate() {
    return Value;
}

Constant::Constant(double value) {
    Value = value;
}
