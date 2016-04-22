//
// Created by kagudkov on 19.04.16.
//

#include <set>
#include "AdaBoost.h"
#include <algorithm>
#include <iostream>

void AdaBoost::init(size_t randomSeed) {
    samples.initializeWeight();
    randomGenerator = std::mt19937(randomSeed);
}

AdaBoost::AdaBoost(SampleContainer samples, double percentGeneratedFeatures, size_t randomSeed)
        : samples(std::move(samples)),
          percentGeneratedFeatures(percentGeneratedFeatures) {
    init(randomSeed);

}

void AdaBoost::run(size_t numOfIteration) {
    for (size_t i = 0; i < numOfIteration; ++i) {
        doIteration();
    }
}

void AdaBoost::doIteration() {
    std::vector<Feature> newTestedFeature;

    size_t numberOfGeneratedFeature =
            static_cast<size_t> (FEATURE_NUMBER * pow(samples.getHeight() * samples.getWidth(), 2) *
                                 percentGeneratedFeatures);

    newTestedFeature = samples.getRandomFeature(randomGenerator, numberOfGeneratedFeature);

    double minError = 1;
    Feature bestFeature = *newTestedFeature.begin();
#pragma omp parallel for
    for (size_t i = 0; i < newTestedFeature.size(); ++i) {
        double nowError = samples.getError(newTestedFeature[i]);
        if (minError > nowError) {
#pragma omp critical(updateMin)
            {
                if (minError > nowError) {
                    minError = nowError;
                    bestFeature = newTestedFeature[i];
                }
            }
        }
    }
    selectedFeatures.push_back(bestFeature);
    double nextB_t = minError / (1 - minError);
    B_t.push_back(nextB_t);
    samples.updateWeights(bestFeature, nextB_t);
}

const std::vector<Feature> &AdaBoost::getSelectedFeatures() const {
    return selectedFeatures;
}

const std::vector<double> &AdaBoost::getB_t() const {
    return B_t;
}
















