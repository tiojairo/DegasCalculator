cmake_minimum_required(VERSION 3.24)
project(DegasCalculator)

set(CMAKE_CXX_STANDARD 17)

add_executable(DegasCalculator src/main.cpp src/degas/generator.cpp include/generator.h src/degas/integrator.cpp include/integrator.h src/degas/utils.cpp include/utils.h src/degas/derivator.cpp include/derivator.h)
