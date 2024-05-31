#ifndef CELL_H
#define CELL_H

#include <iostream>
#include <tuple>
using namespace std;

class Cell
{
protected:
    std::tuple<int, int> position;
    char type;

public:
    Cell(/* args */){};
    Cell(int x, int y, char type)
    {position = std::make_tuple(x, y); this->type = type;}
    virtual ~Cell(){};
    std::tuple<int, int> getPos(){return position;}
char getType(){return type;};
void setPos(int x, int y){position = std::make_tuple(x, y);}
void setType(char type){this->type = type;};


};




#endif