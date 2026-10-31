#pragma once
#include<initializer_list>

#include"Node.h"
#include"func.h"

using namespace std;



template<class T>
class List
{
	Node<T>* first;
	Node<T>* last;
	size_t   size;

	Node<T>* getNode(size_t index) const;

public:
	List();
	List(initializer_list<T> list);
	List(const List& obj);
	List<T>& operator=(const List& obj);
	~List();

	void push_front(const T& value);
	void push_back(const T& value);
	void insert(const T& value, size_t index);

	void pop_front();
	void pop_back();
	void remove(size_t index);
	void erase(const T& value);
	void erase_if(bool(*predicate)(const T&));

	T& front() const;
	T& back() const;
	T& operator[](size_t index) const;
	T  at(size_t index) const;

	size_t getSize() const;
	void print() const;
	void print(int x , int y) const;
	void clear();

	int firstIndex(const T& value);
	int lastIndex(const T& value);

	List splice(size_t index1, size_t index2);

	List operator+(const List& list);

	template<typename U>
	friend ostream& operator<<(ostream& out, const List<U>& list);

};

template<class T>
Node<T>* List<T>::getNode(size_t index) const
{
	if(index >= size)
		throw "Index out"

	Node<T>* pos = nullptr;
	if (index < size / 2)
	{
		pos = first;
		for (size_t i = 0; i < index; i++)
		{
			pos = pos->next;
		}
	}
	else
	{
		pos = last;
		for (size_t i = 0; i < size - 1 - index; i++)
		{
			pos = pos->prev;
		}
	}
	return pos;
}

template<class T>
List<T>::List() : first(nullptr), last(nullptr), size(0) {}

template<class T>
List<T>::List(initializer_list<T> list)
{
	for (T elem : list)
	{
		push_back(elem);
	}
}

template<class T>
List<T>::List(const List& obj) : first(nullptr), last(nullptr), size(0)
{
	Node<T>* temp = obj.first;
	while (temp)
	{
		push_back(temp->value);
		temp = temp->next;
	}
}

template<class T>
List<T>& List<T>::operator=(const List& obj)
{
	if (this != &obj)
	{
		clear();
		Node<T>* temp = obj.first;
		while (temp)
		{
			push_back(temp->value);
			temp = temp->next;
		}
	}
	return *this;
}

template<typename T>
ostream& operator<<(ostream& out, const List<T>& list)
{
	for (size_t i = 0; i < list.getSize(); i++)
	{
		out << list[i] << endl; 
	}
	return out;
}

template<class T>
List<T>::~List()
{
	clear();
}

template<class T>
void List<T>::push_front(const T& value)
{
	if (size == 0)
	{
		first = last = new Node<T>(value);
	}
	else
	{
		Node<T>* newNode = new Node<T>(value);
		newNode->next = first;
		first->prev = newNode;
		first = newNode;
	}
	size++;
}

template<class T>
void List<T>::push_back(const T& value)
{
	if (size == 0 || last == nullptr) 
	{
		first = last = new Node<T>(value);
		size = 1;
	}
	else
	{
		last->next = new Node<T>(value);
		last->next->prev = last;
		last = last->next;
		size++;
	}
}

template<class T>
void List<T>::insert(const T& value, size_t index)
{
	if (index > size)
		throw "Insert index out size";

	if (index == 0)
	{
		push_front(value);
	}
	else if (index == size)
	{
		push_back(value);
	}
	else
	{
		Node<T>* pos = getNode(index - 1);
		Node<T>* newNode = new Node<T>(value);
		newNode->next = pos->next;
		pos->next->prev = newNode;
		pos->next = newNode;
		newNode->prev = pos;
		size++;
	}
}

template<class T>
void List<T>::pop_front()
{
	if (size == 0)
		throw "List is empty";
	
	if (size > 0)
	{
		Node<T>* temp = first;
		first = first->next;
		delete temp;
		size--;
		if (first != nullptr)
			first->prev = nullptr;

	}
}

template<class T>
void List<T>::pop_back()
{

	if (size == 0)
		throw "List is empty";

	if (size > 0)
	{
		if (size == 1)
		{
			delete first;
			first = last = nullptr;
		}
		else
		{
			last = last->prev;
			delete last->next;
			last->next = nullptr;
		}
		size--;
	}
}

