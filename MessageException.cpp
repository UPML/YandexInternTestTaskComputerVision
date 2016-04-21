//
// Created by kagudkov on 19.04.16.
//

#include <iostream>
#include "MessageException.h"

MessageException::MessageException(const std::string &message) {
    std::cerr << message << "\n";
}

