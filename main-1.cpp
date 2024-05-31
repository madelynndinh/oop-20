#include "Cell.h"
#include "Effect.h"
#include "Utils.h"
#include <iostream>
#include <tuple>
#include <random>

int main(int argc, char const *argv[])
{
    Utils utils;
    Cell cell(0, 0, 'a');
    std::tuple<int, int> pos = utils.generateRandomPos(10, 10);
    std::cout << std::get<0>(pos) << " " << std::get<1>(pos) << std::endl;
    return 0;
}
