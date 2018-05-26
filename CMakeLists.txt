cmake_minimum_required(VERSION 3.6)
project(Convex_Hulls)

set(CMAKE_CXX_STANDARD 14)

set(CREATE_DATASET_SOURCE_FILES create_dataset.cpp Point.cpp Point.h util.cpp util.h DatasetGenerator.cpp DatasetGenerator.h Randomizer.cpp Randomizer.h)
add_executable(create_dataset ${CREATE_DATASET_SOURCE_FILES})

set(EVAL_GRAHAM_SOURCE_FILES evalGrahamScan.cpp GrahamScan.cpp GrahamScan.h Point.cpp Point.h Timer.cpp Timer.h util.cpp util.h)
add_executable(eval_graham_scan ${EVAL_GRAHAM_SOURCE_FILES})

set(EVAL_AHALL_SOURCE_FILES evalAHall.cpp AHall.cpp AHall.h Point.cpp Point.h Timer.cpp Timer.h util.cpp util.h)
add_executable(eval_ahall ${EVAL_AHALL_SOURCE_FILES})

set(EVAL_JARVIS_SOURCE_FILES evalJarvis.cpp Jarvis.cpp Jarvis.h Point.cpp Point.h Timer.cpp Timer.h util.cpp util.h)
add_executable(eval_jarvis ${EVAL_JARVIS_SOURCE_FILES})

set(EVAL_MONOTONE_CHAIN_SOURCE_FILES evalMonotoneChain.cpp MonotoneChain.cpp MonotoneChain.h Point.cpp Point.h Timer.cpp Timer.h util.cpp util.h)
add_executable(eval_monotone_chain ${EVAL_MONOTONE_CHAIN_SOURCE_FILES})