#pragma once

#include <iostream>

using namespace std;

class Area
{
	static int count;

public:

	static double triangleArea(double b, double height);

	static double triangleArea(double a, double b, double c);

	static double rectangleArea(double width, double height);

	static double squareArea(double a);

	static double rombArea(double a1, double a2);

	static int getCount();

};

int Area::count = 0;


double Area::triangleArea(double b, double height)
{
	count++;
	return 0.5 * b * height;
}


double Area::triangleArea(double a, double b, double c)
{
	count++;
	double p = (a + b + c) / 2.0;
	return sqrt(p * (p - a) * (p - b) * (p - c));

}



double Area::rectangleArea(double width, double height)
{
	count++;
	return width * height;

}

double Area::squareArea(double a)
{
	count++;
	return a * a;
}

double Area::rombArea(double a1, double a2)
{
	count++;
	return 0.5 * a1 * a2;

}

int Area::getCount()
{
	return count;
 }