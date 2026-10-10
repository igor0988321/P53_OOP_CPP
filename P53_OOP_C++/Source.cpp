#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

#include <windows.h>
#include <thread> 
#include <chrono>

#include"Student.h"
#include"Array.h"
#include"Area.h"
#include"Time.h"
#include"Reservoir.h"
#include"String.h"
#include"Worker.h"
#include"Fraction.h"

#include"Stack.h"
#include"Calc.h"
#include"Stack2.h"
#include"Queue.h"
#include"PriorityQueue.h"
#include"Bus.h"
#include"ForwardList.h"

using namespace std;


//void printArray(const Array& a)
//{
//	a.show();
//}

template<class T>
void printArray(Array<T> a)
{
	a.show();
}


//void addTimePeople(People& p)
//{
//	p.addTime();
//}

int main(){
	SetConsoleOutputCP(65001);
	SetConsoleCP(65001);

	// 10.10.2026 Home Work 9

	ForwardList<int> list = { 10, 20, 30, 20, 50 };

	cout << "Початковий список: ";
	list.print();

	
	list.push_front(5);
	cout << "Після push_front(5): ";
	list.print();

	
	list.push_back(60);
	cout << "Після push_back(60): ";
	list.print();

	
	list.insert(15, 2);
	cout << "Після insert(15, 2): ";
	list.print();

	
	cout << "Перший елемент: " << list.front() << endl;
	cout << "Останній елемент: " << list.back() << endl;

	
	cout << "Елемент з індексом 2 через at(): "
		<< list.at(2) << endl;

	cout << "Елемент з індексом 3 через []: "
		<< list[3] << endl;

	
	cout << "Кількість елементів: "
		<< list.getSize() << endl;

	
	cout << "Перший індекс числа 20: "
		<< list.firstIndex(20) << endl;

	
	cout << "Останній індекс числа 20: "
		<< list.lastIndex(20) << endl;

	// 09.10.2026 Lesson 9

	//ForwardList<int> l = { 1,21,3 };
	//cout << l[1] << endl;

	//ForwardList<int> l2 = l;
	//l2.print();

	//ForwardList<int> l3 = l + l2;
	//l3.print();

	// 06.10.2026 Home Work 8

	//srand(time(0));

	//double mInterval;
	//double busInterval;
	//int maxQueue;


	//cout << "Модель зупинки" << endl;
	//cout << "Ведіть середній інтервал появи пасажирів" << endl;
	//cin >> mInterval;
	//cout << "Ведіть середній інтервал приїзду маршутки" << endl;
	//cin >> busInterval;
	//cout << "Ведіть максимальну кількість людей" << endl;
	//cin >> maxQueue;

	//Queue<People> queue;

	//int nextPasan = randominterval(mInterval);
	//int nextBus = randominterval(busInterval);

	//long long totalwaitTime = 0;
	//int totalPasan = 0;
	//int Tick = 0;

	//while (true)
	//{
	//	Tick++;
	//	cout << "[" << Tick << " сек] ";
	//	if (Tick >= nextPasan)
	//	{
	//		queue.enqueue(People(Tick));
	//		cout << "+1 пасажир ";
	//		nextPasan = Tick + randominterval(mInterval);
	//	}

	//	int Queuesize = queue.getSize();

	//	if (Queuesize > maxQueue)
	//	{
	//		if (busInterval > 2.0)
	//		{
	//			busInterval *= 0.8;
	//			cout << "Людей забагато! Інтервал маршуток зменшено до " << roundDecimal(busInterval) << " сек ";
	//		}
	//	}
	//	else if (Queuesize <= 2 && busInterval < 60.0)
	//	{
	//		busInterval *= 1.1;
	//	}

	//	if (Tick >= nextBus)
	//	{
	//		Bus bus(15);
	//		int freeSeats = bus.getFreeSeats();

	//		cout << "Маршутка прибула! Вільних місць: " << freeSeats << endl;

	//		int boarded = 0;
	//		while (queue.getSize() > 0 && freeSeats > 0)
	//		{
	//			People p = queue.peek();
	//			queue.dequeue();

	//			int waitTime = p.gettime(Tick);
	//			totalwaitTime += waitTime;
	//			totalPasan++;
	//			freeSeats--;
	//			boarded++;

	//			cout << " -> Пасажир сів у маршутку. Простояв: " << waitTime << "сек" << endl;
	//		}

	//		cout << "Забрали з зупинки: " << boarded << "чол" << endl;

	//		nextBus = Tick + randominterval(busInterval);
	//	}
	//	cout << "Людей на зупинці: " << queue.getSize()
	//		<< " | Поточний інтервал маршуток: " << roundDecimal(busInterval) << " сек" << endl;

	//	this_thread::sleep_for(chrono::seconds(1));
	//}

	// 05.10.2026 Lesson 8


	//Queue<int> q = { 1, 2, 3 };
	//q.enqueue(10);
	//q.ring();
	//q.print();
	//cout << q.peek() << endl;
	//q.clear();
	//q.print();

	//PriorityQueue<int> pq;
	//pq.enqueue(10, 1);
	//pq.enqueue(20, 2);
	//pq.enqueue(10, 1);
	//pq.enqueue(30, 3);
	//pq.enqueue(20, 2);
	//pq.print();

	//PriorityQueue<Fraction, float> p;
	//p.enqueue(Fraction(2, 3), (float)Fraction(2, 3));
	//p.enqueue(Fraction(1, 3), (float)Fraction(1, 3));
	//p.enqueue(Fraction(3, 3), (float)Fraction(3, 3));
	//p.enqueue(Fraction(5, 3), (float)Fraction(5, 3));
	//p.enqueue(Fraction(1, 3), (float)Fraction(1, 3));
	//p.print();


	//


	// 03.10.2026 Home Work 7

	//cout << "aaa";

	//string str;

	//cout << "Ведіть рядок ";

	//cin >> str;

	//res(str);


	// 02.10.2026 Lesson 7


	//Stack<int, 5> s;
	//s.push(10);
	//s.push(5);
	//s.push(20);
	//s.push(15);
	//s.push(25);
	//s.push(35);
	//s.print();
	//cout << s.peek() << endl;
	//s.pop();
	//s.pop();
	//s.print();
	//s.clear();
	//s.print();

	//Calc c("4/2");
	//cout << c.getResult() << endl;


	// 29.09.2026 Home Work 6

	//Array<int> a;

	//a.SetSize(5, 5);

	//a.add(10);
	//a.add(20);
	//a.add(30);
	//a.add(40);
	//a.add(50);
	//a.add(60);

	//cout << "Size: " << a.GetSize() << endl;
	//cout << "UpperBound: " << a.GetUpperBound() << endl;

	//a.show();

	//a.InsertAt(2, 999);

	//a.show();

	//a.RemoveAt(1);

	//a.show();

	//cout << "Element: " << a.GetAt(2) << endl;

	//a.SetAt(2, 555);

	//a.show();

	//Array<int> b;

	//b.add(100);
	//b.add(200);

	//a.Append(b);

	//a.show();

	//a.RemoveAll();

	//cout << "IsEmpty: " << a.isEmpty() << endl;


	// 28.09.2026 Lesson 6

	//Array<int> arr(10);
	//arr.setRandom();
	//arr.show();
	//cout << arr[-2] << endl;

	//Array<Fraction> f(10);
	//f.setRandom();
	//f.show();

	//Array<Student> s(5);
	//s.setRand();


	//void* p = new int{ 10 };
	//cout << *((int*)p) << endl;

	// 26.09.2026 Home Work 5


	//Array arr1(3);
	//arr1.setRandom();
	//cout << "arr1: ";
	//arr1.show();

	//
	//Array arr2 = arr1 + 99; 
	//cout << "arr2 (arr1 + 99): ";
	//arr2.show();

	//arr1 += 55; 
	//cout << "arr1 += 55: ";
	//arr1.show();

	//
	//Array arr3(3);
	//arr3.fill(10);
	//Array arr4(3);
	//arr4.fill(10);

	//if (arr3 == arr4) {
	//	cout << "(== спрацювало)" << endl;
	//}
	//else {
	//	cout << "НЕ рівні" << endl;
	//}

	//if (arr1 != arr2) {
	//	cout << "(!= спрацювало)" << endl;
	//}


	//cout << "Виведення " << arr3 << endl;



	//String s1("Привіт");
	//String s2(" Світ");

	//
	//String s3 = s1 + s2; 
	//cout << "s3 (s1 + s2): " << s3 << endl;

	//s1 += String(" Привіт");
	//cout << "s1  +=: " << s1 << endl;


	//String s4;
	//s4 = s3;
	//cout << "s4 після s4 = s3: " << s4 << endl;

	//cout << "Перша буква : " << s3[0] << endl;
	//s3[0] = 'p'; 
	//cout << "зміни першої букви: " << s3 << endl;

	//
	//
	//String alpha1("Apple");
	//String alpha2("Banana");

	//if (alpha1 == alpha2) {
	//	cout << "Рівні" << endl;
	//}
	//else {
	//	cout << "не рівні" << endl;
	//}

	//if (alpha1 < alpha2) {
	//	cout << "(< спрацювало)" << endl;
	//}


	
	// cout << "Введіть слово для рядка: ";
	// cin >> s1;
	// cout << "Ви ввели: " << s1 << endl;


	// 25.09.2026 Lesson 5

	// + - ++ --
	// + - * / += -= *= /= % %=

	// !
	// > < >= <= == != && ||

	//() [] << >>



	//Fraction f1(3, 5);
	//f1.show();
	//Fraction f2(0, 3);
	//f2.show();

	//if (f1 && f2)
	//{
	//	cout << "<<<<" << endl;
	//}
	//else
	//{
	//	cout << ">>>>" << endl;
	//}

	//f2(2, 5);


	//cout << f1["num"] << endl;
	//cout << f1 << endl;

	//cin >> f2;
	//cout << f2 << endl;


	//Fraction f4 = f1 + f2;
	//f4.show();

	//Fraction f3 = -f1;
	//f3.show();

	//(f2++).show();
	////(++f2).show();
	//f2.show();

	//f1 = f2 + 5;
	//f1 = 5 + f2;



	// 22.09.2026 Home Work 4


	//int size = 3;
	//Worker workers[3] = {
	//	Worker("Вася ", "ppppppp", 2011, 25555),
	//	Worker("Андрій ", " інженер ", 2013, 25765),
	//	Worker("Катя ", " інженер ", 2015, 2598787)
	//};
	//int year_v = 2026;

	//displayinfo(workers, size, "Всі працівники");

	//int expSize = 0;
	//Worker* expArr = getExperience(workers, size, 8, year_v, expSize);
	//displayinfo(expArr, expSize, " Працівники зі стажем більше 8 років ");
	//delete[] expArr;

	//int salSize = 0;
	//Worker* salArr = getSalary(workers, size, 20000.0, salSize);
	//displayinfo(salArr, salSize, " Працівники з зарплатою більше 20000 грн ");
	//delete[] salArr;

	//int posSize = 0;
	//Worker* posArr = getPos(workers, size, "ppppppp", posSize);
	//displayinfo(posArr, posSize, " Працівники на посаді ppppppp ");
	//delete[] posArr;
	
	



	// 21.09.2026 Lesson 4


	/*Array a(10);
	a.setRand();
	a.show();
	Array b(15);
	b.setRand();
	b = b;
	b.show();*/


	//printArray(a);
	/*a.show();*/

	//Array b(a);
	//Array c = a;

	//19.09.2026 Home Work 3

	//Reservoir blacksea("more", ReservoirType::Sea, 12343, 1233, 12334);
	//blacksea.display();

	//18.09.2026 Lesson 3



	//Time t(1, 1);

	//Array* arr = new Array(5);
	//arr->setRandom();

	//Student s1(1, "Vasya", 30);
	//Array a(10);
	//a.setRandom(); // setRandom(a)
	//a.show();

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



	std::cin.get();
	return 0;
}