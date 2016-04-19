//#define _GLIBCXX_DEBUG

#include <iostream>
#include <vector>
#include "Sample.h"
#include "Utils.h"
#include "SampleContainer.h"

int main() {

    std::vector<Sample> samples = Utils().readDataFromFile("data/16x16/samples00.vec");
    SampleContainer sampleContainer = SampleContainer(samples);
    return 0;
}