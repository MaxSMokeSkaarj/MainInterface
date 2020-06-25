/*Its all function file from module
structure*/
#ifndef FUNC_H
#define FUNC_H
#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;
//calculator
void sum () {
double a,b,c;
cout << "Enter first number" << endl;
cout << "====================================" << endl;
cin >> a;
cout << "Enter second number" << endl;
cout << "====================================" << endl;
cin >> b;
c = a + b;
cout << "Summ: " << c << endl;
cout << "====================================" << endl;
}
void min () {
double a,b,c,d;
cout << "Enter first number" << endl;
cout << "====================================" << endl;
cin >> a;
cout << "Enter second number" << endl;
cout << "====================================" << endl;
cin >> b;
c = b - a;
d = a - b;
cout << "Second munus first: " << c << endl;
cout << "====================================" << endl;
cout << "First minus second: " << d << endl;
cout << "====================================" << endl;
}
void multiply () {
double a,b,c;
cout << "Enter first number" << endl;
cout << "====================================" << endl;
cin >> a;
cout << "Enter Second number" << endl;
cout << "====================================" << endl;
cin >> b;
c = a * b;
cout << "Multyply: " << c << endl;
cout << "====================================" << endl;
}
void divide () {
double a,b,c,d;
cout << "Enter first number" << endl;
cout << "====================================" << endl;
cin >> a;
cout << "Enter second number" << endl;
cout << "====================================" << endl;
cin >> b;
c = b / a;
d = a / b;
cout << "Second divide first: " << c << endl;
cout << "====================================" << endl;
cout << "First divide second: " << d << endl;
cout << "====================================" << endl;
}
void square () {
double a,b;
cout << "Enter number" << endl;
cout << "====================================" << endl;
cin >> a;
b = a * a;
cout << "Square: " << b << endl;
cout << "====================================" << endl;
}
void cube () {
double a,b;
cout << "Enter number:" << endl;
cout << "====================================" << endl;
cin >> a;
b = a * a * a;
cout << "Cube: " << b << endl;
cout << "====================================" << endl;
}
void root () {
double a,b;
cout << "Enter number" << endl;
cout << "====================================" << endl;
cin >> a;
b = sqrt(a);
cout << "Root: " << b << endl;
cout << "====================================" << endl;
}
void sin () {
double a,b;
cout << "Enter number" << endl;
cout << "====================================" << endl;
cin >> a;
b=sin(a);
cout << "Sinus: " << b << endl;
cout << "====================================" << endl;
}
void cos () {
double a,b;
cout << "Enter number" << endl;
cout << "====================================" << endl;
cin >> a;
b = cos(a);
cout << "Cosinus: " << b << endl;
cout << "====================================" << endl;
}
void tan () {
double a,b;
cout << "Enter number" << endl;
cout << "====================================" << endl;
cin >> a;
b = tan(a);
cout << "Tangens: " << a << endl;
cout << "====================================" << endl;
}
void log () {
double a,b;
cout << "Enter number" << endl;
cout << "====================================" << endl;
cin >> a;
b = log(a);
cout << "Logarifm: " << b << endl;
cout << "====================================" << endl;
}
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
