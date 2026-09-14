#pragma once

#include <iostream>

using namespace std;

class Array
{
	int* arr;
	int size;

public:
	Array();
	Array(int s);
	~Array();

	void setRandom();

	void show();
	void add(int value);
	void remove(int index);
	void sort();
	void insert(int index, int value);
	void clear();
	void resize(int newSize);
	int getSize();
	void reverse();
	void fill(int value);
};




Array::Array() : arr(nullptr) ,size(0)
{

}

Array::Array(int s)
{
	size = s;
	arr = new int[size] {0};
}

Array::~Array()
{
	delete[] arr;
}

void Array::setRandom()
{
	for (size_t i = 0; i < size; i++)
	{
		arr[i] = rand() % 100;
	}
}

void Array::show()
{
	if (size == 0)
	{
		return;
	}

	for (size_t i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

void Array::add(int value)
{
	int* newArr = new int[size + 1];
	for (size_t i = 0; i < size; i++)
	{
		newArr[i] = arr[i];
	}
	newArr[size] = value;

	delete[] arr;
	arr = newArr;
	size++;
}

void Array::remove(int index)
{
	if (index < 0 || index >= size)
	{
		return;
	}
	int* newArr = new int[size - 1];
	for (size_t i = 0, j = 0; i < size; i++)
	{
		if (i == index)
		{
			continue;
		}
		newArr[j++] = arr[i];
	}
	delete[] arr;
	arr = newArr;
	size--;
}

void Array::sort()
{
	for (size_t i = 0; i < size - 1; i++)
	{
		for (size_t j = 0; j < size - i - 1; j++)
		{
			if (arr[i] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}


void Array::insert(int index, int value)
{
	if (index < 0 || index > size)
	{
		return;
	}

	int* newArr = new int[size + 1];
	for (size_t i = 0, j = 0; i < size + 1; i++)
	{
		if (i == index)
		{
			newArr[i] = value;
		}
		else
		{
			newArr[i] = arr[j++];
		}
	}
	delete[] arr;
	arr = newArr;
	size++;
}

void Array::clear()
{
	delete[] arr;
	arr = nullptr;
	size = 0;
}

int Array::getSize()
{
	return size;
}

void Array::fill(int value)
{
	for (size_t i = 0; i < size; i++)
	{
		arr[i] = value;
	}
}

void Array::reverse()
{
	if (size <= 1)
	{
		return;
	}
	for (size_t i = 0; i < size / 2; i++)
	{
		int temp = arr[i];
		arr[i] = arr[size - 1 - i];
		arr[size - 1 - i] = temp;
	}
}
