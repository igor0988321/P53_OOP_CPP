#pragma once
#include <iostream>
#include <fstream>
#include <bitset>
#include <iomanip>

using namespace std;

class File
{
public:
	virtual ~File() {}

	virtual void display()
	{
		ifstream file("test.txt", ios::in | ios::binary);
		if (!file.is_open())
		{
			cout << "Помилка" << "test.txt" << endl;
			return;
		}

		cout << "Вміст файлу" << "test.txt" << endl;
		char c;
		while (file.get(c))
		{
			cout << c;
		}
		cout << "\n----------------------------------------\n" << endl;
	}
};


class AsciiFile : public File
{
public:
	void display() override
	{
		ifstream file("test.txt", ios::in | ios::binary);
		if (!file.is_open())
		{
			cout << "Помилка" << "test.txt" << endl;
			return;
		}

		cout << "Вміст у ASCII " << "test.txt" << endl;
		char c;
		while (file.get(c))
		{
			cout << (int)(unsigned char)c << " ";
		}
		cout << "\n----------------------------------------\n" << endl;
	}
};


class BinaryFile : public File
{
public:
	void display() override
	{
		ifstream file("test.txt", ios::in | ios::binary);
		if (!file.is_open())
		{
			cout << "Помилка" << "test.txt" << endl;
			return;
		}

		cout << "Вміст у двійковому " <<"test.txt" << endl;
		char c;
		while (file.get(c))
		{
			cout << bitset<8>((unsigned char) c) << " ";
		}
		cout << "\n----------------------------------------\n" << endl;
	}
};


class HexFile : public File
{
public:
	void display() override
	{
		ifstream file("test.txt", ios::in | ios::binary);
		if (!file.is_open())
		{
			cout << "Помилка" << "test.txt" << endl;
			return;
		}

		cout << "Вміст у HEX " << "test.txt" << endl;
		char c;
		while (file.get(c))
		{
			cout << hex << uppercase << setw(2) << setfill('0') << (int)(unsigned char)c << " ";
		}
		cout << dec;
		cout << "\n----------------------------------------\n" << endl;
	}
};


