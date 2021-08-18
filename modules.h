/*Its all function file from module
structure*/
#ifndef FUNC_H
#define FUNC_H
#include <iostream>
#include <cmath>
#include <cstdlib>

//calculator

void MathCore(std::string arr[]) {
  std::string a = arr[0];
  std::string b = arr[1];
  std::string c = arr[2];
  if(b == "+") {
    std::stringstream ssa(a);
    std::stringstream ssc(c);
    double da = 0.0;
    double dc = 0.0;
    ssa >> da;
    ssc >> dc;
    std::cout << a + " + " + c + " = " << da + dc << std::endl;
  } else if(b == "-") {
    std::stringstream ssa(a);
    std::stringstream ssc(c);
    double da = 0.0;
    double dc = 0.0;
    ssa >> da;
    ssc >> dc;
    std::cout << a + " - " + c + " = " << da - dc << std::endl;
  } else if(b == "*") {
    std::stringstream ssa(a);
    std::stringstream ssc(c);
    double da = 0.0;
    double dc = 0.0;
    ssa >> da;
    ssc >> dc;
    std::cout << a + " * " + c + " = " << da * dc << std::endl;
  } else if(b == "/") {
    std::stringstream ssa(a);
    std::stringstream ssc(c);
    double da = 0.0;
    double dc = 0.0;
    ssa >> da;
    ssc >> dc;
    std::cout << a + " / " + c + " = " << da / dc << std::endl;
  } else if(a == "sin") {
    std::stringstream ssb(b);
    double db = 0.0;
    ssb >> db;
    std::cout << "Sinus " + b + " = " << sin(db) << std::endl;
  } else if(a == "cos") {
    std::stringstream ssb(b);
    double db = 0.0;
    ssb >> db;
    std::cout << "Cosinus " + b + " = " << cos(db) << std::endl;
  } else if(a == "tan") {
    std::stringstream ssb(b);
    double db = 0.0;
    ssb >> db;
    std::cout << "Tangent " + b + " = " << tan(db) << std::endl;
  } else if(a == "log") {
    std::stringstream ssb(b);
    double db = 0.0;
    ssb >> db;
    std::cout << "Logarithm " + b + " = " << log(db) << std::endl;
  } else if (a == "ctg") {
    std::stringstream ssb(b);
    double db = 0.0;
    ssb >> db;
    std::cout << "Cotangent " + b + " = " << 1/tan(db) << std::endl;
  } else if (a == "sqrt" || a == "√") {
    std::stringstream ssb(b);
    double db = 0.0;
    ssb >> db;
    std::cout << "Square root " + b + " = " << sqrt(db) << std::endl;
  } else if (b == "^" || b == "in") {
    std::stringstream ssa(a);
    std::stringstream ssc(c);
    double da = 0.0;
    double dc = 0.0;
    ssa >> da;
    ssc >> dc;
    std::cout << a + " ^ " + c + " = " << pow(da, dc) << std::endl;
  } else if (a == "cbrt" || a == "√^3") {
    std::stringstream ssb(b);
    double db = 0.0;
    ssb >> db;
    std::cout << "Cube root " + b + " = " << cbrt(db) << std::endl;
  } else if ((a == "|" && c == "|") || a == "abs") {
    std::stringstream ssb(b);
    double db = 0.0;
    ssb >> db;
    std::cout << "Module " + b + " = " << abs(db) << std::endl;
  } else if (a == "log10") {
    std::stringstream ssb(b);
    double db = 0.0;
    ssb >> db;
    std::cout << "Decimal logarithm " + b + " = " << log10(db) << std::endl;
  } else {
    std::cout << "Error 202\n";
  };
};

void stringProcessor(std::string line) {
  std::string s = line;
  std::istringstream iss(s);
  int i = 0;
  std::string arr[4];
  do {
    std::string subs;
    iss >> subs;
    arr[i] = subs;
    i++;
  } while (iss);
  MathCore(arr);
};

//keygen

void four () {
  std::cout << "4-numberic code: " << 1000 + rand() % 1000 << std::endl;
}
void six () {
  std::cout << "6-numberic code: " << 100000 + rand() % 100000 << std::endl;
}
void eight () {
  std::cout << "8-numberic code: " << 10000000 + rand() % 10000000 << std::endl;
}

//converter

#endif