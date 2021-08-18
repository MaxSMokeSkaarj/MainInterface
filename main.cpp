#include <iostream>
#include <cstdlib>

int main() {
  while(true) {
    std::string a,b;
    std::cout << "MainInterface v1.6 by MaxSMoke\n";
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
        return 0;
      } else if (b == "n" || b == "N") {
        //nothing to do
      } else {
        std::cout << "Error 101\n";
      }
    } else {
      std::cout << "Error 102\n";
    }
  }
  return 0;
}