#ifndef UTILS_H
#define UTILS_H
#include <iostream>
#include <tuple>
#include <random>

using namespace std;
class Utils
{
private:
    /* data */
public:
    Utils(/* args */){};
    ~Utils(){};
    static std::tuple<int, int> generateRandomPos(int gridWidth, int gridHeight){
        return std::make_tuple(rand() % gridWidth, rand() % gridHeight);
    }
    static double calculateDistance(std::tuple<int, int> pos1, std::tuple<int, int> pos2) {
        return sqrt(pow(std::get<0>(pos1) - std::get<0>(pos2), 2) + pow(std::get<1>(pos1) - std::get<1>(pos2), 2));
    }
};


#endif