//
// Created by kagudkov on 19.04.16.
//
#pragma once

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include "Sample.h"
#include "MessageException.h"

class Utils {

public:
    static std::vector<Sample> readDataFromFile(const std::string filename);
};


