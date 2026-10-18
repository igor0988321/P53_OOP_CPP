#pragma once
#include<iostream>
#include <fstream>
#include"List.h"
#include"BTree.h"
#include <string>

using namespace std;

class Protocol
{
	string number;
	string date;
	int sum;
	bool isPay = false;

public:

	string getNumber()const
	{
		return number;
	}

	int getSum() const
	{
		return sum;
	}

	bool getIsPay() const
	{
		return isPay;
	}

	void setPaid(bool pay)
	{
		isPay = pay;
	}

	friend ostream& operator<<(ostream& out, const Protocol& p)
	{
		out << "   [Протокол] Дата: " << p.date
			<< " | Сума: " << p.sum << "грн"
			<< " | Статус: " << (p.isPay ? "Спалчено" : "Не сплачено");
		return out;
	}
	friend ostream& operator<<(ostream& out, const Protocol* p)
	{
		if (p)
			out << *p;
		return out;
	}

	void input()
	{
		cout << "Ведіть номер машини: ";
		cin >> number;
		cout << "Ведіть дату (11.11.2011): ";
		cin >> date;
		cout << "Ведіть суму штрафу: ";
		cin >> sum;
		isPay = false;
	}

	void save(ostream& fout) const
	{
		fout << number << endl << date << endl << sum << endl << isPay << endl;
	}

	void load(ifstream& fin)
	{
		fin >> number >> date >> sum >> isPay;
	}
};




class BasePolice
{
	BTree<string, List<Protocol*>*> base;

public:

	void addProtocol();

	void print();

	void printAll();

	void print(string number1, string number2);

	void save();

	void load();

	void pay();
};

void BasePolice::addProtocol()
{
	Protocol* p = new Protocol();
	p->input();

	List<Protocol*>** l = base.getValue(p->getNumber());

	if (l != nullptr && *l != nullptr)
	{
		(*l)->push_back(p);
		cout << ">> Протокол додано до існуючої картки авто [" << p->getNumber() << "].\n";
	}
	else
	{
	
		List<Protocol*>* newList = new List<Protocol*>();
		newList->push_back(p);
		base.push_r(p->getNumber(), newList);
		cout << ">> Створено новий запис для авто [" << p->getNumber() << "] та додано протокол.\n";
	}
}

void BasePolice::print()
{
	string number;
	cout << "Введіть номер авто для пошуку: ";
	cin >> number;

	List<Protocol*>** l_ptr = base.getValue(number);

	if (l_ptr != nullptr && *l_ptr != nullptr)
	{
		List<Protocol*>* l = *l_ptr;

		cout << "\nПорушення для номера: " << number << endl;
		for (size_t i = 0; i < l->getSize(); i++)
		{
			Protocol* p = (*l)[i];

			cout << *p << endl;
		}
	}
	else
	{
		cout << "Записи для номеру " << number << " не знайдено.\n";
	}
}

void BasePolice::printAll()
{
	cout << "\n================ ПОВНА БАЗА ДАНИХ ДАІ ================\n";
	base.print();
	cout << "======================================================\n";
}

void BasePolice::print(string number1, string number2)
{
	cout << "\n=== Друк по діапазону [" << number1 << "-" << number2 << "] ===\n";
	base.printRange(number1, number2);
}

void BasePolice::save()
{
	ofstream fout("db.txt");
	if (!fout.is_open())
	{
		cout << "Помилка відкриття файлу!";
		return;
	}

	cout << "база даних успішно збережено в файл!";
	fout.close();
}

void BasePolice::load()
{
	ifstream fin("db.txt");
	if (!fin.is_open())
	{
		cout << "Файл бази даних не знайдено!\n";
		return;
	}

	base.clear();

	while (true)
	{
		Protocol* p = new Protocol();
		p->load(fin);

		if (fin.fail())
		{
			delete p;
			break;
		}

		List<Protocol*>** l = base.getValue(p->getNumber());
		if (l != nullptr && *l != nullptr)
		{
			(*l)->push_back(p);
		}
		else
		{
			List<Protocol*>* newList = new List<Protocol*>();
			newList->push_back(p);
			base.push_r(p->getNumber(), newList);
		}
	}
	fin.close();
	cout << "База даних успішно завантажена!\n";
}


void BasePolice::pay()
{
	string number;
	cout << "Введіть номер авто для оплати штрафу: ";
	cin >> number;

	List<Protocol*>** l_ptr = base.getValue(number);

	if (l_ptr != nullptr && *l_ptr != nullptr)
	{
		List<Protocol*>* l = *l_ptr; 

		cout << "Квитанція для авто " << number << ":\n";
		for (size_t i = 0; i < l->getSize(); i++)
		{
			Protocol* p = (*l)[i]; 
			cout << i + 1 << ". " << *p << endl;
		}

		cout << "Виберіть номер квитанції для оплати (1-" << l->getSize() << "): ";
		size_t index;
		cin >> index;

		if (index >= 1 && index <= l->getSize())
		{
			(*l)[index - 1]->setPaid(true);
			cout << "Штраф успішно оплачено!\n";
		}
		else
		{
			cout << "Некоректний номер квитанції.\n";
		}
	}
	else
	{
		cout << "Номер " << number << " не знайдено в базі.\n";
	}
}