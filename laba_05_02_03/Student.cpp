#include "Student.h"

sortType Student::_sortType = sortType::GrupNum;
subjectCompareType Subject::_compareType = subjectCompareType::Mark;

Student::Student() :
	grupNum(0), averageMark(0) {}

Student::Student(string name, int grupNum, List<Subject> subjects) :
	name(name), grupNum(grupNum), subjects(subjects)
{
	countAverageMark();
}

Student::Student(const Student& other) :
	name(other.name), grupNum(other.grupNum), subjects(other.subjects), averageMark(other.averageMark) {}

Student::~Student() {}

Student& Student::operator=(const Student& other)
{
	this->name = other.name;
	this->grupNum = other.grupNum;
	this->subjects = other.subjects;
	this->averageMark = other.averageMark;
	return *this;
}

bool Student::operator<(Student const& other) const
{
	return _sortType == sortType::Name ? this->name < other.name :
		_sortType == sortType::GrupNum ? this->grupNum < other.grupNum :
		this->averageMark < other.averageMark;
}

void Student::setName(string name)
{
	this->name = name;
}

string Student::getName()
{
	return name;
}

void Student::setGrupNum(int grupNum)
{
	this->grupNum = grupNum;
}

int Student::getGrupNum()
{
	return grupNum;
}

void Student::countAverageMark()
{
	if (subjects.empty()) throw Exception("List is empty");
	averageMark = 0.0;
	for (size_t i = 0; i < subjects.size(); i++)
		averageMark += subjects[i].mark;
	averageMark /= subjects.size();
}

double Student::getAverageMark()
{
	return averageMark;
}

void Student::setTitle(string oldTitle, string newTitle)
{
	if (subjects.empty()) throw Exception("List is empty");
	Subject::_compareType = subjectCompareType::Title;
	List<int> indexes = subjects.search({ oldTitle, NULL });
	if (!indexes.empty())
		subjects[indexes[0]].title = newTitle;
}

void Student::setMark(string subject, int8_t mark)
{
	if (subjects.empty()) throw Exception("List is empty");
	Subject::_compareType = subjectCompareType::Title;
	List<int> indexes = subjects.search({ subject, NULL });
	if (!indexes.empty())
		subjects[indexes[0]].mark = mark;
	countAverageMark();
}

int8_t Student::getMark(string subject)
{
	if (subjects.empty()) throw Exception("List is empty");
	Subject::_compareType = subjectCompareType::Title;
	List<int> indexes = subjects.search({ subject, NULL });
	if (indexes.empty()) return -1;
	return subjects[indexes[0]].mark;
}

void Student::delSubject(string subject)
{
	if (subjects.empty()) throw Exception("List is empty");
	Subject::_compareType = subjectCompareType::Title;
	List<int> indexes = subjects.search({ subject, NULL });
	if (indexes.empty()) return;
	for (size_t i = 0; i < indexes.size(); i++)
		subjects.pop(indexes[i]);
	countAverageMark();
}

void Student::addSubject(string subject, int8_t mark)
{
	if (subjects.empty()) throw Exception("List is empty");
	Subject::_compareType = subjectCompareType::Title;
	List<int> indexes = subjects.search({ subject, NULL });
	if (indexes.empty())
		subjects.push_back(Subject(subject, mark));
	countAverageMark();
}

void Student::setSortType(sortType sortType)
{
	_sortType = sortType;
}

void Student::print()
{
	cout << name << " " << grupNum << endl;
	for (size_t i = 0; i < subjects.size(); i++)
		cout << "\t" << subjects[i].title << ":\t" << (subjects[i].mark > 0 ? to_string(subjects[i].mark) : "нет") << endl;
	cout << "\tAverage mark:\t" << averageMark << endl << endl;
}
