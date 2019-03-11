#include <utility>

//
// Created by Nika on 15.02.2019.
//

#ifndef RPNEQUATIONSOLVER_BINARYOPERATION_H
#define RPNEQUATIONSOLVER_BINARYOPERATION_H


#include "Evaluable.h"
#include <functional>

using namespace std;

template<int power>
class Operation : public Evaluable {
public:
    function<double(double *)> Action;
    Evaluable *Arguments[power];

    explicit Operation(function<double(double *)> Action)
            :Action(std::move(Action)) {}

    ~Operation() override {
        for (int i = 0; i < power; ++i) {
            delete Arguments[i];
        }

        delete[] Arguments;
    }

    bool ContainsVariable() override {
        for (int i = 0; i < power; ++i) {
            if (Arguments[i]->ContainsVariable())
            {
                return true;
            }
        }

        return false;
    }

protected:
    double _calculate() override {
        double arguments[power];

        for (int i = 0; i < power; ++i) {
            arguments[i] = Arguments[i]->Calculate();
        }

        return Action(arguments);
    }
};


#endif //RPNEQUATIONSOLVER_BINARYOPERATION_H
