//
// Created by kagudkov on 19.04.16.
//

#include <assert.h>
#include "Feature.h"

Feature::Feature(const Pixel &firstPixel, const Pixel &secondPixel, size_t featureIndex) : firstPixel(firstPixel),
                                                                                           secondPixel(secondPixel) {
    assert(indexIsCorrect(featureIndex));
    Feature::featureIndex = featureIndex;

}

bool Feature::indexIsCorrect(size_t index) const {
    return index < FEATURE_NUMBER;
}

const Pixel &Feature::getFirstPixel() const {
    return firstPixel;
}

const Pixel &Feature::getSecondPixel() const {
    return secondPixel;
}

size_t Feature::getFeatureIndex() const {
    return featureIndex;
}

bool Feature::operator<(const Feature &otherFeature) const {
    if (firstPixel != otherFeature.firstPixel) {
        return firstPixel < otherFeature.firstPixel;
    } else if (secondPixel != otherFeature.secondPixel) {
        return secondPixel < otherFeature.secondPixel;
    } else {
        return featureIndex < otherFeature.featureIndex;
    }
}

bool Feature::operator==(const Feature &otherFeature) const {
    return !(*this < otherFeature) && !(otherFeature < *this);
}

Feature::Feature() {
    firstPixel = Pixel();
    secondPixel = Pixel();
}

void Feature::print(std::fstream &output) const {
    output << "first pixel: \n";
    firstPixel.print(output);
    output << "second pixel: \n";
    secondPixel.print(output);
    output << "index:" << featureIndex << std::endl;
}
















