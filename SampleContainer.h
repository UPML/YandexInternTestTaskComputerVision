//
// Created by kagudkov on 19.04.16.
//

#pragma once
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

    void updateWeights(Feature feature, double B);

    double getError(const Feature &feature) const;

    double getSize() const;

    Feature getRandomFeature() const;

private:
    size_t getNumberOfGirls();

    size_t getNumberOfBoys();

    Pixel randomPixel() const;
};


