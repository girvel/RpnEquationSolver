//
// Created by Nika on 12.02.2019.
//

#ifndef RPNEQUATIONSOLVER_EVALUABLE_H
#define RPNEQUATIONSOLVER_EVALUABLE_H


class Evaluable {
public:
    virtual ~Evaluable() = default;
    virtual bool ContainsVariable() = 0;
    double Calculate();

protected:
    virtual double _calculate() = 0;
};


#endif //RPNEQUATIONSOLVER_EVALUABLE_H
