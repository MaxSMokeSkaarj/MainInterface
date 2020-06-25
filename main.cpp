#include <iostream>
#include <cstdlib>
#include <cstdlib>
#include "calc.h"
#include "keygen.h"
int main() {
	std::string a, b;
	std::cout << "====================================\nMainInterface v1.6 by MaxSMoke\n====================================\n";
	again:
	std::cout << "Choose:\n1)Calculator\n2)KeyGen\n3)Converter\nType 'e' to exit\n====================================\n";
	getline(std::cin, a);
	if (a == "1") {
		calc ();
	} else if (a == "2") {
		KeyGen();
	} else if (a == "3") {
		std::cout << "Not work...\n";
		//shell();
	} else if (a == "E" || a == "e") {
		cout << "Exit? y/N\n====================================\n";
		cin >> b;
		if (b == "Y" || b == "y") {
			goto end;
		} else if (b == "n" || b == "N") {
			goto again;
		} else {
			std::cout << "Error 101\n";
			std::cout << "====================================\n";
		}
	} else {
		std::cout << "Error 102\n====================================\n";
	}
	goto again;
	end:
	return 0;
}
