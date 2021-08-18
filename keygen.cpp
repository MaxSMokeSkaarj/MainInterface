#include <iostream>
#include <cstdlib>

int KeyGen() {

  //pre
  four();
  six();
  eight();

  while (true) {
    std::string choice, exitChoice;
    std::cout << "Choice difficulty: 4, 6 or 8\n";
    std::cout << "Type 'e' to exit\n";
    getline(std::cin, choice);
    if (choice == "4") {
      four ();
    } else if (choice == "6") {
      six();
    } else if (choice == "8") {
      eight();
    } else if (choice == "e" || choice == "E") {
      std::cout << "Exit to menu? y/N\n";
      getline(std::cin, exitChoice);
      if (exitChoice == "y" || exitChoice == "Y") {
        return 0;
      } else if (exitChoice == "n" || exitChoice == "N") {
        std::cout << "Aborting...\n";
      } else {
        std::cout << "Error 301\n";
      }
    } else {
      std::cout << "Error 302\n";
    }
  }
}