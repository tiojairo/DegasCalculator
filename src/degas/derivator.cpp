#include "../../include/derivator.h"

#include <iostream>

#include "../../include/utils.h"

using namespace std;

float derivateCentral(int position, double x[], double y[]) {
    return (y[position + 1] - y[position - 1]) / ((x[position + 1] - x[position - 1]));
}

void derivate(const string& path) {
    int option = 0;
    input(&option, "Digite:\n(0) Para criar um arquivo com a derivada de todos os pontos\n(1) Calcular a derivada em um unico ponto");

    int count = readFileCount(path);
    if (count == 0) {
        print("Arquivo nao encontrado.");
        return;
    }

    double x[count], y[count];
    readFile(path, x, y);

    int size = (int)(sizeof(x) / sizeof(x[0]));

    if (!option) {
        writeFile("derivates.txt", x[0], x[1] - x[0], size, x, y, derivateCentral);
        return;
    }

    float value = 0;
    input(&value, "Digite o valor que deseja derivar:");

    float derivate = derivateCentral(binarySearch(x, value, size), x, y);
    cout << derivate;
}