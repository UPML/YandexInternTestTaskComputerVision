//
// Created by kagudkov on 19.04.16.
//

#include "AdaBoost.h"

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

    }
}







