#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <windows.h>

#include"Student.h"
#include"Array.h"
#include"Area.h"
#include"Time.h"
#include"Reservoir.h"
#include"String.h"


using namespace std;


void printArray(const Array& a)
{
	a.show();
}


int main()
{
	SetConsoleOutputCP(65001);
	SetConsoleCP(65001);

	//18.09.2026 Lesson 3

	Reservoir r(ReservoirType::Lake);

	if (ReservoirType::Lake == r.getType())
	{
		cout << "Reservoir is a lake." << endl;
	}
	else
	{
		cout << "Reservoir is not a lake." << endl;
	}

	Time t(1, 1);

	Array* arr = new Array(5);
	arr->setRandom();

	Student s1(1, "Vasya", 30);
	Array a(10);
	a.setRandom(); // setRandom(a)
	a.show();

	//15.09.2026 Home Work 2
	// 
	// 
	
	//cout << "Площа квадрата : " << Area::squareArea(5) << endl;
	//cout << "Площа прямокутника: " << Area::rectangleArea(4, 6) << endl;
	//cout << "Площа трикутника : " << Area::triangleArea(10, 5) << endl;
	//cout << "Площа ромба : " << Area::rombArea(6, 8) << endl;

	//cout << "Загальна кількість виконаних підрахунків: " << Area::getCount() << endl;


	//14.09.2026 Lesson 2

	//Array arr(10);
	//arr.setRandom();
	//arr.show();
	//

	//Статичне поле - поле яке належить всім об*єктам одночасно
	//cout << "Count of student: " << Student::getCount() << endl;

	/*Student s1(1, "Vasya", 30);

	cout << "Count of student: " << s1.getCount() << endl;

	Student s2(0);

	cout << "Count of student: " << s2.getCount() << endl;

	s1.displayInfo();
	s2.displayInfo();*/




	//1. Ініцалізація при створенні 
	//int a = 5;
	//2. Юніформ ініцалізація
	//const int c{(int) 5.5 };
	//3.
	//const int b(5.5);



	//07.09.2026 Lesson 1
	/*Student s1(1, "Vasya", 30);
	Student s2(0);
	s1.displayInfo();
	s2.displayInfo();*/




	return 0;
}