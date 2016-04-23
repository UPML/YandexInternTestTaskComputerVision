//
// Created by kagudkov on 20.04.16.
//


#include <string>
#include "Feature.h"
#include "Sample.h"
#include "AdaBoost.h"

class Scorer {
public:

    Scorer();

    std::vector<bool> predict(const std::vector<Sample> &test, const std::vector<Feature> &selectedFeatures,
                                     const std::vector<double> &B_t);


    double getScoreKFold(std::string const &pictureSize, size_t numberOfIteration, double percentOfTestedFeature,
                         size_t seed, size_t numberOfFolds);

private:
    void addKFold(size_t indexOfFold, std::vector<Sample> &test, std::vector<Sample> &train,
                  std::vector<Sample> &samples, size_t numberOfFolds);

    double getScore(const std::vector<Sample> &test, const std::vector<Feature> &selectedFeatures,
                    const std::vector<double> &B_t);


};


