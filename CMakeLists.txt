cmake_minimum_required(VERSION 3.21)
project(bigReal)

set(CMAKE_CXX_STANDARD 14)

add_executable(bigReal BigDecimalIntClass.cpp BigDecimalIntClass.h BigReal.cpp BigReal.h main.cpp)
