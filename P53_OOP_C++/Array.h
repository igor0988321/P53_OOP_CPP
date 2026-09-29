#pragma once

#include <iostream>
#include <cstdlib>
#include<cassert>


using namespace std;


template<class T>
class Array
{
	T* arr;
	int size;
	int capacity;
	int grow;

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

	int GetSize() const;

	void SetSize(int newSize, int newgrow = 1);

	int GetUpperBound() const;

	bool isEmpty() const;

	void FreeExtra();
	
	void RemoveAll();

	T& GetAt(int index);

	void SetAt(int index, const T& value);

	void Append(const Array& obj);

	void InsertAt(int index, const T& value);

	void RemoveAt(int index);


	T& operator[](int index);

	Array& operator+=(const T& value);
	Array operator+(const T& value) const;

	bool operator==(const Array& obj) const;
	bool operator!=(const Array& obj) const;

	friend ostream& operator<<(ostream& os, const Array& obj);
	friend istream& operator>>(istream& is, Array& obj);


};



template<class T>
Array<T>::Array() 
{
	arr = nullptr;
	size = 0;
	capacity = 0;
	grow = 1;
}

template<class T>
Array<T>::Array(int s)
{
	size = s;
	capacity = s;
	grow = 1;

	if (capacity > 0)
	{
		arr = new T[capacity]{};
	}
	else
	{
		arr = nullptr;
	}
}

template<class T>
Array<T>::Array(const Array& obj)
{

	size = obj.size;
	capacity = obj.capacity;
	grow = obj.grow;

	if (capacity > 0)
	{
		arr = new T[capacity];

		for (size_t i = 0; i < size; i++)
		{
			arr[i] = obj.arr[i];
		}
	}
	else
	{
		arr = nullptr;
	}
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
	capacity = obj.capacity;
	grow = obj.grow;

	if (capacity > 0)
	{
		arr = new T[capacity];
		for (size_t i = 0; i < size; i++)
		{
			arr[i] = obj.arr[i];
		}
	}
	else
	{
		arr = nullptr;
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
		arr[i] = (T)(rand() % 100);
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
Array<T>& Array<T>::operator+=(const T& value)
{
	this->add(value);
	return *this;

}

template<class T>
Array<T> Array<T>::operator+(const T& value) const
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


template<class T>
int Array<T>::GetSize() const
{
	return capacity;
}


template<class T>
void Array<T>::SetSize(int newSize, int newgrow)
{
	if (newgrow > 0)
	{
		grow = newgrow;
	}
	if (newSize == capacity)
	{
		size = newSize;
		if (size > capacity)
		{
			size = capacity;
		}
		return;
	}

	T* newarr = nullptr;

	if (newSize > 0)
	{
		newarr = new T[newSize]{};

		int size2 = size;
		if (size2 > newSize)
		{
			size2 = newSize;
		}
		for (size_t i = 0; i < size2; i++)
		{
			newarr[i] = arr[i];
		}
	}

	delete[] arr;

	arr = newarr;
	capacity = newSize;


	if (size > capacity)
	{
		size = capacity;
	}
}

template<class T>
int Array<T>::GetUpperBound() const
{
	return size - 1;
}

template<class T>
bool Array<T>::isEmpty() const
{
	return size == 0;
}


template<class T>
void Array<T>::FreeExtra()
{
	if (size == capacity)
	{
		return;
	}

	T* newarr = nullptr;

	if (size > 0)
	{
		newarr = new T[size];
		for (size_t i = 0; i < size; i++)
		{
			newarr[i] = arr[i];
		}
	}

	delete[] arr;

	arr = newarr;
	capacity = size;
}


template<class T>
void Array<T>::RemoveAll()
{
	delete[] arr;

	arr = nullptr;
	size = 0;
	capacity = 0;
}

template<class T>
T& Array<T>::GetAt(int index)
{
	return arr[index];
}

template<class T>
void Array<T>::SetAt(int index, const T& value)
{
	if (index >= 0 && index < capacity)
	{
		arr[index] = value;
	}
}


template<class T>
void Array<T>::add(const T& value)
{
	if (size >= capacity)
	{
		int newcapacity;

		if (newcapacity == 0)
		{
			newcapacity = grow;
		}
		else
		{
			newcapacity = capacity + grow;
		}

		T* newarr = new T[newcapacity];

		for (size_t i = 0; i < size; i++)
		{
			newarr[i] = arr[i];
		}

		delete[] arr;
		arr = newarr;
		capacity = newcapacity;
	}
	arr[size] = value;
	size++:
}


template<class T>
void Array<T>::Append(const Array& obj)
{
	for (size_t i = 0; i < obj.size; i++)
	{
		add(obj.arr[i]);
	}
}



template<class T>
void Array<T>::InsertAt(int index, const T& value)
{
	if (index < 0 || index > size)
	{
		return;
	}

	add(T());

	for (size_t i = size - 1; i > index; i++)
	{
		arr[i] = arr[i - 1];
	}
	arr[index] = value;

}


template<class T>
void Array<T>::RemoveAt(int index)
{
	if (index < 0 || index >= size)
	{
		return;
	}

	for (int i = index; i < size - 1; i++)
	{
		arr[i] = arr[i + 1];
	}

	size--;
}



