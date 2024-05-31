#ifndef EFFECT_H
#define EFFECT_H
#include "Cell.h"

class Effect
{
private:
    /* data */
public:
    Effect(/* args */){};
    ~Effect(){};
    virtual void apply(Cell& cell)=0;
};



#endif