cmake_minimum_required(VERSION 3.23)
project(lab5)

set(CMAKE_CXX_STANDARD 14)

add_executable(lab5 main.cpp ParallelClassic.cpp My_Polynomial.cpp Task.cpp ParallelKaratsuba.cpp SequentialKaratsuba.cpp PolynomialUtils.cpp SequentialClassic.cpp)
