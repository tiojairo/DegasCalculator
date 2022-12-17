#include "../../include/utils.h"

#include <iostream>
#include <iomanip>

using namespace std;

void print(const string text) {
    cout << text << endl;
}

void input(int *i, string text) {
    if (!text.empty())
        print(text);

    cin >> *i;
}

void input(float *f, string text) {
    if (!text.empty())
        print(text);

    cin >> *f;
}

int binarySearch(const double array[], float target, int size) {
    int middle;
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        middle = (left + right) / 2;

        double found = array[middle];

        // TODO: Change to difference comparison, for more precision or if requested by Degas.
        // found - target <= margin
        if (target == found || left == right)
            return middle;

        if (target > found)
            left = middle + 1;
        else
            right = middle - 1;
    }

    return -1;
}

float areaTrapeze(float B, float b, float h) {
    return (B + b) * h / 2;
}

int fat(int x) {
    if (x == 0)
        return 1;

    return x * fat(x - 1);
}

int readFileCount(const string& path) {
    FILE *file;
    file = fopen(path.c_str(), "r");

    if (!file)
        return 0;

    int count = 0;
    fscanf(file, "%d", &count);

    fclose(file);

    return count;
}

void readFile(const string &path, double *xArray, double *yArray) {
    FILE *file;
    file = fopen(path.c_str(), "r");

    if (!file)
        return;

    int count = 0;
    fscanf(file, "%d", &count);

    print("Elementos encontrados: ");

    double localX[count], localY[count];
    for (int i = 0; i < count; i++) {
        double tempX, tempY;
        fscanf(file, "%lf %lf\n", &tempX, &tempY);

        localX[i] = tempX;
        localY[i] = tempY;

        cout << fixed << setprecision(6) << "x=" << tempX << " y=" << tempY << endl;
    }

    fclose(file);

    cout << "Total de elementos: " << count << endl;

    for (int i = 0; i < count; i++) {
        xArray[i] = localX[i];
        yArray[i] = localY[i];
    }
}

void writeFile(const string &path, float start, float delta, int quantity, float (*function)(float)) {
    FILE *file;
    file = fopen(path.c_str(), "w");

    int count = quantity + 1;
    fprintf(file, "%d\n", count);

    cout << "Elementos salvos: " << endl;

    int position = 0;
    double x = start;
    while (position <= quantity) {
        double tempX = x, tempY = (double)function((float)x);
        fprintf(file, "%.6f %.6f\n", tempX, tempY);

        x += delta;
        position++;

        cout << fixed << setprecision(6) << "x=" << tempX << " y=" << tempY << endl;
    }

    fclose(file);

    cout << "Total de elementos: " << count << endl;
}

void writeFile(const string &path, float start, float delta, int quantity, double xArray[], double yArray[], float (*function)(int, double[], double[])) {
    FILE *file;
    file = fopen(path.c_str(), "w");

    int count = quantity + 1;
    fprintf(file, "%d\n", count);

    cout << "Elementos salvos: " << endl;

    int position = 0;
    double x = start;
    while (position <= quantity) {
        double tempX = x, tempY = (double)function(position, xArray, yArray);
        fprintf(file, "%.6f %.6f\n", tempX, tempY);

        x += delta;
        position++;

        cout << fixed << setprecision(6) << "x=" << tempX << " y=" << tempY << endl;
    }

    fclose(file);

    cout << "Total de elementos: " << count << endl;
}

void writeFile(const string &path, float start, float delta, int quantity, double xArray[], double yArray[], float (*function)(float, float, float)) {
    FILE *file;
    file = fopen(path.c_str(), "w");

    int count = quantity + 1;
    fprintf(file, "%d\n", count);

    cout << "Elementos salvos: " << endl;

    int position = 0;
    double x = start;
    while (position <= quantity) {
        int p1 = position + 1;
        int p2 = position + 2;
        int size = quantity + 1;

        if (p2 > size)
            break;

        double tempX = x, tempY = (double)function(yArray[p1], yArray[position], xArray[p2] - xArray[p1]);
        fprintf(file, "%.6f %.6f\n", tempX, tempY);

        x += delta;
        position++;

        cout << fixed << setprecision(6) << "x=" << tempX << " y=" << tempY << endl;
    }

    fclose(file);

    cout << "Total de elementos: " << count << endl;
}