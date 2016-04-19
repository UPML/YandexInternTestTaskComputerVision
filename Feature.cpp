//
// Created by kagudkov on 19.04.16.
//

#include "Feature.h"

Feature::Feature(const Pixel &firstPixel, const Pixel &secondPixel, size_t featureIndex) : firstPixel(firstPixel),
                                                                                           secondPixel(secondPixel),
                                                                                           featureIndex(
                                                                                                   featureIndex) { }

bool Feature::indexIsCorrect() const {
    return featureIndex >= 0 && featureIndex <= 9;
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








