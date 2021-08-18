#include <iostream>
#include <cstdlib>

int KeyGen() {
  std::string a,
  b;
  while (true) {
    std::cout << "Choice difficulty: 4, 6 or 8\n";
    std::cout << "Type 'e' to exit\n";
    getline(std::cin, a);
    if (a == "4") {
      four ();
    } else if (a == "6") {
      six();
    } else if (a == "8") {
      eight();
    } else if (a == "e" || a == "E") {
      std::cout << "Exit to menu? y/N\n";
      getline(std::cin, b);
      if (b == "y" || b == "Y") {
        return 0;
      } else if (b == "n" || b == "N") {
        std::cout << "Aborting...\n";
      } else {
        std::cout << "Error 301\n";
      }
    } else {
      std::cout << "Error 302\n";
    }
  }
}
