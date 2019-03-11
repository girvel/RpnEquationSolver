//
// Created by Nika on 12.02.2019.
//

#include "Equation.h"

Equation::~Equation() {
    delete Left;
    delete Right;
}
