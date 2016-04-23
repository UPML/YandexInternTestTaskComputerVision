//
// Created by kagudkov on 19.04.16.
//

#include <iostream>
#include <cassert>
#include <random>
#include "SampleContainer.h"
#include "MessageException.h"

SampleContainer::SampleContainer(std::vector<Sample> samples) : samples(std::move(samples)) {
    assert(SampleContainer::samples.size() != 0);
}

Sample SampleContainer::getSample(size_t index) const {
    if (index >= samples.size()) {
        throw new MessageException("incorrect index");
    }

    return samples[index];
}

void SampleContainer::initializeWeight() {
    size_t numberOfGirls = getNumberOfGirls();
    size_t numberOfBoys = getNumberOfBoys();
    for (size_t i = 0; i < samples.size(); ++i) {
        if (samples[i].isMale()) {
            samples[i].setWeight(0.5 / numberOfBoys);
        } else {
            samples[i].setWeight(0.5 / numberOfGirls);
        }
    }
}

void SampleContainer::updateWeights(const Feature &feature, double B) {
    double sumWeight = 0;

    for (size_t i = 0; i < samples.size(); ++i) {
        if (samples[i].getPrediction(feature) == samples[i].isMale()) {
            samples[i].setWeight(samples[i].getWeight() * B);
        }
        sumWeight += samples[i].getWeight();
    }

    for (Sample &sample : samples) {
        sample.setWeight(sample.getWeight() / sumWeight);
    }
}


size_t SampleContainer::getNumberOfGirls() {
    size_t numberOfGirl = 0;
    for (size_t i = 0; i < samples.size(); ++i) {
        numberOfGirl += !samples[i].isMale();
    }
    return numberOfGirl;
}

size_t SampleContainer::getNumberOfBoys() {
    return samples.size() - getNumberOfGirls();
}

double SampleContainer::getError(const Feature &feature) const {
    double sumError = 0;
    for (size_t i = 0; i < samples.size(); ++i) {
        sumError += samples[i].getError(feature);
    }
    return sumError;
}


std::vector<Feature> SampleContainer::getRandomFeaturePairs(std::mt19937 &generator,
                                                       size_t numberOfGeneratedFeatures) const {
    std::vector<Feature> generatedFeature;
    generatedFeature.reserve(numberOfGeneratedFeatures);
    std::uniform_int_distribution<size_t> uidFeatureIndex(0, FEATURE_NUMBER - 1);
    std::uniform_int_distribution<size_t> uidPixelWidth(0, getWidth() - 1);
    std::uniform_int_distribution<size_t> uidPixelHeight(0, getHeight() - 1);

    for (size_t i = 0; i < numberOfGeneratedFeatures; ++i) {
        //add a feature pair
        size_t  featureIndex = uidFeatureIndex(generator);
        Pixel firstPixel(uidPixelHeight(generator), uidPixelWidth(generator));
        Pixel socondPixel(uidPixelHeight(generator), uidPixelWidth(generator));
        generatedFeature.emplace_back(firstPixel,socondPixel,featureIndex);
        generatedFeature.emplace_back(firstPixel,socondPixel,(featureIndex + FEATURE_NUMBER /2) % FEATURE_NUMBER );
    }
    return generatedFeature;
}

size_t SampleContainer::getHeight() const {
    return getSample(0).getPicture().getHeight();
}

size_t SampleContainer::getWidth() const {
    return getSample(0).getPicture().getWidth();
}

SampleContainer::SampleContainer(SampleContainer &&sampleContainer) : samples(std::move(sampleContainer.samples)) {
}

SampleContainer &SampleContainer::operator=(SampleContainer &&sampleContainer) {
    samples = std::move(sampleContainer.samples);
    return *this;
}
































