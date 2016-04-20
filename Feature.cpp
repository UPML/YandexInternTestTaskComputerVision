//
// Created by kagudkov on 19.04.16.
//

#include "Feature.h"

Feature::Feature(const Pixel &firstPixel, const Pixel &secondPixel, size_t featureIndex) : firstPixel(firstPixel),
                                                                                           secondPixel(secondPixel),
                                                                                           featureIndex(
                                                                                                   featureIndex) { }

bool Feature::indexIsCorrect() const {
    return featureIndex >= 0 && featureIndex < FEATURE_NUMBER;
}

const Pixel &Feature::getFirstPixel() const {
    return firstPixel;
}

const Pixel &Feature::getSecondPixel() const {
    return secondPixel;
}

size_t Feature::getFeatureIndex() const  {
    return featureIndex;
}

const bool Feature::operator<(const Feature &otherFeature) const {
    if(firstPixel != otherFeature.getFirstPixel()){
        return firstPixel < otherFeature.getFirstPixel();
    } else if(secondPixel != otherFeature.getSecondPixel()) {
        return secondPixel < otherFeature.getSecondPixel();
    } else {
        return featureIndex < otherFeature.getFeatureIndex();
    }
}

const bool Feature::operator==(const Feature &otherFeature) const {
    return !(*this < otherFeature) && !(otherFeature < *this);
}

Feature::Feature() {
    firstPixel = Pixel();
    secondPixel = Pixel();
}













