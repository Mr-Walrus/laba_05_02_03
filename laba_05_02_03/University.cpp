#include "University.h"

void University::setSTName()
{
	Student::setSortType(sortType::Name);
	cout << "\n\nSort order was set to Name\n\n";
}

void University::setSTAverageMark()
{
	Student::setSortType(sortType::AverageMark);
	cout << "\n\nSort order was set to Average Mark\n\n";
}

void University::setSTGrupNum()
{
	Student::setSortType(sortType::GrupNum);
	cout << "\n\nSort order was set to Grup Number\n\n";
}

University::University() {}

University::University(List<Student> students) : students(students) {}

University::University(const University& other) : students(other.students) {}

University::~University() {}

University& University::operator++()
{
	menu(
		"\tAdd:\n    1. Student\n    2. Subject\n    0. Back\n",
		&University::addStudent,
		&University::addSubject
	);
	return *this;
}

void University::edit()
{
	menu(
		"\tEdit:\n    1. Student\n    2. Subject\n    0. Back\n",
		&University::editStudent,
		&University::editSubject
	);
}

University& University::operator--()
{
	menu(
		"\tRemove:\n    1. Student\n    2. Subject\n    0. Back\n",
		&University::delStudent,
		&University::delSubject
	);
	return *this;
}

void University::addStudent()
{
	int gnum, mark;
	string name, title;
	List<Subject> subjects;
	cout << "Enter student's\n";
	cout << "  Name\n->";
	getline(cin, name);
	getline(cin, name);
	cout << "  Grup Number\n->";
	cin >> gnum;
	cout << "  Subject and Mark(0 to stop):\n";
	while (true)
	{
		cout << "  Enter Subject\n->";
		getline(cin, title);
		getline(cin, title);
		if (title == "0")
			break;
		cout << "  Enter Mark\n->";
		cin >> mark;
		subjects.push_back(Subject(title, mark));
	}
	students.push_back(Student(name, gnum, subjects));
}

void University::addSubject()
{
	int num, mark;
	string title;
	for (size_t i = 0; i < students.size(); i++)
		cout << "    " << i + 1 << "\t" << students[i].getName() << endl;
	cout << "Select student\n->";
	cin >> num;
	students[num - 1].print();
	cout << "  Enter Subject\n->";
	getline(cin, title);
	getline(cin, title);
	cout << "  Enter Mark\n->";
	cin >> mark;
	students[num - 1].addSubject(title, mark);
}

void University::editStudent()
{
	int num, v;
	for (size_t i = 0; i < students.size(); i++)
		cout << "    " << i + 1 << "\t" << students[i].getName() << endl;
	cout << "Select student\n->";
	cin >> num;

	cout << "\tEdit student's:" << endl;
	cout << "    1. Name" << endl;
	cout << "    2. Grup Number" << endl;
	cout << "    3. Mark and Subject" << endl;
	cout << "    0. Back" << endl;
	cin >> v;
	switch (v) {
	case 1: {
		string name;
		cout << "Enter new name: ";
		cin.ignore();
		getline(cin, name);
		students[num - 1].setName(name);
		cout << "Complete!" << endl;
		break; }
	case 2: {
		int gn;
		cout << "Enter new grup number:" << endl;
		cin >> gn;
		students[num - 1].setGrupNum(gn);
		cout << "Complete!" << endl;
		break; }
	case 3: {
		editSubject(num - 1);
		break; }
	default: {
		cout << "Incorrected number" << endl;
		break; }
	}
}

void University::editSubject(size_t index = -1)
{
	int num;
	string title;
	for (size_t i = 0; i < students.size(); i++)
		cout << "    " << i + 1 << "\t" << students[i].getName() << endl;
	cout << "Select student\n->";
	cin >> num;
	students[num - 1].print();
	cout << "Enter subject\n->";
	getline(cin, title);
	getline(cin, title);
}

void University::delStudent()
{
	int num;
	for (size_t i = 0; i < students.size(); i++)
		cout << "    " << i + 1 << "\t" << students[i].getName() << endl;
	cout << "Select student\n->";
	cin >> num;
	students.pop(num - 1);
}

void University::delSubject()
{
	int num, mark;
	string title, title2;
	for (size_t i = 0; i < students.size(); i++)
		cout << "    " << i + 1 << "\t" << students[i].getName() << endl;
	cout << "Select student\n->";
	cin >> num;
	students[num - 1].print();
	cout << "Enter subject\n->";
	getline(cin, title);
	getline(cin, title);
	students[num - 1].delSubject(title);
}


void University::print()
{
	cout << endl;
	for (size_t i = 0; i < students.size(); i++)
		students[i].print();
}

void University::sort()
{
	menu(
		"\tSort by:\n    1. Name\n    2. Average Mark\n    3. Grup Number\n    0. Back\n",
		&University::setSTName,
		&University::setSTAverageMark,
		&University::setSTGrupNum
	);
	students.sort();
}
