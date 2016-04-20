//
// Created by kagudkov on 20.04.16.
//

#include <cmath>
#include "Scorer.h"


std::vector<bool> Scorer::predict(const std::vector<Sample> &test, const std::vector<Feature> &selectedFeatures,
                                         const std::vector<double> &B_t) {
    std::vector<bool> prediction;
    prediction.reserve(test.size());
    for (Sample const sample : test) {
        double left = 0;
        double right = 0;
        for(size_t i = 0; i < selectedFeatures.size(); ++i) {
            right += log(1/B_t[i]) * 0.5;
            left += log(1/B_t[i]) * sample.getPrediction(selectedFeatures[i]);
        }
        prediction.push_back(left >= right);
    }
    return prediction;
}


double Scorer::getScore(const std::vector<Sample> &test, const std::vector<Feature> &selectedFeatures,
                        const std::vector<double> &B_t) {
    std::vector<bool> prediction = Scorer().predict(test, selectedFeatures, B_t);
    size_t score = 0;
    for(size_t i = 0; i < test.size(); ++i) {
        score += (test[i].isMale() == prediction[i]);
    }
    return static_cast<double >(score) / test.size();
}


Scorer::Scorer() {

}






