//
// Created by kagudkov on 19.04.16.
//

#include <set>
#include "AdaBoost.h"
#include <algorithm>
#include <iostream>

void AdaBoost::init() {
    samples.initializeWeight();
    srand(static_cast<unsigned int> (time(0)));
}

AdaBoost::AdaBoost(const SampleContainer &samples, double percentGeneratedFeatures)
        : samples(samples),
          percentGeneratedFeatures(percentGeneratedFeatures) {
    init();

}

void AdaBoost::run(size_t numOfIteration) {
    for (int i = 0; i < numOfIteration; ++i) {
        doIteration();
    }
}

void AdaBoost::doIteration() {
    std::vector<Feature> newTestedFeature;
    while (newTestedFeature.size() < percentGeneratedFeatures * samples.getSize() * FEATURE_NUMBER) {
        Feature nextRandomFeature = samples.getRandomFeature();
        //изначально проверял, что раньше такой фичи не встречалось, но из-за этой проверки итерация выполнялась
        // очень долго
        newTestedFeature.push_back(nextRandomFeature);
    }

    double minError = 1;
    Feature bestFeature = *newTestedFeature.begin();
    for (Feature feature : newTestedFeature) {
        if (minError > samples.getError(feature)) {
            minError = samples.getError(feature);
            bestFeature = feature;
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
















