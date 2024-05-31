#include "Game.h"
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
    Game game;
    game.init(2, 2, 10, 10);
    game.gameLoop(10, 10);
    return 0;
}
