#ifndef CALC_H
#define CALC_H

#include <iostream>
#include <sstream>
#include <string>
#include <cmath>

void MathCore(std::string arr[]) {
 std::string a = arr[0];
 std::string b = arr[1];
 std::string c = arr[2];
 if(b == "+"){
  std::stringstream ssa(a);
  std::stringstream ssc(c);
  double da = 0.0;
  double dc = 0.0;
  ssa >> da;
  ssc >> dc;
  std::cout << a + " + " + c + " = " << da + dc << std::endl;
 } else if(b == "-"){
  std::stringstream ssa(a);
  std::stringstream ssc(c);
  double da = 0.0;
  double dc = 0.0;
  ssa >> da;
  ssc >> dc;
  std::cout << a + " - " + c + " = " << da - dc << std::endl;
 } else if(b == "*"){
  std::stringstream ssa(a);
  std::stringstream ssc(c);
  double da = 0.0;
  double dc = 0.0;
  ssa >> da;
  ssc >> dc;
  std::cout << a + " * " + c + " = " << da * dc << std::endl;
 } else if(b == "/"){
  std::stringstream ssa(a);
  std::stringstream ssc(c);
  double da = 0.0;
  double dc = 0.0;
  ssa >> da;
  ssc >> dc;
  std::cout << a + " / " + c + " = " << da / dc << std::endl;
 } else if(a == "sin"){
  std::stringstream ssb(b);
  double db = 0.0;
  ssb >> db;
  std::cout << "Sinus " + b + " = " << sin(db) << std::endl;
 } else if(a == "cos"){
  std::stringstream ssb(b);
  double db = 0.0;
  ssb >> db;
  std::cout << "Cosinus " + b + " = " << cos(db) << std::endl;
 } else if(a == "tan"){
  std::stringstream ssb(b);
  double db = 0.0;
  ssb >> db;
  std::cout << "Tangens " + b + " = " << tan(db) << std::endl;
 } else if(a == "log"){
  std::stringstream ssb(b);
  double db = 0.0;
  ssb >> db;
  std::cout << "Logarifm " + b + " = " << log(db) << std::endl;
 } else {
 std::cout << "Error 102\n";
 };
};

void stringProcessor(std::string line)
{
 std::string s = line;
 std::istringstream iss(s);
 int i = 0;
 std::string arr[4];
 do {
  std::string subs;
  iss >> subs;
  arr[i]= subs;
  i++;
  //std:: cout << "Substring: " << arr[i] << std::endl;
 } while (iss);
 MathCore(arr);
};

void calc() {
 std::cout << "====================================\n";
 std::cout << "MainInterface v1.6 by KillSZ\n";
 std::cout << "====================================\n";
 back:
 std::cout << "Input a mathematical example...\nInput 'e' to exit\n";
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
   std::cout << "Error 101\n";
  }
 };
 stringProcessor(in);
 goto back;
 exit:
 return;
}
#endif
