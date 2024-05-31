#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <random>
#include <tuple>
#include <vector>

#include "Cell.h"
#include "Character.h"
#include "Effect.h"
#include "Trap.h"
#include "Utils.h"

using namespace std;

class Game {
 private:
  std::vector<Cell*> grid;
  int numCharacters;
  int numTraps;
  int gridWidth;
  int gridHeight;
  int maxIterations;
  double trapActivationDistance;

 public:
  Game(/* args */){};
  std::vector<Cell*>& getGrid() { return grid; };
  std::vector<Cell*> initGame(int numCharacters, int numTraps, int gridWidth,
                              int gridHeight) {
    grid.clear();
    for (int i = 0; i < numCharacters; i++) {
      std::tuple<int, int> pos = Utils::generateRandomPos(gridWidth, gridHeight);
      grid.push_back(new Character(std::get<0>(pos), std::get<1>(pos)));
    }
    for (int i = 0; i < numTraps; i++) {
      std::tuple<int, int> pos = Utils::generateRandomPos(gridWidth, gridHeight);
      grid.push_back(new Trap(std::get<0>(pos), std::get<1>(pos)));
    }
    return grid;
  };
  
  void gameLoop(int maxIterations, double trapActivationDistance) {
    int i=0;
    while(i<maxIterations){ {
      for (int j = 0; j < grid.size(); j++) {
        if (grid[j]->getType() == 'C') {
          dynamic_cast<Character*>(grid[j])->move(1, 0);
          for (int k = 0; k < grid.size(); k++) {
            if (grid[k]->getType() == 'T' &&
                Utils::calculateDistance(grid[j]->getPos(), grid[k]->getPos()) <= trapActivationDistance) {
              dynamic_cast<Trap*>(grid[k])->apply(*grid[j]);
            }
          }
        }
      }
      bool win = false;
      for (int j = 0; j < grid.size(); j++) {
        std::tuple<int, int> pos = grid[j]->getPos();
        if ((std::get<0>(pos) >= gridWidth - 1 || std::get<1>(pos) >= gridHeight - 1 ||
             std::get<0>(pos) <= 0 || std::get<1>(pos) <= 0) && grid[j]->getType() == 'C') {
          win = true;
          std::cout << "Character has won the game!" << std::endl;
          break;
        }
      }
      if (win) {
        break;
      }
      i++;
    if ((i == maxIterations) && (win == false))
    {
          std::cout << "Maximum number of iterations reached. Game over." << std::endl;
    };

    }
    
    }
  }
};

#endif
