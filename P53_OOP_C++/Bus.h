#pragma once

using namespace std;

class People
{
	int arrivedtime;

public:
	People(int temp) : arrivedtime(temp) {}
	int gettime(int temp) const
	{
		return temp - arrivedtime;
	}
};



class Bus
{
	int freeSeats;

public:
	Bus(int maxCapacity = 15)
	{
		freeSeats = rand() % (maxCapacity + 1);
	}

	int getFreeSeats() const
	{
		return freeSeats;
	}
};


int randominterval(double mInterval)
{
	double u = (rand() + 1.0) / (RAND_MAX + 2.0);
	double interval = -mInterval * log(u);
	return max(1, (int)round(interval));

}


double roundDecimal(double val)
{
	return round(val * 10.0) / 10.0;
}