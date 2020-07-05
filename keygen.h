#ifndef KEYGEN_H
#define KEYGEN_H
#include <iostream>
#include <cstdlib>
#include "modules.h"
void KeyGen () {
    std::string a,
    b;
    go:
    std::cout << "Choice difficulty: 4, 6 or 8\n";
    std::cout << "Type 'e' to exit\n";
    getline(std::cin, a);
    if (a == "4") {
        four ();
        goto go;
    } else if (a == "6") {
        six();
        goto go;
    } else if (a == "8") {
        eight();
        goto go;
    } else if (a == "e" || a == "E") {
        std::cout << "Exit to menu? y/N\n";
        getline(std::cin, b);
        if (b == "y" || b == "Y") {
            goto end;
        } else if (b == "n" || b == "N") {
            goto go;
        } else {
            std::cout << "Error 301\n";
        }
        goto go;
    } else {
        std::cout << "Error 302\n";
        goto go;
        end:
        return;
    }
}
#endif