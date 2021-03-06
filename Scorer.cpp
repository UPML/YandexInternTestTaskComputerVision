//
// Created by kagudkov on 20.04.16.
//

#include <cmath>
#include <assert.h>
#include <ctime>
#include "Scorer.h"
#include "Utils.h"
#include "AdaBoost.h"


std::vector<bool> Scorer::predict(const std::vector<Sample> &test, const std::vector<Feature> &selectedFeatures,
                                  const std::vector<double> &B_t) {
    std::vector<bool> prediction;
    prediction.reserve(test.size());
    for (size_t i = 0; i < test.size(); ++i) {
        double left = 0;
        double right = 0;
        for (size_t j = 0; j < selectedFeatures.size(); ++j) {
            right += log(1 / B_t[j]) * 0.5;
            left += log(1 / B_t[j]) * test[i].getPrediction(selectedFeatures[j]);
        }
        prediction.push_back(left >= right);
    }
    return prediction;
}


double Scorer::getScore(const std::vector<Sample> &test, const std::vector<Feature> &selectedFeatures,
                        const std::vector<double> &B_t) {
    std::vector<bool> prediction = Scorer().predict(test, selectedFeatures, B_t);
    size_t score = 0;
    for (size_t i = 0; i < test.size(); ++i) {
        score += (test[i].isMale() == prediction[i]);
    }
    return static_cast<double >(score) / test.size();
}


Scorer::Scorer() {

}

double Scorer::getScore(const std::string &pictureSize) {
    assert(pictureSize == "16x16" || pictureSize == "20x20" || pictureSize == "24x24");
    std::string inputDataFilename = "data/" + pictureSize + "/samples00.vec";
    std::vector<Sample> samples = Utils().readDataFromFile(inputDataFilename);
    std::vector<Sample> train;
    std::vector<Sample> test;
    for (int i = 0; i < samples.size(); ++i) {
        if (i < samples.size() * 0.8) {
            train.push_back(samples[i]);
        } else {
            test.push_back(samples[i]);
        }
    }
    AdaBoost adaBoost = AdaBoost(train, 0.01);
    std::fstream fsOutput;
    fsOutput.open("result" + pictureSize + ".txt", std::fstream::out | std::fstream::app);
    clock_t startIterate = std::clock();
    for (size_t i = 0; i < 1000; ++i) {
        adaBoost.run(1);
        fsOutput << i << " " << Scorer().getScore(test, adaBoost.getSelectedFeatures(), adaBoost.getB_t()) << " ";
        fsOutput << (std::clock() - startIterate) / static_cast<double > (CLOCKS_PER_SEC) << "\n";
    }
    fsOutput.close();
    return Scorer().getScore(test, adaBoost.getSelectedFeatures(), adaBoost.getB_t());
}








