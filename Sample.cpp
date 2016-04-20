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

bool absDifferenceLessThan(const Picture picture, const Feature &feature, size_t maxDifference) {
    return abs(
            picture.getPixelIntensity(feature.getFirstPixel()) - picture.getPixelIntensity(feature.getSecondPixel())) <
           maxDifference;

}

double Sample::getError(const Feature &feature) const {
    return (getPrediction(feature) != isMale()) * getWeight();
}

Sample::Sample() {
    picture = Picture();
}

double Sample::getPrediction(const Feature &feature) const {
    if (!feature.indexIsCorrect()) {
        throw new MessageException("incorrect feature index");
    }
    std::vector<bool> features;
    features.reserve(FEATURE_NUMBER / 2);
    features.push_back(
            picture.getPixelIntensity(feature.getFirstPixel()) > picture.getPixelIntensity(feature.getSecondPixel()));
    features.push_back(absDifferenceLessThan(picture, feature, 5));
    features.push_back(absDifferenceLessThan(picture, feature, 10));
    features.push_back(absDifferenceLessThan(picture, feature, 25));
    features.push_back(absDifferenceLessThan(picture, feature, 50));
    if (feature.getFeatureIndex() < FEATURE_NUMBER / 2) {
        return features[feature.getFeatureIndex()];
    } else {
        return !features[feature.getFeatureIndex() - FEATURE_NUMBER / 2];
    }
}













