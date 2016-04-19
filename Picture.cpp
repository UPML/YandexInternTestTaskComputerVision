//
// Created by kagudkov on 19.04.16.
//

#include <iostream>
#include "Picture.h"


intensity Picture::getPixelIntensity(Pixel &pixel) {
    if (pixel.getHeightCoordinate() > height || pixel.getHeightCoordinate() < 0 ||
        pixel.getWidthCoordinate() > width || pixel.getWidthCoordinate() < 0) {
        std::cerr << "Pixel has incorrect coordinate.\n Width: " << pixel.getWidthCoordinate() <<
        ". Height:" << pixel.getHeightCoordinate() << ",\n";
    }
    return pixels[pixel.getHeightCoordinate() * width + pixel.getWidthCoordinate()];
}

