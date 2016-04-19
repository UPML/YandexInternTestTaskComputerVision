//
// Created by kagudkov on 19.04.16.
//

#pragma once


#include "Picture.h"

class Sample {
private:
    Picture picture;
    bool isMale;


public:
    const Picture &getPicture() const {
        return picture;
    }

    bool isIsMale() const {
        return isMale;
    }

public:
    Sample(Picture &picture, bool isMale) : picture(picture), isMale(isMale) { }
};


