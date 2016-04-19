//
// Created by kagudkov on 19.04.16.
//


#include <vector>
#include "Sample.h"
#include "Feature.h"

class SampleContainer {
private:
    std::vector<Sample> samples;


public:
    SampleContainer(const std::vector<Sample> &samples);

    Sample getSample(size_t index) const;

    void initializeWeight();

    double getError(const Feature &feature) const;

private:
    size_t getNumberOfGirls();

    size_t getNumberOfBoys();
};


