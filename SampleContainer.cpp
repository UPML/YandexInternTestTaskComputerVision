//
// Created by kagudkov on 19.04.16.
//

#include "SampleContainer.h"
#include "MessageException.h"
#include "Feature.h"

SampleContainer::SampleContainer(const std::vector<Sample> &samples) : samples(samples) { }

Sample SampleContainer::getSample(size_t index) const {
    if (index < 0 && index >= samples.size()) {
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















