#ifndef AJUMP_H
#define AJUMP_H

#include "action.h"


class AJump : public Action
{
public:
    AJump();
    void Execute() override;
    State Plan(State a) override;
};

#endif // A_FORWARD_H
