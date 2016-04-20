//
// Created by kagudkov on 19.04.16.
//

#include <set>
#include "AdaBoost.h"
#include <algorithm>

void AdaBoost::init() {
    samples.initializeWeight();
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
    std::set<Feature> newTestedFeature;
    while (newTestedFeature.size() < percentGeneratedFeatures * samples.getSize()) {
        Feature nextRandomFeature = samples.getRandomFeature();
        if (newTestedFeature.find(nextRandomFeature) == newTestedFeature.end() &&
            selectedFeatures.find(nextRandomFeature) == selectedFeatures.end()) {
            newTestedFeature.insert(nextRandomFeature);
        }
    }

    double minError = 1;
    Feature bestFeature = *newTestedFeature.begin();
    std::for_each(newTestedFeature.begin(), newTestedFeature.end(), [](Feature const &feature) {
        if(minError > samples.getError(feature)) {
            minError = samples.getError(feature);
            bestFeature = feature;
        }
    });
    selectedFeatures.insert(bestFeature);
}









