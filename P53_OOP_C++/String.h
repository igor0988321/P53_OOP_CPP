#pragma once
#include <iostream>

using namespace std;

class String
{

protected:
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
		strcpy_s(str, size + 1, obj.str);
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

	void clear()
	{
		delete[] str;
		size = 0;
		str = new char[1];
		str[0] = '\0';
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

	int GetSize() const { return size; }
	const char* GetCStr() const { return str; }
		
};



ostream& operator<<(ostream& str, const String& obj)
{
	if (obj.str != nullptr) {
		str << obj.str;
	}
	return str;
}


class BitString : public String
{
	bool  isBit(const char* s) const
	{
		if (s == nullptr)
		{
			return;
		}
		for (size_t i = 0; s[i]!= '\0'; i++)
		{
			if (s[i] != '0' && s[i] != '1')
			{
				return false;
			}
		}
		return true;
	}

public:

	BitString() : String() {}

	BitString(const char* str) : String()
	{
		if (isBit(str))
		{
			delete[] this->str;
			this->size = strlen(str);
			this->str = new char[this->size + 1];
			strcpy_s(this->str, this->size + 1, str);
		}
		else
		{
			clear();
		}
	}

	BitString(const BitString& obj) : String(obj) {}

	~BitString() {}

	BitString& operator=(const BitString& obj)
	{
		String::operator=(obj);
		return *this;
	}

	void change()
	{
		if (size == 0)
		{
			return;
		}
		for (size_t i = 0; i < size; i++)
		{
			if (str[i] == '0')
			{
				str[i] = '1';
			}
			else
			{
				str[i] = '0';
			}
		}

		int temp = 1;
		for (int i = size - 1; i >= 0; i--)
		{
			if (temp == 0) break;

			if (str[i] == '1')
			{
				str[i] = '0';
			}
			else
			{
				str[i] = '1';
				temp = 0;
			}
		}
	}



	bool operator==(const BitString& obj) const
	{
		return String::operator==(obj);
	}


	bool operator!=(const BitString& obj) const
	{
		return String::operator!=(obj);
	}
};