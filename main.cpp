/*
 * main.cpp
 * 
 * Copyright 2019 KillSZ <aser2522002@gmail.com>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */
#include <iostream>
#include <cstdlib>
#include <cstdlib>
#include "calc.h"
#include "keygen.h"
#include "shell.h"
using namespace std;
int main() {
	int a, b;
	cout << "====================================\nMain Interfase v1.4 by KillSZ\n====================================\n";
	again:
	cout << "Choose:\n1)Calculator\n2)KeyGen\n3)SH/BaSh\n4)Converter\n5)OSMOS Project\n0-exit\n====================================\n";
	cin >> a;
	if (a == 1){
		calc ();
	} else if (a == 2) {
		KeyGen();
	} else if (a == 3) {
		shell();
	} else if (a == 4) {
		system("clear");
		cout << "Coming Soon!\n====================================\n";
	} else if (a == 5) {
		system("clear");
		cout << "Coming Soon!\n====================================\n";
	} else if (a == 744327) {
		//support();
	} else if (a == 0) {
		system("clear");
		cout << "Exit? 1)Yes, 2)No\n====================================\n";
		cin >> b;
		if (b == 1) {
			goto end;
		} else if (b == 2) {
			goto again;
		} else {
			cout << "Error 101" << endl;
			cout << "====================================" << endl;;
			cin >> b;
		}
	} else {
		cout << "Error 102\n====================================\n";
		cin >> b;
	}
	goto again;
	end:
	return 0;
}
