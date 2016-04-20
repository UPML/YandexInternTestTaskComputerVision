//
// Created by kagudkov on 19.04.16.
//

#pragma once


#include "Picture.h"
#include "Feature.h"


class Sample {
private:
    Picture picture;
    bool male;
    double weight;


public:
    Sample(Picture &picture, bool isMale);

    Sample();

    double getWeight() const;

    void setWeight(double weight);

    const Picture &getPicture() const;

    bool isMale() const;

    double getError(const Feature &feature) const;

    double getPrediction(const Feature &feature) const;
};


