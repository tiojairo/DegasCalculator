#include <iostream>
#include "math.h"

#include "../include/utils.h"
#include "../include/generator.h"
#include "../include/integrator.h"
#include "../include/derivator.h"

enum state_enum {
    state_default = -1,
    state_exit = 0,
    state_generate = 1,
    state_integrate = 2,
    state_derivate = 3,
};

const string FILENAME = "data.txt";

float function(float x) {
    return pow(x, 2);
}

int main() {
    print("DEGAS CALCULATOR\n");

    while (true) {
        int state = (int)state_default;

        print("Digite:");
        print("(1) para gerar o arquivo");
        print("(2) para integrar");
        print("(3) para derivar");
        print("(0) para sair do programa");

        cin >> state;

        switch ((state_enum)state) {
            case state_default:
                break;
            case state_exit:
                return 0;
            case state_generate:
                print("");
                generate(FILENAME, function);
                print("");
                break;
            case state_integrate:
                print("");
                integrate(FILENAME);
                print("");
                break;
            case state_derivate:
                print("");
                derivate(FILENAME);
                print("");
        }
    }
}
