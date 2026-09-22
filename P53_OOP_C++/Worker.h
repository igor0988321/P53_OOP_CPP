
#pragma once


#include <iostream>

using namespace std;

class Worker
{
	char* name;
	char* pos;
	int year;
	double salary_val;


public:




	explicit Worker(const char* Name = "", const char* Pos = "", int Year = 0, double salary = 0.0)
	{
		name = new char[strlen(Name) + 1];
		strcpy(name, Name);

		pos = new char[strlen(Pos) + 1];
		strcpy(pos, Pos);

		year = Year;
		salary_val = salary;
	}

	Worker& operator=(const Worker& obj)
	{
		if (this != &obj)
		{
			delete[] name;
			delete[] pos;

			name = new char[strlen(obj.name) + 1];
			strcpy(name, obj.name);

			pos = new char[strlen(obj.pos) + 1];
			strcpy(pos, obj.pos);

			year = obj.year;
			salary_val = obj.salary_val;
		}

		return *this;
	}

	


	Worker(const Worker& obj) : year(obj.year), salary_val(obj.salary_val)
	{
		name = new char[strlen(obj.name) + 1];
		strcpy(name, obj.name);

		pos = new char[strlen(obj.pos) + 1];
		strcpy(pos, obj.pos);
	}

	~Worker()
	{
		delete[] name;
		delete[] pos;
	}

	void display() const
	{
			cout << " Піб " << " " << name
				<< " Посада " << " " << pos
				<< " Стаж " << " " << year
				<< " Зарплата " << " " << salary_val << endl;

	}


	int getExperience(int year) const
	{
		return year - this->year;
	}



	double getSalary() const
	{
		return salary_val;
	}


	const char* getpos() const
	{
		return pos;
	}

};


Worker* getExperience(Worker* arr, int size, int minExp, int year_v, int& arrsize)
{
	arrsize = 0;
	for (size_t i = 0; i < size; i++)
	{
		if (arr[i].getExperience(year_v) > minExp)
		{
			arrsize++;
		}
	}

	if (arrsize == 0)
	{
		return nullptr;
	}

	Worker* res = new Worker[arrsize];
	int index = 0;
	for (size_t i = 0; i < size; i++)
	{
		if (arr[i].getExperience(year_v) > minExp)
		{
			res[index++] = arr[i];
		}
	}
	return res;
}

Worker* getSalary(Worker* arr, int size, double minSalary, int& arrsize)
{

	arrsize = 0;
	for (size_t i = 0; i < size; i++)
	{
		if (arr[i].getSalary() > minSalary)
		{
			arrsize++;
		}
	}

	if (arrsize == 0)
	{
		return nullptr;
	}

	Worker* res = new Worker[arrsize];
	int index = 0;
	for (size_t i = 0; i < size; i++)
	{
		if (arr[i].getSalary() > minSalary)
		{
			res[index++] = arr[i];
		}
	}
	return res;
}

Worker* getPos(Worker* arr, int size, const char* Pos, int& arrsize)
{
	arrsize = 0;
	for (size_t i = 0; i < size; i++)
	{
		if (strcmp(arr[i].getpos(), Pos) == 0)
		{
			arrsize++;
		}
	}

	if (arrsize == 0)
	{
		return nullptr;
	}

	Worker* res = new Worker[arrsize];
	int index = 0;
	for (size_t i = 0; i < size; i++)
	{
		if (strcmp(arr[i].getpos(), Pos) == 0)
		{
			res[index++] = arr[i];
		}
	}
	return res;
}


void displayinfo(Worker* arr, int size, const char* all)
{
	cout << all << endl;
	if (arr == nullptr || size == 0)
	{
		cout << "Список порожній" << endl;
		return;
	}
	for (size_t i = 0; i < size; i++)
	{
		arr[i].display();
	}
}
