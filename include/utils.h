#ifndef DEGASCALCULATOR_UTILS_H
#define DEGASCALCULATOR_UTILS_H

#include <iostream>

using namespace std;

void print(string text);

void input(int *i, string text = "");

void input(float *f, string text = "");

int binarySearch(const double array[], float target, int size);

float areaTrapeze(float B, float b, float h);

#endif //DEGASCALCULATOR_UTILS_H
