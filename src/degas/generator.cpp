#include "../../include/generator.h"

#include <iostream>
#include <iomanip>
#include "stdio.h"

#include "../../include/utils.h"

using namespace std;

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
