/*
   KeyGen by MaxSMoke/KillSZ v1.3
*/
#ifndef KEYGEN_H
#define KEYGEN_H
#include <iostream>
#include <cstdlib>
#include "modules.h"
using namespace std;
void KeyGen () {
int a,b;
cout << "====================================" << endl;
go:
cout << "Choice difficulty: 4, 6 or 8" << endl;
cout << "0-Exit" << endl;
cout << "====================================" << endl;
cin >> a;
if (a == 4) {
four ();
goto go;
} else if (a == 6) {
six();
goto go;
} else if (a == 8) {
eight();
goto go;
} else if (a == 0) {
cout << "Exit to menu? 1)Yes, 2)No" << endl;
cout << "====================================" << endl;
cin >> b;
if (b == 1) {						
goto end;
} else if (b == 2){
goto go;
} else {
cout << "Error 301" << endl;
cout << "====================================" << endl;
cin >> b;
}
goto go;
} else {
cout << "Error 302" << endl;
cout << "====================================" << endl;
cin >> b;
goto go;
end:
cin >> b;
}
}
#endif
