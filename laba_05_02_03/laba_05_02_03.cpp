#include <iostream>
#include "Exception.h"
#include "Double_List.h"
#include "stringStream.h"
#include "Student.h"
#include "University.h"
using namespace std;

void taskOne(University univer);
void taskTwo();
void menu();



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

void taskOne(University univer)
{
	int menu;
	while (true)
	{
		cout << "\tStandard stream task" << endl
			<< "  1. Add" << endl
			<< "  2. Edit" << endl
			<< "  3. Remove" << endl
			<< "  4. Sort" << endl
			<< "  5. Print data" << endl
			<< "  0. Back" << endl << "-> ";
		cin >> menu;

		while (menu < 0 || menu > 5 || cin.fail()) {
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "  Non-existent menu case. Re-enter\n-> ";
			cin >> menu;
		}
		switch (menu)
		{
		case 1: { ++univer; break; }
		case 2: { univer.edit(); break; }
		case 3: { --univer; break; }
		case 4: { univer.sort(); break; }
		case 5: { univer.print(); break; }
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
	University univer;
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
		case 1: { taskOne(univer); break; }
		case 2: { taskTwo(); break; }
		case 0: { return; }
		}
	}
}