#ifndef ATURNLEFT_H
#define ATURNLEFT_H

#include "action.h"

class ATurnLeft : public Action
{
public:
    ATurnLeft();
    void Execute() override;
    State Plan(State a) override;
};

#endif // ATURNLEFT_H
