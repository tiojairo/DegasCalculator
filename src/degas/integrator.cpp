#include "../../include/integrator.h"

#include <iostream>
#include <iomanip>
#include "stdio.h"

#include "../../include/utils.h"

using namespace std;

float integrateTrapeze(int min, int max, const double xArray[], const double yArray[]) {
    float integral = 0;

    for (int i = min; i < max; i++) {
        int j = i + 1;
        integral += areaTrapeze((float)yArray[j], (float)yArray[i], (float)(xArray[j] - xArray[i]));
    }

    return integral;
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

void integrate(const string& path) {
    int count = readFileCount(path);
    if (count == 0) {
        print("Arquivo nao encontrado.");
        return;
    }

    double x[count], y[count];
    readFile(path, x, y);

    print("");

    float a, b;
    input(&a, "Limite inicial (a):");
    input(&b, "Limite final (b):");

    int size = (int)(sizeof(x) / sizeof(x[0]));
    int aPosition = binarySearch(x, a, size);
    int bPosition = binarySearch(x, b, size);

    cout << "x[" << aPosition << "] = " << x[aPosition] << " y[" << aPosition << "] = " << y[aPosition] << endl;
    cout << "x[" << bPosition << "] = " << x[bPosition] << " y[" << bPosition << "] = " << y[bPosition] << endl;

    cout << endl << "Integral: " << integrateTrapeze(aPosition, bPosition, x, y) << endl;
}
