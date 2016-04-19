//
// Created by kagudkov on 19.04.16.
//

#include <iostream>
#include "Picture.h"


intensity Picture::getPixelIntensity(const Pixel &pixel) const {
    if (pixel.getHeightCoordinate() > height || pixel.getHeightCoordinate() < 0 ||
        pixel.getWidthCoordinate() > width || pixel.getWidthCoordinate() < 0) {
        std::cerr << "Pixel has incorrect coordinate.\n Width: " << pixel.getWidthCoordinate() <<
        ". Height:" << pixel.getHeightCoordinate() << ",\n";
    }
    return pixels[pixel.getHeightCoordinate() * width + pixel.getWidthCoordinate()];
}

Picture::Picture(size_t height, size_t width, const std::vector<intensity> &pixels) : height(height), width(width),

                                                                                      pixels(pixels) { }

size_t Pixel::getHeightCoordinate() const {
    return heightCoordinate;
}

size_t Pixel::getWidthCoordinate() const {
    return widthCoordinate;
}

Pixel::Pixel(size_t heightCoordinate, size_t widthCoordinate) : heightCoordinate(heightCoordinate),
                                                                widthCoordinate(widthCoordinate) { }



