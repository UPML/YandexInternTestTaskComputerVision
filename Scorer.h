//
// Created by kagudkov on 20.04.16.
//


#include <string>
#include "Feature.h"
#include "Sample.h"

class Scorer {
public:

    Scorer();

    static std::vector<bool> predict(const std::vector<Sample> &test, const std::vector<Feature> &selectedFeatures,
                                     const std::vector<double> &B_t);


    static double getScore(const std::vector<Sample> &test, const std::vector<Feature> &selectedFeatures,
                           const std::vector<double> &B_t);


    static double getScore(std::string const &pictureSize, size_t numberOfIteration, double persentOfTestedFeature,
                           size_t seed);
};


