//
// Created by Nika on 12.02.2019.
//

#include "Evaluable.h"

double Evaluable::Calculate() {
    if (ContainsVariable()) throw 123; // TODO exc
    return _calculate();
}
