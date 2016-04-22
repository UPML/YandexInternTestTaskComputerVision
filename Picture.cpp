//
// Created by kagudkov on 19.04.16.
//

#include <iostream>
#include "Picture.h"


intensity Picture::getPixelIntensity(const Pixel &pixel) const {
    if (pixel.getHeightCoordinate() > height || pixel.getWidthCoordinate() > width) {
        std::cerr << "Pixel has incorrect coordinate.\n Width: " << pixel.getWidthCoordinate() <<
        ". Height:" << pixel.getHeightCoordinate() << ",\n";
    }
    return pixels[pixel.getHeightCoordinate() * width + pixel.getWidthCoordinate()];
}

Picture::Picture(size_t height, size_t width, const std::vector<intensity> &pixels) : height(height), width(width),

                                                                                      pixels(pixels) { }

size_t Picture::getHeight() const {
    return height;
}

size_t Picture::getWidth() const {
    return width;
}

Picture::Picture() {

}


size_t Pixel::getHeightCoordinate() const {
    return heightCoordinate;
}

size_t Pixel::getWidthCoordinate() const {
    return widthCoordinate;
}

Pixel::Pixel(size_t heightCoordinate, size_t widthCoordinate) : heightCoordinate(heightCoordinate),
                                                                widthCoordinate(widthCoordinate) { }

bool Pixel::operator<(const Pixel &otherPixel) const {
    if (getWidthCoordinate() != otherPixel.getWidthCoordinate()) {
        return getWidthCoordinate() < otherPixel.getWidthCoordinate();
    } else {
        return getHeightCoordinate() < otherPixel.getHeightCoordinate();
    }
}

bool Pixel::operator!=(const Pixel &otherPixel) const {
    return (*this < otherPixel) || (otherPixel < *this);
}

Pixel::Pixel() {
    heightCoordinate = 0;
    widthCoordinate = 0;
}

void  Pixel::print(std::fstream &output) const {
    output << "x = " << widthCoordinate << " y  = " << heightCoordinate << std::endl;
}











