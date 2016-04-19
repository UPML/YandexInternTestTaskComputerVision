//
// Created by kagudkov on 19.04.16.
//

#include "AdaBoost.h"

void AdaBoost::init() {
    samples.initializeWeight();
}

AdaBoost::AdaBoost(const SampleContainer &samples)
        : samples(samples) {
    init();
}





