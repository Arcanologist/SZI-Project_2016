#ifndef ATURNRIGHT_H
#define ATURNRIGHT_H

#include "action.h"

class ATurnRight : public Action
{
public:
    ATurnRight();
    void Execute() override;
    State Plan(State a) override;
};

#endif // ATURNRIGHT_H
