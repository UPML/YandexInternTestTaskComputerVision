cmake_minimum_required(VERSION 3.5)
project(YandexInternTestTaskComputerVision)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Picture.cpp Picture.h Utils.cpp Utils.h Sample.cpp Sample.h MessageException.cpp MessageException.h AdaBoost.cpp AdaBoost.h SampleContainer.cpp SampleContainer.h Feature.cpp Feature.h Scorer.cpp Scorer.h)
add_executable(YandexInternTestTaskComputerVision ${SOURCE_FILES})