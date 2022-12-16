#include "../../include/generator.h"

#include <iostream>
#include <iomanip>
#include "stdio.h"

#include "../../include/utils.h"

using namespace std;

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

void generate(const string &path, float (*function)(float)) {
    float start;
    input(&start, "Valor inicial (start):");

    float delta;
    input(&delta, "Taxa de variacao (delta):");

    int quantity;
    input(&quantity, "Quantidade de elementos (quantity):");

    print("\n" + path);

    writeFile(path, start, delta, quantity, function);
}
