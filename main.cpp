//#define _GLIBCXX_DEBUG

#include <iostream>
#include <vector>
#include <ctime>
#include "Sample.h"
#include "Utils.h"
#include "SampleContainer.h"
#include "AdaBoost.h"
#include "Scorer.h"

int main() {

    std::vector<Sample> samples = Utils().readDataFromFile("data/20x20/samples00.vec");
    std::vector<Sample> train;
    std::vector<Sample> test;
    for (int i = 0; i < samples.size(); ++i) {
        if (i < samples.size() * 0.8) {
            train.push_back(samples[i]);
        } else {
            test.push_back(samples[i]);
        }
    }
    std::clock_t startInit = std::clock();
    AdaBoost adaBoost = AdaBoost(train, 0.01);
    std::cout << "init Time = "  << (std::clock() - startInit) / static_cast<double > (CLOCKS_PER_SEC) << "\n";
    std::clock_t startIterate = std::clock();
    adaBoost.run(100);
    std::cout << "score = " << Scorer().getScore(test, adaBoost.getSelectedFeatures(), adaBoost.getB_t()) << "\n";
    std::cout << "iter time = "  << (std::clock() - startIterate) / static_cast<double > (CLOCKS_PER_SEC) << "\n";
    return 0;
}