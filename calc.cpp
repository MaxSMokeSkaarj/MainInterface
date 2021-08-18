#include <iostream>
#include <sstream>
#include <string>
#include <cmath>

int calc() {
  
  //preinit
  int stringProcessor(std::string choice[]);
  
  while (true) {
    std::cout << "MainInterface v1.6 by MaxSMoke\n";
    std::cout << "Input a mathematical example...\nType 'e' to exit\n";
    std::string choice, exitChoice;
    getline(std::cin, choice);
    if (choice == "E" || choice == "e") {
      std::cout << "Exit? y/N\n";
      getline(std::cin, exitChoice);
      if (exitChoice == "y" || exitChoice == "Y") {
        return 0;
      } else if (exitChoice == "N" || exitChoice == "n") {
        std::cout << "Aborting...\n";
      } else {
        std::cout << "Error 201\n";
      }
    };
    stringProcessor(choice);
  }
  return 0;
}