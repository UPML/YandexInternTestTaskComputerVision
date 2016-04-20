//
// Created by kagudkov on 20.04.16.
//

#include <cmath>
#include "Scorer.h"


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






