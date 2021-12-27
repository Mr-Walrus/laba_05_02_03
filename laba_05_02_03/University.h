#pragma once
#include <iostream>
#include "Exception.h"
#include "Double_List.h"
#include "Student.h"

class University
{
private:
	List<Student> students;
	template<class F>
	void menu(string, F foo1...);
	void setSTName();
	void setSTAverageMark();
	void setSTGrupNum();
public:

	University();
	University(List<Student> students);
	University(const University& other);
	~University();

	University& operator++();//����������
	void edit();//��������������
	University& operator--();//��������

	void addStudent();//����������
	void addSubject();//����������
	void editStudent();//��������������
	void editSubject(size_t);//��������������
	void delStudent();//��������
	void delSubject();//��������

	void print();//������

	void sort();

};

template<class F>
inline void University::menu(string menuText, F foo1 ...)
{
	F* foo = &foo1; //������ ������ � ������� ���������
	int fooAmount = 0;
	while (*foo) //���� ����������� ���������
	{
		foo++; //�������� ����������. ����� �������� ������ �� ���������
		fooAmount++;
	}
	foo = &foo1; //������ ������ � ������� ���������

	int menu;
	while (true)
	{
		cout << menuText << "-> ";
		cin >> menu;

		while (menu < 0 || menu > fooAmount || cin.fail()) {
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "    Non-existent menu case. Re-enter\n-> ";
			cin >> menu;
		}
		if (menu == 0) return;
		(this->*(*(foo + menu - 1)))();
	}
}