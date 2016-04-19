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
    std::vector<

public:

    AdaBoost(const SampleContainer &samples);
private:
    void init();
};


