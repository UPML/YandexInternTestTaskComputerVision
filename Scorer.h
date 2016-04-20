//
// Created by kagudkov on 20.04.16.
//


#include "Feature.h"
#include "Sample.h"

class Scorer {
public:

    Scorer();

    static std::vector<bool> predict(const std::vector<Sample> &test, const std::vector<Feature> &selectedFeatures,
                                     const std::vector<double> &B_t);


    static double getScore(const std::vector<Sample> &test, const std::vector<Feature> &selectedFeatures,
                           const std::vector<double> &B_t);


};


