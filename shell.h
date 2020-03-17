//sh/bash
#ifndef SHELL_H
#define SHELL_H
#include <iostream>
#include <cstdlib>
using namespace std;
void shell(){
int a,b;
start:
cout << "Choose version" << endl;
cout << "====================================" << endl;
cout << "1)Sh" << endl;
cout << "2)BaSh" << endl;
cout << "0-exit" << endl;
cout << "====================================" << endl;
cin >> a;
if (a == 1) {
system("/bin/sh");
} else if (a == 2) {
system("/bin/bash");
} else if (a == 0) {
cout << "Exit to menu?" << endl;
cout << "====================================" << endl;
cout << "1)Yes" << endl;
cout << "2)No" << endl;
cout << "====================================" << endl;
cin >> b;
if (b == 1) {
goto end;
} else if (b == 2) {
goto start;
} else {
cout << "Error 401" << endl;
cout << "====================================" << endl;
cin >> b;
}
} else {
cout << "Error 402" << endl;
cout << "====================================" << endl;
cin >> b;
}
goto start;
end:
cin >> b;
}
#endif
