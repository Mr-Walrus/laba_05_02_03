/*
С использованием файловых и строковых потоков написать программу,
которая считывает текст из файла и выводит на экран только строки,
содержащие двузначные числа.
*/
#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "Exception.h"
using namespace std;

void findTwoDigit() {
	bool firstDigit, secondDigit;
	string s;

	ifstream fin;
	fin.open("input.txt", ios::in);

	stringstream sin;
	sin << fin.rdbuf();

	while (!sin.eof()) {
		firstDigit = secondDigit = false;
		getline(sin, s);
		for (char& c : s)
		{
			if (c >= '0' && c <= '9')
			{
				if (!firstDigit) firstDigit = true;
				else if (!secondDigit) secondDigit = true;
				else firstDigit = secondDigit = false;
			}
			else if (firstDigit && secondDigit)
				break;
			else firstDigit = secondDigit = false;
		}
		if (firstDigit && secondDigit) cout << s << endl;
	}
}