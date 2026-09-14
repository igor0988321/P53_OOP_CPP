#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

#include"Student.h"
#include"Array.h"

using namespace std;


int main()
{
	//14.09.2026 Lesson 2


	Array arr(10);
	arr.setRandom();
	arr.show();
	

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