//
// Created by kagudkov on 20.04.16.
//

#include <cmath>
#include <ctime>
#include <omp.h>
#include "Scorer.h"
#include "Utils.h"


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
    std::vector<bool> prediction = predict(test, selectedFeatures, B_t);
    size_t score = 0;
    for (size_t i = 0; i < test.size(); ++i) {
        score += (test[i].isMale() == prediction[i]);
    }
    return static_cast<double >(score) / test.size();
}


Scorer::Scorer() {

}

double Scorer::getScoreKFold(const std::string &pictureSize, size_t numberOfIteration, double percentOfTestedFeature,
                             size_t seed, size_t numberOfFolds) {
    std::string inputDataFilename = "data/" + pictureSize + "/samples00.vec";
    std::vector<Sample> samples = readDataFromFile(inputDataFilename);
    std::vector<std::vector<Sample>> tests;
    std::vector<AdaBoost> adaBoosts;
    for (size_t k = 0; k < numberOfFolds; ++k) {
        std::vector<Sample> test;
        std::vector<Sample> train;
        addKFold(k, test, train, samples, numberOfFolds);
        tests.push_back(std::move(test));
        adaBoosts.emplace_back(SampleContainer(train), percentOfTestedFeature / 100, seed);
    }
    std::fstream fsOutput;
    fsOutput.open("result" + pictureSize + ".txt", std::fstream::out | std::fstream::app);
    double startIterate = omp_get_wtime();
    double score = 0;
    for (size_t i = 0; i < numberOfIteration; ++i) {
        score = 0;
        for (size_t i = 0; i < adaBoosts.size(); ++i) {
            adaBoosts[i].run(1);
            score += getScore(tests[i], adaBoosts[i].getSelectedFeatures(), adaBoosts[i].getB_t()) / adaBoosts.size();
        }
        fsOutput << i << " " << score << " ";
        fsOutput << omp_get_wtime() - startIterate << "\n";
        fsOutput.flush();
    }

    for (AdaBoost &adaBoost : adaBoosts) {
        fsOutput << "selectedFeatures\n\n";
        for (size_t i = 0; i < adaBoost.getSelectedFeatures().size(); ++i) {
            adaBoost.getSelectedFeatures()[i].print(fsOutput);
            fsOutput << "Bt = " << adaBoost.getB_t()[i] << "\n";
        }
    }
    fsOutput.close();
    return score;
}

void Scorer::addKFold(size_t indexOfFold, std::vector<Sample> &test, std::vector<Sample> &train,
                      std::vector<Sample> &samples, size_t numberOfFolds) {
    for (size_t i = 0; i < samples.size(); ++i) {
        if (i >= static_cast<double > (indexOfFold) / numberOfFolds * samples.size() &&
            i < static_cast<double > (indexOfFold + 1) / numberOfFolds * samples.size()) {
            test.push_back(samples[i]);
        } else {
            train.push_back(samples[i]);
        }
    }
}












