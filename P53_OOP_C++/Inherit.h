#pragma once


class A
{
private:

	int a;

protected:
	int aa;

public:
	int aaa;

	void aaaa()
	{

	}

};

class B : public A
{
public:
	void b()
	{
		//a = 10;
		aa = 10;
		aaa = 10;
	}
};


//class B : protected A
//{
//public:
//	void b()
//	{
//		//a = 10;
//		aa = 10;
//		aaa = 10;
//	}
//};
//
//
//class B : private A
//{
//public:
//	void b()
//	{
//		//a = 10;
//		aa = 10;
//		aaa = 10;
//	}
//};


