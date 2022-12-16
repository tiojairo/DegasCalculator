#include <iostream>
#include "math.h"

#include "../include/utils.h"
#include "../include/generator.h"
#include "../include/integrator.h"

enum state_enum {
    state_default = -1,
    state_exit = 0,
    state_generate = 1,
    state_integrate = 2,
};

float function(float x) {
    return tan(x);
}

int main() {
    print("DEGAS CALCULATOR\n");

    while (true) {
        int state = (int)state_default;

        print("Digite:");
        print("(1) para gerar o arquivo");
        print("(2) para integrar a partir do arquivo");
        print("(0) para sair do programa");

        cin >> state;

        switch ((state_enum)state) {
            case state_default:
                break;
            case state_exit:
                return 0;
            case state_generate:
                print("");
                generate("tan.txt", function);
                print("");
                break;
            case state_integrate:
                print("");
                integrate("tan.txt");
                print("");
                break;
        }
    }
}
