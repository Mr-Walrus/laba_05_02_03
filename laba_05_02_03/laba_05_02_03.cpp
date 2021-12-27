#include <iostream>
#include "stringStream.h"
using namespace std;



void taskOne()
{
	int menu;
	while (true)
	{
		cout << "\tStandard stream task" << endl
			<< "  1. Standard stream task" << endl
			<< "  2. String   stream task" << endl
			<< "  0. Back" << endl
			<< "-> ";
		cin >> menu;

		while (menu < 0 || menu > 2 || cin.fail()) {
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "Non-existent menu case. Re-enter" << endl;
			cin >> menu;
		}
		switch (menu)
		{
		case 1: {  break; }
		case 2: {  break; }
		case 0: { return; }
		}
	}
}

void taskTwo()
{
	cout << "\tString stream task:" << endl << endl;
	findTwoDigit();
	cout << endl;
}

void menu()
{
	int menu;
	while (true)
	{
		cout << "\tMain menu" << endl
			<< "1. Standard stream task" << endl
			<< "2. String   stream task" << endl
			<< "0. Exit" << endl
			<< "-> ";
		cin >> menu;

		while (menu < 0 || menu > 2 || cin.fail()) {
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "Non-existent menu case. Re-enter" << endl;
			cin >> menu;
		}
		switch (menu)
		{
		case 1: { taskOne(); break; }
		case 2: { taskTwo(); break; }
		case 0: { return; }
		}
	}
}

int main()
{
	try { 
		menu(); 
	}
	catch (Exception& exception) {
		cout << "Exception occurred : " << exception.what() << endl;
	}
	catch (exception& exception) {
		cout << "Some other exception occurred : " << exception.what() << endl;
	}
}