#pragma once

#include<iostream>
using namespace std;

class Pet
{
protected:
	string name;
	int age;
	double weight;

public:
	Pet(string petName, int petAge, double petWeight)
	{
		name = petName;
		age = petAge;
		weight = petWeight;
	}

	void printInfo()
	{
		cout << "Імя " << name << "Вік" << age << "Вес" << weight << endl;
	}
};


class Dog : public Pet
{
	string foodType;
	string Cmd;

public:

	Dog(string name, int age, double weight, string food, string cmd) : Pet(name, age, weight) 
	{
		foodType = food;
		Cmd = cmd;
	}

	void printDog()
	{
		cout << "Собака";
		printInfo();
		cout << "Корм" << foodType << "Команда " << Cmd << endl;
	}
};


class Cat : public Pet
{

	string foodType;
	bool Indoor;

public:
	Cat(string name, int age, double weight, string food, bool indoor) : Pet(name , age, weight) 
	{
		foodType = food;
		Indoor = indoor;
	}

	void printCat()
	{
		cout << "Кіт";
		printInfo();
		cout << "Корм " << foodType << "домашня " << (Indoor ? "Так" : "Ні") << endl;
	}
};


class Parrot : public Pet
{
	string foodType;
	double wingspan;
public:
	Parrot(string name, int age, double weight, string food, double span) : Pet(name, age, weight) 
	{
		foodType = food;
		wingspan = span;
	}

	void printParrot()
	{
		cout << "Папуга";
		printInfo();
		cout << "Попуга " << foodType << "Розмах крил " << wingspan << " см" << endl;
	}
};