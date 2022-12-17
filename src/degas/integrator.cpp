#include "../../include/integrator.h"

#include <iostream>
#include <iomanip>
#include "stdio.h"

#include "../../include/utils.h"

#include "../../include/derivator.h"

using namespace std;

float integrateTrapeze(int min, int max, const double xArray[], const double yArray[]) {
    float integral = 0;

    for (int i = min; i < max; i++) {
        int j = i + 1;
        integral += areaTrapeze((float)yArray[j], (float)yArray[i], (float)(xArray[j] - xArray[i]));
    }

    return integral;
}

void integrate(const string& path) {
    int option = 0;
    input(&option, "Digite:\n(0) Para criar um arquivo com a area de todos os pontos\n(1) Calcular a area em um intervalo");

    int count = readFileCount(path);
    if (count == 0) {
        print("Arquivo nao encontrado.");
        return;
    }

    double x[count], y[count];
    readFile(path, x, y);

    int size = (int)(sizeof(x) / sizeof(x[0]));

    if (!option) {
        writeFile("areas.txt", x[0], x[1] - x[0], size, x, y, areaTrapeze);
        return;
    }

    print("");

    float a, b;
    input(&a, "Limite inicial (a):");
    input(&b, "Limite final (b):");

    int aPosition = binarySearch(x, a, size);
    int bPosition = binarySearch(x, b, size);

    cout << "x[" << aPosition << "] = " << x[aPosition] << " y[" << aPosition << "] = " << y[aPosition] << endl;
    cout << "x[" << bPosition << "] = " << x[bPosition] << " y[" << bPosition << "] = " << y[bPosition] << endl;

    cout << endl << "Integral: " << integrateTrapeze(aPosition, bPosition, x, y) << endl;
}
