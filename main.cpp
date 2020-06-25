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
= * This program is distributed in the hope that it will be useful,
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
int main() {
	std::string a, b;
	std::cout << "====================================\nMainInterface v1.6 by MaxSMoke\n====================================\n";
	again:
	std::cout << "Choose:\n1)Calculator\n2)KeyGen\n3)Converter\nе-exit\n====================================\n";
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
