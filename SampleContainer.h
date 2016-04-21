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

    void updateWeights(const Feature &feature, double B);

    double getError(const Feature &feature) const;


    std::vector<Feature> getRandomFeature(std::mt19937 &generator, size_t numberOfGeneratedFeatures) const;

    const size_t getHeight() const;
    const size_t getWidth() const;

private:
    size_t getNumberOfGirls();

    size_t getNumberOfBoys();

};


