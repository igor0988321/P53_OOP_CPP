#pragma once
#include<iostream>
using namespace std;



//class Engine
//{
//	int cilindr = 4;
//
//
//
//public:
//	void start()
//	{
//		cout << "Engine start" << endl;
//	}
//
//
//	void stop()
//	{
//		cout << "Engine stop" << endl;
//	}
//
//};
//
//class Car
//{
//	Engine en;
//
//
//
//public:
//
//	void move()
//	{
//		en.start();
//		en.stop();
//	}
//
//};


//Агрегація
//class Engine
//{
//	int cilindr = 4;
//
//	int power = 50;
//
//public:
//	void start()
//	{
//		cout << "Engine start" << endl;
//	}
//
//
//	void stop()
//	{
//		cout << "Engine stop" << endl;
//	}
//
//	void powerUpgrade()
//	{
//		power += 10;
//	}
//
//};
//
//class Car
//{
//	Engine* en;
//
//
//
//public:
//
//	Car(Engine* en) : en(en) {}
//
//	void move()
//	{
//		en->start();
//		en->stop();
//	}
//
//	Engine* getEngine()
//	{
//		return en;
//	}
//};
//
//class STO
//{
//	Engine* en;
//
//
//public:
//
//	void setEngine(Engine* en)
//	{
//		this->en = en;
//	}
//
//	void uprgade()
//	{
//		en->powerUpgrade();
//	}
//};




//композиція
//class Engine
//{
//	int cilindr = 4;
//
//	int power = 50;
//
//public:
//	void start()
//	{
//		cout << "Engine start" << endl;
//	}
//
//
//	void stop()
//	{
//		cout << "Engine stop" << endl;
//	}
//
//	void powerUpgrade()
//	{
//		power += 10;
//	}
//
//};
//
//class Car
//{
//	Engine* en;
//
//
//
//public:
//
//	Car() { en = new Engine; }
//
//	~Car() { delete en; }
//
//	void move()
//	{
//		en->start();
//		en->stop();
//	}
//
//	//Engine* getEngine()
//	//{
//	//	return en;
//	//}
//};
//
//class STO
//{
//	Engine* en;
//
//
//public:
//
//	void setEngine(Engine* en)
//	{
//		this->en = en;
//	}
//
//	void uprgade()
//	{
//		en->powerUpgrade();
//	}
//};



//Наслідування
class Human
{
	string name;
	int age;

public:
	Human(string n,int a)
	{
		name = n;
		age = a;
		//cout << "ctor Human" << endl;
	}

	~Human()
	{
		//cout << "Destr human" << endl;
	}



	void setAge(int a)
	{
		age = a;
	}

	void info()
	{
		cout << "Name: " << name << endl;
		cout << "Age: " << age << endl;

	}

	void method()
	{
		//age
		//name
	}

};


class Player : public Human
{
	int goal;

public:
	Player(string n,int age, int goal) : Human(n, age), goal(goal)
	{
		//cout << "ctor Player" << endl;
	}

	~Player()
	{
		//cout << "destr player" << endl;
	}

	void info()
	{
		Human::info();
		cout << "Goal : "<< goal << endl;
	}

	void info(int a){}

	void method() = delete;
};


class Device
{
public:
	int id;

	Device(int id) : id(id)
	{

	}
};

class LANDevice : virtual public Device
{
	int id;

public:
	LANDevice(int id, int id_d) : id(id), Device(id_d)
	{

	}

	int getID() { return id; }
};

class WiFiDevice : virtual public Device
{
	int id;

public:
	WiFiDevice(int id, int id_d) : id(id), Device(id_d)
	{

	}

	int getID() { return id; }
};

class Router : public WiFiDevice, public LANDevice
{
	int id;

public:
	Router(int id, int id_l, int id_w, int id_d) : id(id), WiFiDevice(id_w, id_d), LANDevice(id_l, id_d), Device(id_d)
	{

	}
};