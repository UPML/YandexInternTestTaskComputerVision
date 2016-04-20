//
// Created by kagudkov on 19.04.16.
//

#pragma once

#include <exception>
#include <string>

class MessageException : std::exception {

public:
    MessageException(std::string message);
};


