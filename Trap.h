#ifndef TRAP_H
#define TRAP_H
#include <iostream>
#include "Cell.h"
#include "Effect.h"

class Trap: public Effect, public Cell
{
private:
    bool active = true;
public:
    Trap(int x, int y):Cell(x, y, 'T'){};
    ~Trap(){};
    bool isActive(){return active;}
    void apply(Cell& cell)
    {
        cell.setType('T');
        this->active = false;
    };
};
#endif