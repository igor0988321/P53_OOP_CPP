#pragma once

#include <iostream>
#include<cassert>


using namespace std;


template<class T>
class Array
{
	int* arr;
	int size;

public:
	Array();
	
	explicit Array(int s);

	Array(const Array& obj);

	Array& operator=(const Array& obj);
	~Array();

	void setRandom();

	void show();
	void add(const T& value);
	void remove(int index);
	void sort();
	void insert(int index, const T& value);
	void clear();
	void resize(int newSize);
	int getSize();
	void reverse();
	void fill(const T& value);

	T& operator[](int index);

	Array& operator+=(int value);
	Array operator+(int value) const;

	bool operator==(const Array& obj) const;
	bool operator!=(const Array& obj) const;

	friend ostream& operator<<(ostream& os, const Array& obj);
	friend istream& operator>>(istream& is, Array& obj);


};



template<class T>
Array<T>::Array() : arr(nullptr) ,size(0)
{

}

template<class T>
Array<T>::Array(int s)
{
	size = s;
	arr = new int[size] {0};
}

template<class T>
Array<T>::Array(const Array& obj)
{

	size = obj.size;
	arr = new T[size];
	for (size_t i = 0; i < size; i++)
	{
		arr[i] = obj.arr[i];
	}
	cout << "CopyConstr " << arr << endl;
}

template<class T>
Array<T>& Array<T>::operator=(const Array& obj)
{
	if (this == &obj)
	{
		return *this;
	}

	delete[] arr;

	size = obj.size;
	arr = new T[size];
	for (size_t i = 0; i < size; i++)
	{
		arr[i] = obj.arr[i];
	}

	return *this;
}

template<class T>
Array<T>::~Array()
{
	delete[] arr;
}

template<class T>
void Array<T>::setRandom()
{
	for (size_t i = 0; i < size; i++)
	{
		arr[i] = rand() % 100;
	}
}

template<class T>
void Array<T>::show()
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

template<class T>
void Array<T>::add(const T& value)
{
	T* newArr = new T[size + 1];
	for (size_t i = 0; i < size; i++)
	{
		newArr[i] = arr[i];
	}
	newArr[size] = value;

	delete[] arr;
	arr = newArr;
	size++;
}

template<class T>
void Array<T>::remove(int index)
{
	if (index < 0 || index >= size)
	{
		return;
	}
	T* newArr = new T[size - 1];
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

template<class T>
void Array<T>::sort()
{
	for (size_t i = 0; i < size - 1; i++)
	{
		for (size_t j = 0; j < size - i - 1; j++)
		{
			if (arr[i] > arr[j + 1])
			{
				T temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}


template<class T>
void Array<T>::insert(int index, const T& value)
{
	if (index < 0 || index > size)
	{
		return;
	}

	T* newArr = new T[size + 1];
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

template<class T>
void Array<T>::clear()
{
	delete[] arr;
	arr = nullptr;
	size = 0;
}

template<class T>
int Array<T>::getSize()
{
	return size;
}

template<class T>
void Array<T>::fill(const T& value)
{
	for (size_t i = 0; i < size; i++)
	{
		arr[i] = value;
	}
}

template<class T>
void Array<T>::reverse()
{
	if (size <= 1)
	{
		return;
	}
	for (size_t i = 0; i < size / 2; i++)
	{
		T temp = arr[i];
		arr[i] = arr[size - 1 - i];
		arr[size - 1 - i] = temp;
	}
}

template<class T>
T& Array<T>::operator[](int index)
{
	return arr[index];
}

template<class T>
Array<T>& Array<T>::operator+=(int value)
{
	this->add(value);
	return *this;

}

template<class T>
Array<T> Array<T>::operator+(int value) const
{
	Array temp(*this);
	temp.add(value);
	return temp;
}



template<class T>
bool Array<T>::operator==(const Array<T>& obj) const
{
	if (this->size != obj.size)
	{
		return false;
	}
	for (size_t i = 0; i < size; i++)
	{
		if (this->arr[i] != obj.arr[i])
		{
			return false;
		}
	}
	return true;
}


template<class T>
bool Array<T>::operator!=(const Array<T>& obj) const
{
	if (*this != obj)
	{
		return false;
	}
	else
	{
		return true;
	}
}

template<class T>
ostream& operator<<(ostream& os, const Array<T>& obj)
{
	for (size_t i = 0; i < obj.size; i++)
	{
		os << obj.arr[i] << " ";
	}
	return os;
}

template<class T>
istream& operator>>(istream& is, Array<T>& obj)
{
	for (size_t i = 0; i < obj.size; i++)
	{
		is >> obj.arr[i];
	}
	return is;
}