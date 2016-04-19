//
// Created by kagudkov on 19.04.16.
//

#pragma once

#include <vector>
#include "Sample.h"
#include "SampleContainer.h"

class AdaBoost {
private:
    SampleContainer samples;
    std::vector<Feature> selectedFeatures;
    double percentGeneratedFeatures;

public:

    AdaBoost(const SampleContainer &samples, double percentGeneratedFeatures);
    void run(size_t numOfIteration);
private:
    void init();
};


