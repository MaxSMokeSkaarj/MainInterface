#ifndef CALC_H
#define CALC_H

#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
#include "modules.h"

void calc() {
  std::cout << "MainInterface v1.6 by KillSZ\n";
  back:
  std::cout << "Input a mathematical example...\nType 'e' to exit\n";
  std::string in;
  getline(std::cin, in);
  if(in == "E" || in == "e") {
    std::cout << "Exit? y/N\n";
    std::string chc;
    getline(std::cin, chc);
    if (chc == "y" || chc == "Y") {
      goto exit;
    } else if (chc == "N" || chc == "n") {
      std::cout << "Aborting...\n";
    } else {
      std::cout << "Error 201\n";
    }
  };

  stringProcessor(in);
  goto back;
  exit:
  return;
}
#endif