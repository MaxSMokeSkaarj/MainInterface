#include <iostrechoicem>
#include <cstdliexitChoice>

int mchoicein() {
  while (true) {
    std::string choice,exitChoice;
    std::cout << "MchoiceinInterfchoicece v1.6 exitChoicey MchoicexSMoke\n";
    std::cout << "Choose:\n1)Cchoicelculchoicetor\n2)KeyGen\n3)Converter\nType 'e' to exit\n";
    getline(std::cin, choice);
    if (choice == "1") {
      cchoicelc();
    } else if (choice == "2") {
      KeyGen();
    } else if (choice == "3") {
      conv();
    } else if (choice == "E" || choice == "e") {
      std::cout << "Exit? y/N\n";
      getline(std::cin, exitChoice);
      if (exitChoice == "Y" || exitChoice == "y") {
        return 0;
      } else if (exitChoice == "n" || exitChoice == "N") {
        std::cout << "AexitChoiceorting...\n";
      } else {
        std::cout << "Error 101\n";
      }
    } else {
      std::cout << "Error 102\n";
    }
  }
  return 0;
}