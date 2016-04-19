//
// Created by kagudkov on 19.04.16.
//
#pragma once

typedef unsigned char intensity;

#include <cstdio>
#include <vector>

class Pixel {
private:
    size_t heightCoordinate;
    size_t widthCoordinate;

public:
    size_t getHeightCoordinate() const {
        return heightCoordinate;
    }

    size_t getWidthCoordinate() const {
        return widthCoordinate;
    }

    Pixel(size_t heightCoordinate, size_t widthCoordinate) : heightCoordinate(heightCoordinate),
                                                             widthCoordinate(widthCoordinate) { }
};

class Picture {
private:
    size_t height;
    size_t width;
    std::vector<intensity> pixels;

public:
    Picture(size_t height, size_t width, const std::vector<intensity> &pixels) : height(height), width(width),

                                                                                 pixels(pixels) { }

    intensity getPixelIntensity(Pixel &pixel);
};

