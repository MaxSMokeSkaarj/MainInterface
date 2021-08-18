#include <iostream>
#include <cstdlib>
#include <cstdlib>
#include "calc.h"
#include "keygen.h"
#include "conv.h"

int main() {
    std::string a,
    b;
    std::cout << "MainInterface v1.6 by MaxSMoke\n";
    again:
    std::cout << "Choose:\n1)Calculator\n2)KeyGen\n3)Converter\nType 'e' to exit\n";
    getline(std::cin, a);
    if (a == "1") {
        calc ();
    } else if (a == "2") {
        KeyGen();
    } else if (a == "3") {
        conv();
    } else if (a == "E" || a == "e") {
        std::cout << "Exit? y/N\n";
        getline(std::cin, b);
        if (b == "Y" || b == "y") {
            goto end;
        } else if (b == "n" || b == "N") {
            goto again;
        } else {
            std::cout << "Error 101\n";
        }
    } else {
        std::cout << "Error 102\n";
    }
    goto again;
    end:
    return 0;
}
