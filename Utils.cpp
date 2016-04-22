//
// Created by kagudkov on 19.04.16.
//

#include <bits/unique_ptr.h>
#include "Utils.h"

std::vector<Sample> readDataFromFile(const std::string &filename) {
    std::ifstream inputStream;
    inputStream.open(filename.c_str(), std::ifstream::in | std::ifstream::binary);
    if (!inputStream.is_open()) {
        throw new MessageException(filename + " file not found.");
    }


    char c;

    if (!inputStream.get(c)) {
        throw new MessageException("can't read width");
    }
    size_t width = static_cast<size_t >(c);

    if (!inputStream.get(c)) {
        throw new MessageException("can't read height");
    }
    size_t height = static_cast<size_t>(c);

    //Читаем пиксели картинки и заодно пол.
    size_t buf_size = height * width + 1;
    std::unique_ptr<char[]> buffer(new char[buf_size]);

    std::vector<Sample> readSamples;

    while (inputStream.good()) {
        inputStream.read(buffer.get(), buf_size);

        if (buf_size == static_cast<size_t >(inputStream.gcount())) {
            if (buffer[buf_size - 1] != -1 && buffer[buf_size - 1] != 1) {
                throw new MessageException("incorrect data format, you must write 1 for male or 255 for female.");
            }
            //если данные прочитались корректно добавляем ещё одни объект для обучения.
            std::vector<intensity> pixels;
            pixels.reserve(buf_size - 1);
            for (size_t i = 0; i < buf_size; ++i) {
                pixels.push_back(static_cast<intensity >(buffer[i]));
            }
            Picture newPicture(height, width, pixels);
            readSamples.emplace_back(Sample(newPicture, buffer[buf_size - 1] == 1));

        }
        else if (inputStream.eof()) {
            break;
        }
        else {
            throw new MessageException("Unexpected end of file.");
        }
    }
    inputStream.close();
    return readSamples;
}



