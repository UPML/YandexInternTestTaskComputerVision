//
// Created by kagudkov on 19.04.16.
//
#pragma once

#include "Picture.h"

class Feature {
    Pixel firstPixel;
    Pixel secondPixel;
    size_t featureIndex;


public:
    Feature(const Pixel &firstPixel, const Pixel &secondPixel, size_t featureIndex);

    bool indexIsCorrect() const ;

    const Pixel &getFirstPixel() const;

    const Pixel &getSecondPixel() const;

    size_t getFeatureIndex() const;
};


