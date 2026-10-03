#pragma once

#include <iostream>
#include"Stack.h"

using namespace std;

void res(string str)
{

	Stack<char, 100> st;
	bool istrue = true;

	for (size_t i = 0; i < str.length(); i++)
	{
		char temp = str[i];

		if (temp == ';')
		{
			break;
		}
		if (temp == '(' || temp == '[' || temp == '{')
		{
			st.push(temp);
		}
		else if (temp == ')')
		{
			if (st.isEmpty() || st.peek() != '(')
			{
				istrue = false;
				cout << "ПОмилка:";
				for (size_t j = 0; j <= i; j++)
				{
					cout << str[j];
				}

				cout << endl;
				break;
			}
			st.pop();

		}
		else if (temp == ']')
		{
			if (st.isEmpty() || st.peek() != '[')
			{
				istrue = false;

				cout << "Помилка: ";

				for (size_t j = 0; j <= i ; j++)
				{
					cout << str[j];
				}
				cout << endl;
				break;
			}
			st.pop();
		}
		else if (temp == '}')
		{
			if (st.isEmpty() || st.peek() != '{')
			{
				istrue = false;

				cout << "Помилка: ";

				for (size_t j = 0; j <= i; j++)
				{
					cout << str[j];
				}
				cout << endl;
				break;
			}
			st.pop();
		}

	}

	if (istrue && !st.isEmpty())
	{
		istrue = false;

		cout << "Помилка: ";
		for (size_t i = 0; i < str.length(); i++)
		{
			if (str[i] == ';')
			{
				break;
			}
			cout << str[i];
		}
		cout << endl;
	}
	if (istrue)
	{
		cout << "рядок правильний";
	}
}