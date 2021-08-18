#include <iostream>
#include <sstream>
#include <string>
#include <cmath>

int calc() {
  while (true) {
    std::cout << "MainInterface v1.6 by KillSZ\n";
    std::cout << "Input a mathematical example...\nType 'e' to exit\n";
    std::string in;
    getline(std::cin, in);
    if(in == "E" || in == "e") {
      std::cout << "Exit? y/N\n";
      std::string chc;
      getline(std::cin, chc);
      if (chc == "y" || chc == "Y") {
        return 0;
      } else if (chc == "N" || chc == "n") {
        std::cout << "Aborting...\n";
      } else {
        std::cout << "Error 201\n";
      }
    };

    stringProcessor(in);
  }
  return 0;
}