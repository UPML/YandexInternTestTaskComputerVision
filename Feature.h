//
// Created by kagudkov on 19.04.16.
//
#pragma once

#include "Picture.h"
#define FEATURE_NUMBER 10

class Feature {
private:
    Pixel firstPixel;
    Pixel secondPixel;
    size_t featureIndex;


public:
    Feature(const Pixel &firstPixel, const Pixel &secondPixel, size_t featureIndex);

    bool indexIsCorrect() const;

    const Pixel &getFirstPixel() const;

    const Pixel &getSecondPixel() const;

    size_t getFeatureIndex() const;

    const bool operator<(const Feature &otherFeature) const ;

};


