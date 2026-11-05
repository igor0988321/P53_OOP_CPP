#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

struct Train 
{
	string trainNum;
	string time;
	string dest;
};

inline void clear()
{
	cin.clear();
	while (cin.get() != '\n');
}

inline string getTrain(int count)
{
	int n = count % 100;
	if (n >= 11 && n <= 19)
	{
		return "поїздів";
	}
	n = count % 10;
	if (n == 1)
	{
		return "поїзд";
	}
	if (n >= 2 && n <= 4)
	{
		return "поїзди";
	}

	return "поїздів";
}

inline void inputTrain(vector<Train>& trains)
{
	int count;
	cout << "----------- Додавання поїздів -----------";
	cout << "Ведіть кількість поїздів для додавання: ";

	while (!(cin >> count) || count <= 0)
	{
		cout << "Ведіть додатне число: ";
		clear();
	}
	clear();

	for (size_t i = 0; i < count; ++i)
	{
		Train t;
		cout << "Поїзд № " << (i + 1) << ":\n";

		cout << "Ведіть номер поїзда: ";
		getline(cin, t.trainNum);

		cout << "Ведіть час відправлення: ";
		getline(cin, t.time);

		cout << "Ведіть станцію призначення: ";
		getline(cin, t.dest);

		trains.push_back(t);
	}
	cout << "\nУспішно додано " << count << " " << getTrain(count) << "!\n";
}

inline void  printTable()
{
	cout << left
		<< setw(15) << "Номер поїзда"
		<< setw(20) << "Час відправлення"
		<< setw(25) << "Станція призначення" << "\n";
	cout << string(60, '-') << "\n";
}



inline void  printTrain(const Train& t)
{
	cout << left
		<< setw(15) << t.trainNum
		<< setw(20) << t.time
		<< setw(25) << t.dest << "\n";
}


inline void displayall(const vector<Train>& trains)
{
	cout << "\n --- Результат: Список усіх поїздів --- \n";
	if (trains.empty())
	{
		cout << "База даних порожня.\n";
		return;
	}
	printTable();
	for (size_t i = 0; i < trains.size(); ++i)
	{
		printTrain(trains[i]);
	}
	cout << string(60, '-') << "\n";
}


inline void search(const vector<Train>& trains)
{
	cout << "\n--- Пошук поїздів ---\n";
	if (trains.empty())
	{
		cout << "База даних порожня.\n";
		return;
	}

	cout << "Вибір категорій пошуку:\n";
	cout << "1 - За номером поїзду\n";
	cout << "2 - За станцією призначення\n";
	cout << " Ваш вибір: ";

	int choice;
	cin >> choice;
	clear();

	bool found = false;

	if (choice == 1)
	{
		string query;
		cout << "Ведіть номер поїзду для пошуку: ";
		getline(cin, query);

		cout << "\nРезульат пошуку за номером  " <<  query << "\n";
		printTable();
		for (size_t i = 0; i < trains.size(); ++i)
		{
			if (trains[i].trainNum == query)
			{
				printTrain(trains[i]);
				found = true;
			}
		}
	}
	else if (choice == 2)
	{
		string query;
		cout << "Ведіть станцію призначення: ";
		getline(cin, query);

		cout << "\nРезульат пошуку за станцією " << query << "\n";
		printTable();
		for (size_t i = 0; i < trains.size(); ++i)
		{
			if (trains[i].dest == query)
			{
				printTrain(trains[i]);
				found = true;
			}
		}
	}
	else
	{
		cout << "Некоректний вибір категорій\n";
		return;
	}

	if (!found)
	{
		cout << "Поїзда за вашим запитом не знайдено\n";
	}
	else
	{
		cout << string(60, '-') << "\n";
	}


}


