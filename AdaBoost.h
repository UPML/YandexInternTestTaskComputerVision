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
    std::vector<double> B_t; // B_t = error_t / (1 - error_t); where error_t - error of t iterate.
    double percentGeneratedFeatures;

public:
    const std::vector<double> &getB_t() const;

    AdaBoost(const SampleContainer &samples, double percentGeneratedFeatures);

    void run(size_t numOfIteration);


    const std::vector<Feature> &getSelectedFeatures() const;

private:
    void init();

    void doIteration();
};


