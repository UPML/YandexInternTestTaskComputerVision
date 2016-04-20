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
    Pixel(size_t heightCoordinate, size_t widthCoordinate);

    size_t getHeightCoordinate() const;

    size_t getWidthCoordinate() const;

    const bool operator<(const Pixel &otherPixel) const;

    const bool operator!=(const Pixel &otherPixel) const;

    Pixel();
};

class Picture {
private:
    size_t height;
    size_t width;
    std::vector<intensity> pixels;

public:
    Picture(size_t height, size_t width, const std::vector<intensity> &pixels);

    size_t getHeight() const;

    size_t getWidth() const;

    intensity getPixelIntensity(const Pixel &pixel) const;

    Picture();
};

