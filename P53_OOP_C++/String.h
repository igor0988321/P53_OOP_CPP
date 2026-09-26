#pragma once
#include <iostream>

using namespace std;

class String
{
	char* str;
	int size;

public:

	String()
	{
		size = 0;
		str = new char[1];
		str[0] = '\0';
	}

	String(const char* str)
	{
		size = strlen(str);
		this->str = new char[size + 1];
		strcpy(this->str, str);
	}

	String(const String& obj)
	{
		size = obj.size;
		str = new char[size + 1];
		strcpy(str, obj.str);
	}

	~String()
	{
		delete[] str;
	}

	String reSize()
	{
		size = 50;
		delete[] str;
		str = new char[size];
		return *this;
	}

	String& operator=(const String& obj)
	{
		if (this == &obj)
		{
			return *this;
		}

		delete[] str;

		size = obj.size;
		str = new char[size + 1];
		strcpy_s(str, size + 1, obj.str);
		return *this;
	}

	char& operator[](int index)
	{
		return str[index];
	}

	String operator+(const String& obj) const
	{
		int newsize = this->size + obj.size;
		char* newstr = new char[newsize + 1];

		strcpy_s(newstr, newsize + 1, this->str);
		strcat_s(newstr, newsize + 1, obj.str);
		String res(newstr);
		delete[] newstr;
		return res;
	}

	String& operator+=(const String& obj)
	{
		*this = *this + obj;
		return *this;
	}

	bool operator==(const String& obj) const
	{
		if (strcmp(this->str, obj.str) == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool operator!=(const String& obj) const
	{
		if (*this == obj)
		{
			return false;
		}
		else
		{
			return true;
		}
	}

	bool operator<(const String& obj) const
	{
		if (strcmp(this->str, obj.str) < 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}


	bool operator>(const String& obj) const
	{
		if (strcmp(this->str, obj.str) > 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	friend ostream& operator<<(ostream& os, const String& obj);
		
};



ostream& operator<<(ostream& str, const String& obj)
{
	if (obj.str != nullptr) {
		str << obj.str;
	}
	return str;
}