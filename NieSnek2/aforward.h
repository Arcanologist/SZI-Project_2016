#ifndef AFORWARD_H
#define AFORWARD_H

#include "action.h"


class AForward : public Action
{
public:
    AForward();
    void Execute() override;
    State Plan(State a) override;
};

#endif // A_FORWARD_H
