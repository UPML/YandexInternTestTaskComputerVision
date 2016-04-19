#include <iostream>
#include <vector>
#include "Sample.h"
#include "Utils.h"

int main() {

    std::vector<Sample> samples = Utils().readDataFromFile("data/16x16/samples00.vec");
    int a = 2;

    return 0;
}