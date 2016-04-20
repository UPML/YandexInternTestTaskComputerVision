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
    std::cout << "score on picture with size" <<  Scorer().getScore(pictureSize);
    return 0;
}