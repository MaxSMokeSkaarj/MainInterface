#include <iostream>
#include "functions.hpp"

int main() {
    while (true) {
        char choice,exitChoice;
        std::cout << "MainInteface v1.6 by MaxSMoke\n";
        std::cout << "Choose:\n1)Calculator\n2)KeyGen\n3)Converter\nType 'e' to exit\n";
        std::cin >> choice;
        switch (choice) {
            case '1':
                calc();
                break;
            case '2':
                KeyGen();
                break;
            case '3':
                conv();
                break;
            case 'e':
            case 'E':
                std::cout << "Exit? y/N\n";
                std::cin >> exitChoice;
                switch (exitChoice) {
                    case 'y':
                    case 'Y':
                        return 0;
                        break;
                    case 'n':
                    case 'N':
                    std::cout << "Aborting...\n";

                    break;
                default:
                    std::cout << "Error 101\n";
                break;
            }
        default:
            std::cout << "Error 102\n";
        break;
        }
    }
    return 0;
}