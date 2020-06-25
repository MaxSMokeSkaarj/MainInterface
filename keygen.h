#ifndef KEYGEN_H
#define KEYGEN_H
#include <iostream>
#include <cstdlib>
#include "modules.h"
void KeyGen () {
 std::string a,b;
 std::cout << "====================================\n";
 go:
 std::cout << "Choice difficulty: 4, 6 or 8\n";
 std::cout << "Type 'e' to exit\n";
 std::cout << "====================================\n";
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
  std::cout << "Exit to menu? 1)Yes, 2)No\n";
  std::cout << "====================================\n";
  getline(std::cin, b);
  if (b == "1") {
   goto end;
  } else if (b == "2"){
   goto go;
  } else {
   std::cout << "Error 301\n";
   std::cout << "====================================\n";
  }
  goto go;
 } else {
 std::cout << "Error 302\n";
 std::cout << "====================================\n";
 goto go;
 end:
 return;
 }
}
#endif
