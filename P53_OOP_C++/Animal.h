
#pragma once

#include <iostream>
#include <string>

using namespace std;

class IPrinable
{
public:
    virtual void print() = 0;
    virtual ~IPrinable() {}
};

class Animal
{
    string name;
    int age;

public:
    Animal(string n, int a) : name(n), age(a) {}

    virtual ~Animal() {}

    string getName() const { return name; }
    int getAge() const { return age; }

    virtual string getType() { return "Animal"; }
    virtual string getVoice() = 0;
};

inline string Animal::getVoice()
{
    return "????";
}

class Cat : public Animal, public IPrinable
{
    int mouse = 0;

public:
    Cat(string n, int a) : Animal(n, a) {}

    ~Cat()
    {
        cout << "Destr Cat" << endl;
    }

    string getType() override { return "Cat"; }
    string getVoice() override { return "Mau Mau"; }

    void print() override
    {
        cout << getType() << ": " << getName()
            << ", Age: " << getAge() << endl;
    }

    void cathMouse() { mouse++; }
    int getMouse() const { return mouse; }
};

class SiamCat : public Cat
{
public:
    SiamCat(string n, int a) : Cat(n, a) {}

    string getType() override { return "SiamCat"; }
    string getVoice() override { return "Myau Myau"; }
};

class Dog : public Animal, public IPrinable
{
public:
    Dog(string n, int a) : Animal(n, a) {}

    string getType() override { return "Dog"; }
    string getVoice() override { return "Gaw Gaw"; }

    void print() override
    {
        cout << getType() << ": " << getName()
            << ", Age: " << getAge() << endl;
    }
};

class Ravlik : public Animal
{
public:
    Ravlik(string n, int a) : Animal(n, a) {}

    string getType() override { return "Ravlik"; }
    string getVoice() override { return Animal::getVoice(); }
};
