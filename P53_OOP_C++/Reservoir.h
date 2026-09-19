#pragma once

#include <iostream>

using namespace std;

enum class ReservoirType
{
	Ocean, Sea, Lake, River, Pond, Luzha, Pool
};

class Reservoir
{
	static const int size = 100;
	char name[size];
	ReservoirType type;
	double width;
	double length;
	double maxDepth;



public:
	Reservoir() : type(ReservoirType::Pond), width(0.0), length(0.0), maxDepth(0.0)
	{
		strncpy(name, " ", size - 1);
		name[size - 1] = '\0';
	}

	explicit Reservoir(const char* reservoirName, ReservoirType type, double width, double length, double maxDepth) : type(type), width(width), length(length), maxDepth(maxDepth)
	{
		strncpy(name, reservoirName, size - 1);
		name[size - 1] = '\0';
	}

	const char* getName() const
	{
		return name;
	}

	double getWidth() const
	{
		return width;
	}

	double getLength() const
	{
		return length;
	}

	double getMaxDepth() const
	{
		return maxDepth;
	}

	double getVolume() const
	{
		return width * length * maxDepth;
	}

	double getArea() const
	{
		return width * length;
	}


	void display() const
	{
		cout << "Водойми" << "Name" << name << endl;

		switch (type)
		{
		case ReservoirType::Ocean: cout << "Okean"; break;
		case ReservoirType::Sea: cout << "More"; break;
		case ReservoirType::Lake: cout << "Ozero"; break;
		case ReservoirType::River: cout << "Richka"; break;
		case ReservoirType::Pond: cout << "Stavok"; break;
		case ReservoirType::Pool: cout << "Basein"; break;
		}

		cout << "Ширина" << width << "m"
			<< "Довжина" << length << "m"
			<< "Максимальна глубина" << maxDepth << "m"
			<< "Площа" << getArea() << "m2"
			<< "Приблизний об*єм" << getVolume() << "kub";

	}

};