template<class T>
void List<T>::remove(size_t index)
{

	if (index >= size)
		throw "Remove index out of size";

	if (index == 0)
	{
		pop_front();
	}
	else if (index == size - 1)
	{
		pop_back();
	}
	else
	{
		Node<T>* pos = getNode(index - 1);
		Node<T>* temp = pos->next;
		pos->next = pos->next->next;
		pos->next->prev = pos;
		delete temp;
		size--;
	}
}

template<class T>
void List<T>::erase(const T& value)
{
	Node<T>* temp = first;
	while (temp)
	{
		if (temp->value == value)
		{
			Node<T>* delet = temp;
			temp = temp->next;
			if (delet == first)
			{
				pop_front();
			}
			else if (delet == last)
			{
				pop_back();
			}
			else
			{
				delet->prev->next = delet->next;
				delet->next->prev = delet->prev;
				delete delet;
				size--;
			}
		}
		else
		{
			temp = temp->next;
		}
	}
}

template<class T>
 void List<T>::erase_if(bool(*predicate)(const T&))
{
	 Node<T>* temp = first;
	 while (temp)
	 {
		 if (predicate(temp->value))
		 {
			 Node<T>* delet = temp;
			 temp = temp->next;
			 if (delet == first)
			 {
				 pop_front();
			 }
			 else if (delet == last)
			 {
				 pop_back();
			 }
			 else
			 {
				 delet->prev->next = delet->next;
				 delet->next->prev = delet->prev;
				 delete delet;
				 size--;
			 }
		 }
		 else
		 {
			 temp = temp->next;
		 }
	 }
}

 template<class T>
 T& List<T>::front() const
 {
	 if (size == 0)
		 throw "List is empty";

	 return first->value;
 }


 template<class T>
 T& List<T>::back() const
 {
	 if (size == 0)
		 throw "List is empty";

	 return last->value;
 }

 template<class T>
T& List<T>::operator[](size_t index) const
 {
	return getNode(index)->value;
 }

template<class T>
 T List<T>::at(size_t index) const
{
	return getNode(index)->value;
}

 template<class T>
size_t List<T>::getSize() const
 {
	 return size;
 }

 template<class T>
void List<T>::print() const
{
	Node<T>* temp = first;
	while (temp)
	{
		cout << temp->value << " ";
		temp = temp->next;
	}
	cout << endl;
}

template<class T>
void List<T>::print(int x, int y) const
{
	Node<T>* temp = first;
	while (temp)
	{
		SetCursor(x, y++);
		cout << temp->value;
		temp = temp->next;
	}
	cout << endl;
}

template<class T>
void List<T>::clear()
{
	Node<T>* temp = first;
	while (temp)
	{
		first = first->next;
		delete temp;
		temp = first;
	}
	size = 0;
	last = nullptr;

}

template<class T>
int List<T>::firstIndex(const T& value)
{
	Node<T>* temp = first;
	size_t index = 0;
	while (temp)
	{
		if (temp->value == value)
		{
			return index;
		}
		temp = temp->next;
		index++;
	}
	return -1;
}


template<class T>
int List<T>::lastIndex(const T& value)
{
	Node<T>* temp = first;
	size_t index = 0;
	while (temp)
	{
		if (temp->value == value)
		{
			return size - index - 1;
		}
		temp = temp->next;
		index++;
	}
	return -1;
}

template<class T>
List<T> List<T>::operator+(const List<T>& list)
{
	List<T> newList(*this);
	Node<T>* temp = list.first;
	while (temp)
	{
		newList.push_back(temp->value);
		temp = temp->next;
	}
	return newList;
}


template<class T>
List<T> List<T>::splice(size_t index1, size_t index2)
{
	List<T> sublist;
	if (index1 > index2 || index1 >= size) return sublist;

	Node<T>* temp = getNode(index1);
	size_t currentIndex = index1;

	while (temp && currentIndex <= index2 && currentIndex < size)
	{
		sublist.push_back(temp->value);
		temp = temp->next;
		currentIndex++;
	}
	return sublist;
}
