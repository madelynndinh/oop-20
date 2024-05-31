#ifndef CHARACTER_H
#define CHARACTER_H
#include <iostream>
#include "Cell.h"

class Character:public Cell
{
private:
    /* data */
public:
    Character(int x, int y):Cell(x, y, 'C'){};
    ~Character(){};
    void move(int dx, int dy)
    {
        setPos(get<0>(getPos()) + dx, get<1>(getPos()) + dy);
    }
};

#endif