#pragma once
#include <vector>

const int MAP_SIZE = 20;

class Animal
{
public:
	int x;
	int y;
	bool live;

	Animal(int startX, int startY);
	void Step(bool canMove);
};

class Rabbit : public Animal
{
public:
	Rabbit(int startX, int startY);
	void act(std::vector<Rabbit>& newRabbit);
};

class FemaleWolf : public Animal
{
public:
	double eat;

	FemaleWolf(int startX, int startY);
	void act(std::vector<Rabbit>& rabbit, bool eatenMap[MAP_SIZE][MAP_SIZE]);
};

class MaleWolf : public Animal
{
public:
	double eat;

	MaleWolf(int startX, int startY);
	void act(std::vector<Rabbit>& rabbit, std::vector<FemaleWolf>& females,
		std::vector<FemaleWolf>& newFemale, std::vector<MaleWolf>& newMale,
		bool eatenMap[MAP_SIZE][MAP_SIZE]);
};

void print(const std::vector<Rabbit>& rabbits, const std::vector<FemaleWolf>& females,
	const std::vector<MaleWolf>& males, const bool Map[MAP_SIZE][MAP_SIZE]);

void start(int rCount, int fCount, int mCount);
