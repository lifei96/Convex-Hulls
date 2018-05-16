cmake_minimum_required(VERSION 3.6)
project(Convex_Hulls)

set(CMAKE_CXX_STANDARD 14)

set(CREATE_DATASET_SOURCE_FILES create_dataset.cpp Point.cpp Point.h util.cpp util.h DatasetGenerator.cpp DatasetGenerator.h Randomizer.cpp Randomizer.h)
add_executable(create_dataset ${CREATE_DATASET_SOURCE_FILES})
