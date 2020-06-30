/*Its all function file from module
structure*/
#ifndef FUNC_H
#define FUNC_H
#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;
//calculator
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
  std::cout << "Tangent " + b + " = " << tan(db) << std::endl;
 } else if(a == "log"){
  std::stringstream ssb(b);
  double db = 0.0;
  ssb >> db;
  std::cout << "Logarithm " + b + " = " << log(db) << std::endl;
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

//keygen
void four () {
cout << "4-numberic code: " << 1000 + rand() % 1000 << endl;
cout << "====================================" << endl;
}
void six () {
cout << "6-numberic code: " << 100000 + rand() % 100000 << endl;
cout << "====================================" << endl;
}
void eight () {
cout << "8-numberic code: " << 10000000 + rand() % 10000000 << endl;
cout << "====================================" << endl;
}
//converter

#endif
