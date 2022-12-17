#ifndef DEGASCALCULATOR_UTILS_H
#define DEGASCALCULATOR_UTILS_H

#include <iostream>

using namespace std;

void print(string text);

void input(int *i, string text = "");

void input(float *f, string text = "");

int binarySearch(const double array[], float target, int size);

float areaTrapeze(float B, float b, float h);

int fat(int x);

int readFileCount(const string& path);

void readFile(const string &path, double *xArray, double *yArray);

void writeFile(const string &path, float start, float delta, int quantity, float (*function)(float));

void writeFile(const string &path, float start, float delta, int quantity, double xArray[], double yArray[], float (*function)(int, double[], double[]));

void writeFile(const string &path, float start, float delta, int quantity, double xArray[], double yArray[], float (*function)(float, float, float));

#endif //DEGASCALCULATOR_UTILS_H
