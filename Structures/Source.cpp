#include <iostream>
#include <fstream>
#include <cstring>

struct Student
{
	char fio[50];
	size_t group;
	size_t zach;
	size_t marks[3];
};

void read(Student&, std::ifstream&);
void print(const Student&, std::ostream&);
double averageStGrade(const Student&);
double averageAll(Student*, size_t);
void printAll(const Student&, std::ostream&);
void printExcellent(const Student, std::ostream&);
bool isExcellentStudent(Student&);
void sort(Student*, size_t);

int main()
{
	// Students
	size_t const size = 8;
	Student students[size];
	
	std::ifstream fin("input1.txt");
	std::ofstream fout("OutAll.txt"), fout1("OutExcellent");

	for (size_t i = 0; i < size; i++)
	{
		read(students[i], fin);
	}
	sort(students, size);
	for (size_t i = 0; i < size; i++)
	{
		print(students[i], fout);
	}
	std::cout << std::endl;

	// 1. C++ given, count and print all operations.
	std::ifstream fin1Task("inFor1Task.txt");

	char str[100];
	int countPlus = 0, countMinus = 0, countMult = 0, countDiv = 0;
	while (!fin1Task.eof())
	{
		fin1Task.getline(str, 100);
		for (size_t i = 0; i < strlen(str); i++)
		{
			if (str[i] == '+')
			{
				countPlus++;
			}
			else if (str[i] == '-')
			{
				countMinus++;
			}
			else if (str[i] == '*')
			{
				countMult++;
			}
			else if (str[i] == '/')
			{
				countDiv++;
			}
		}
	}
	std::cout << std::endl;
	std::cout << "Num of plus signs: " << countPlus << std::endl;
	std::cout << "Num of minus signs: " << countMinus << std::endl;
	std::cout << "Num of multiplication signs: " << countMult << std::endl;
	std::cout << "Num of division signs: " << countDiv << std::endl;


	system("pause");
	return 0;
}

void read(Student& st, std::ifstream& stream)
{
	stream >> st.fio >> st.group >> st.zach;
	size_t size = sizeof(st.marks) / sizeof(size_t);
	for (size_t i = 0; i < size; i++)
	{
		stream >> st.marks[i];
	}
}
void print(const Student& st, std::ostream& stream)
{
	stream << "\nStudent's name " << st.fio << " group number " << st.group
		<< " record book number " << st.zach << " marks ";
		size_t size = sizeof(st.marks) / sizeof(size_t);
		for (size_t i = 0; i < size; i++)
		{
			stream << st.marks[i] << " ";
		}
}
double averageStGrade(const Student&st)
{
	double avGrade = 0;
	size_t size = sizeof(st.marks) / sizeof(size_t);
	for (size_t i = 0; i < size; i++)
	{
		avGrade += st.marks[i];
	}
	return avGrade /= size;
}
double averageAll(Student*st, size_t size)
{
	double avAll = 0;
	for (size_t i = 0; i < size; i++)
	{
		avAll += averageStGrade(st[i]);
	}
	return avAll /= size;
}
void printAll(const Student&st, std::ostream&stream)
{
	stream << "Student's name " << st.fio << " group number " << st.group
		<< " record book number " << st.zach << " average mark " << averageStGrade(st);
}
bool isExcellentStudent(Student& st)
{
	bool flag = false;
	for (size_t i = 0; i < 3; i++)
	{
		if (st.marks[i] < 5) break;
		flag = false;
	}
	return flag;
}
void printExcellent(const Student&st, std::ostream&stream)
{
	stream << "Student's name " << st.fio << " group number " << st.group
		<< " record book number " << st.zach;
}
void sort(Student*st, size_t size)
{
	for (size_t i = size - 1; i > 0; i--)
	{
		for (size_t j = 0; j < i; j++)
		{
			if (st[j].group < st[j + 1].group) std::swap(st[j], st[j + 1]);
		}
	}
	for (size_t i = size - 1; i > 0; i--)
	{
		for (size_t j = 0; j < i; j++)
		{
			if (strcmp(st[j].fio, st[j + 1].fio) > 0) std::swap(st[j], st[j + 1]);
		}
	}
}
