//
// Created by kagudkov on 19.04.16.
//

#pragma once

#include <vector>
#include <random>
#include "Sample.h"
#include "SampleContainer.h"

class AdaBoost {
private:
    SampleContainer samples;
    std::vector<Feature> selectedFeatures;
    std::vector<double> B_t; // B_t = error_t / (1 - error_t); where error_t - error of t iterate.
    double percentGeneratedFeatures;
    std::mt19937 randomGenerator;

public:
    const std::vector<double> &getB_t() const;

    AdaBoost(const SampleContainer &samples, double percentGeneratedFeatures, size_t randomSeed);

    void run(size_t numOfIteration);


    const std::vector<Feature> &getSelectedFeatures() const;

private:
    void init(size_t randomSeed);

    void doIteration();
};


