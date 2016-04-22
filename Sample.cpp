//
// Created by kagudkov on 19.04.16.
//

#include <cstdlib>
#include "Sample.h"
#include "MessageException.h"

Sample::Sample(Picture &picture, bool isMale) : picture(picture), male(isMale) {
    weight = 0;
}

double Sample::getWeight() const {
    return weight;
}

void Sample::setWeight(double weight) {
    Sample::weight = weight;
}

const Picture &Sample::getPicture() const {
    return picture;
}

bool Sample::isMale() const {
    return male;
}

namespace {
    bool absDifferenceLessThan(const Picture &picture, const Feature &feature, size_t maxDifference) {
        return static_cast<size_t >(abs(
                picture.getPixelIntensity(feature.getFirstPixel()) -
                picture.getPixelIntensity(feature.getSecondPixel()))) <
               maxDifference;

    }
}

double Sample::getError(const Feature &feature) const {
    return (getPrediction(feature) != isMale()) * getWeight();
}

Sample::Sample() {
    picture = Picture();
}

double Sample::getPrediction(const Feature &feature) const {

    std::vector<bool> differenceBetweenPixels;
    differenceBetweenPixels.reserve(FEATURE_NUMBER / 2);

    differenceBetweenPixels.push_back(
            picture.getPixelIntensity(feature.getFirstPixel()) > picture.getPixelIntensity(feature.getSecondPixel()));
    for (auto maxDifference : {5, 10, 25, 50}) {
        differenceBetweenPixels.push_back(absDifferenceLessThan(picture, feature, (size_t) maxDifference));
    };

    if (feature.getFeatureIndex() < FEATURE_NUMBER / 2) {
        return differenceBetweenPixels[feature.getFeatureIndex()];
    } else {
        return !differenceBetweenPixels[feature.getFeatureIndex() - FEATURE_NUMBER / 2];
    }
}













