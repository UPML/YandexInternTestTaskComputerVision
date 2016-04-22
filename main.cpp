//#define _GLIBCXX_DEBUG

#include <iostream>
#include <vector>
#include <ctime>
#include "Utils.h"
#include "Scorer.h"

int main() {

    std::string pictureSize;
    std::cout << "please enter picture size. One from 16x16, 20x20 or 24x24" << std::endl;
    std::cin >> pictureSize;
    std::cout << "enter number of iterations\n";
    size_t numberOfIterations;
    std::cin >> numberOfIterations;
    std::cout << "enter percentage of tested features\n";
    double percentage;
    std::cin >> percentage;
    std::cout << "enter seed for random\n";
    size_t seed;
    std::cin >> seed;
    std::cout << "score on picture with size " << pictureSize << " " <<
    Scorer().getScore(pictureSize, numberOfIterations, percentage, seed);
    return 0;
}