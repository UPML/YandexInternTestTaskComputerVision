//
// Created by kagudkov on 19.04.16.
//

#include <iostream>
#include "MessageException.h"

MessageException::MessageException(std::string message) {
    std::cerr << message << "\n";
}

