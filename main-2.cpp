#include "Cell.h"
#include "Effect.h"
#include "Utils.h"
#include "Character.h"
#include "Trap.h"
#include <iostream>
#include <tuple>
#include <random>

int main(int argc, char const *argv[])
{
    Character character(0,0);
    character.move(1,1);
    std::cout<<"character position: "<<get<0>(character.getPos())<<" "<<get<1>(character.getPos())<<std::endl;
    std::cout<<"character type: "<<character.getType()<<std::endl;
    Trap trap(0,0);
    std::cout<<"Trap active: "<<trap.isActive()<<std::endl;
   std::cout<<"Trap type: "<<trap.getType()<<std::endl;
    trap.apply(character);
    std::cout<<"Trap active: "<<trap.isActive()<<std::endl;
    std::cout<<"character type: "<<character.getType()<<std::endl;
    return 0;
}