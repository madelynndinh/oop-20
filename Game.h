#ifndef GAME_H
#define GAME_H
#include "Cell.h"
#include "Effect.h"
#include "Utils.h"
#include "Character.h"
#include "Trap.h"
#include <iostream>
#include <tuple>
#include <random>
#include <vector>

using namespace std;    
class Game
{
private:
    std::vector<Cell*> grid;
    std::vector<Cell*>& getGrid(){
        return grid;
    };
    int numCharacters;
    int numTraps;
     int gridWidth;
      int gridHeight;
      int maxIterations;
       double trapActivationDistance;
public:
    Game(/* args */){};
    ~Game(){};

    void init(int numCharacters, int numTraps, int gridWidth, int gridHeight)
    {grid.clear();
for (int i = 0; i < numCharacters; i++)
{
    grid.push_back(new Character(rand() % gridWidth, rand() % gridHeight));
}
for (int i = 0; i < numTraps; i++)
{
    grid.push_back(new Trap(rand() % gridWidth, rand() % gridHeight));
}
    };
    void gameLoop(int maxIterations, double trapActivationDistance)
    {
        int i = 0;
        while(i < maxIterations)
        {
            for (int j = 0; j < grid.size(); j++)
            {
                if (grid[j]->getType()=='C')
                {
                    dynamic_cast<Character*>(grid[j])->move(1,0);
                    for (int k = 0; k <  grid.size(); i++)
                    {
                       if (grid[k]->getType()=='T'&&  Utils::calculateDistance(grid[j]->getPos(),grid[k]->getPos()) <= trapActivationDistance)
                       {
                        dynamic_cast<Trap*>(grid[k])->apply(*grid[j]);
                         std::cout<<"Character is trapped"<<std::endl;
                       }
                    }
                    
                }
            }
            bool win = false;
           for (int j = 0; j < grid.size(); j++)
            {
                if (grid[j]->getType()=='C')
                {win = true;
                std::cout<<"Character has won the game!"<<std::endl;
                break;}
            i++;
        }
    }
    std::cout<<"Maximum number of iterations reached. Game over."<<std::endl;

}
};




#endif