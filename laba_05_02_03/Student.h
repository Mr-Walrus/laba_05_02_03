/*
#	���������� ����� � ������ Student, ���������� ��������� ����:
#		������� � ��������;
#		����� ������;
#		��������� �������� � ��������������� �� ������.
#	���������� ������ ������� � ���� �����,
	������������� �������� ���������� � ������� ��� �������� ���� Student.
	������� ����� �������� �� ��������.
	�������� ���������, ����������� ��������� ��������:
		������ ������ ���� ����������� �� ����������� �������� �����;
		����� �� ������� ������� � ������� ����� ��� ���� ���������, ������� ���� �� ���� ������ 2;
			���� ����� ��������� ���, ������� ��������������� ���������.
*/
#pragma once
#include <iostream>
#include <string>
#include "Exception.h"
#include "Double_List.h"

enum class sortType
{
	Name,
	AverageMark,
	GrupNum
};
enum class subjectCompareType
{
	Title,
	Mark,
	Strict
};

struct Subject
{
	string title;
	int8_t mark = 0;
	static subjectCompareType _compareType;
	Subject(string title, int8_t mark) : title(title), mark(mark) {}
	Subject() : mark(0) {}
	Subject(const Subject& other) : title(other.title), mark(other.mark) {}
	Subject& operator= (const Subject& other) {
		title = other.title;
		mark = other.mark;
		return *this;
	}
	bool operator== (Subject const& other) const {
		return _compareType == subjectCompareType::Title ? this->title == other.title :
			_compareType == subjectCompareType::Mark ? this->mark == other.mark :
			this->title == other.title && this->mark == other.mark;
	}
};

class Student
{
private:

	string name;
	int grupNum = 0;
	List<Subject> subjects;

	double averageMark = 0.0;
	static sortType _sortType;

public:
	Student();
	Student(string name, int grupNum, List<Subject> subjects);
	Student(const Student& other); // ����������� �����������
	~Student();

	Student& operator= (const Student& other); // �������� ������������
	bool operator< (Student const& other) const;

	void setName(string);
	string getName();

	void setGrupNum(int);
	int getGrupNum();

	void countAverageMark();
	double getAverageMark();

	void setTitle(string, string);
	void setMark(string, int8_t);
	int8_t getMark(string);
	void delSubject(string);
	void addSubject(string, int8_t);

	static void setSortType(sortType sortType);

	void print();
};

