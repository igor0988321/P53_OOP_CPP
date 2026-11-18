#include "Island.h"
#include <iostream>
#include <random>
#include <cmath>
#include <windows.h>

using namespace std;

int getRandom(int min, int max)
{
    static random_device rd;
    static mt19937 gen(rd());
    uniform_int_distribution<int> dist(min, max);
    return dist(gen);
}

void setColor(int textColor, int bgColor)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, (bgColor << 4) | textColor);
}

Animal::Animal(int startX, int startY)
{
    x = startX;
    y = startY;
    live = true;
}

void Animal::Step(bool canMove)
{
    while (true)
    {
        int dx = getRandom(-1, 1);
        int dy = getRandom(-1, 1);

        if (!canMove && dx == 0 && dy == 0) continue;

        int nx = x + dx;
        int ny = y + dy;

        if (nx >= 0 && nx < MAP_SIZE && ny >= 0 && ny < MAP_SIZE)
        {
            x = nx;
            y = ny;
            break;
        }
    }
}

Rabbit::Rabbit(int startX, int startY) : Animal(startX, startY) {}

void Rabbit::act(vector<Rabbit>& newRabbit)
{
    if (!live)
    {
        return;
    }

    Step(true);

    if (getRandom(0, 99) < 20)
    {
        newRabbit.push_back(Rabbit(x, y));
    }
}

template <typename T>
int findNear(const vector<T>& list, int x, int y)
{
    for (size_t i = 0; i < list.size(); i++)
    {
        if (list[i].live && abs(list[i].x - x) <= 1 && abs(list[i].y - y) <= 1 && !(list[i].x == x && list[i].y == y))
        {
            return (int)i;
        }
    }
    return -1;
}

bool tryEat(vector<Rabbit>& rabbit, int x, int y, double& eat, bool eatenMap[MAP_SIZE][MAP_SIZE])
{
    for (size_t i = 0; i < rabbit.size(); i++)
    {
        if (rabbit[i].live && rabbit[i].x == x && rabbit[i].y == y)
        {
            rabbit[i].live = false;
            eat += 1.0;
            eatenMap[x][y] = true;
            return true;
        }
    }
    return false;
}

FemaleWolf::FemaleWolf(int startX, int startY) : Animal(startX, startY) { eat = 1.0; }

void FemaleWolf::act(vector<Rabbit>& rabbits, bool eatenMap[MAP_SIZE][MAP_SIZE])
{
    if (!live)
    {
        return;
    }

    int step = findNear(rabbits, x, y);
    if (step != -1)
    {
        x = rabbits[step].x;
        y = rabbits[step].y;
        rabbits[step].live = false;
        eat += 1.0;
        eatenMap[x][y] = true;
    }
    else
    {
        Step(false);
        if (!tryEat(rabbits, x, y, eat, eatenMap))
        {
            eat -= 0.1;
        }
    }

    if (eat <= 0.001)
    {
        live = false;
    }
}

MaleWolf::MaleWolf(int startX, int startY) : Animal(startX, startY) { eat = 1.0; }

void MaleWolf::act(vector<Rabbit>& rabbits, vector<FemaleWolf>& females,
    vector<FemaleWolf>& newFemales, vector<MaleWolf>& newMales,
    bool eatenMap[MAP_SIZE][MAP_SIZE])
{
    if (!live)
    {
        return;
    }

    int stepRabbit = findNear(rabbits, x, y);
    int stepFemale = findNear(females, x, y);

    if (stepRabbit != -1)
    {
        x = rabbits[stepRabbit].x;
        y = rabbits[stepRabbit].y;
        rabbits[stepRabbit].live = false;
        eat += 1.0;
        eatenMap[x][y] = true;
    }
    else if (stepFemale != -1)
    {
        x = females[stepFemale].x;
        y = females[stepFemale].y;

        if (!tryEat(rabbits, x, y, eat, eatenMap))
        {
            if (getRandom(0, 1) == 0)
            {
                newFemales.push_back(FemaleWolf(x, y));
            }
            else
            {
                newMales.push_back(MaleWolf(x, y));
            }
            eat -= 0.1;
        }
    }
    else
    {
        Step(false);
        if (!tryEat(rabbits, x, y, eat, eatenMap))
        {
            eat -= 0.1;
        }
    }

    if (eat <= 0.001)
    {
        live = false;
    }
}

template<typename T>
void update(vector<T>& list, const vector<T>& babi)
{
    vector<T> next;
    for (size_t i = 0; i < list.size(); i++)
    {
        if (list[i].live)
        {
            next.push_back(list[i]);
        }
    }
    for (size_t i = 0; i < babi.size(); i++)
    {
        next.push_back(babi[i]);
    }
    list = next;
}

void print(const vector<Rabbit>& rabbits, const vector<FemaleWolf>& females,
    const vector<MaleWolf>& males, const bool Map[MAP_SIZE][MAP_SIZE])
{
    static int step = 0;

    COORD coord = { 0, 0 };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

    char map[MAP_SIZE][MAP_SIZE];
    for (int i = 0; i < MAP_SIZE; i++)
        for (int j = 0; j < MAP_SIZE; j++)
            map[i][j] = '.';

    for (size_t i = 0; i < rabbits.size(); i++)
        if (rabbits[i].live && map[rabbits[i].x][rabbits[i].y] == '.')
            map[rabbits[i].x][rabbits[i].y] = 'R';

    for (size_t i = 0; i < females.size(); i++)
        if (females[i].live)
            map[females[i].x][females[i].y] = 'F';

    for (size_t i = 0; i < males.size(); i++)
        if (males[i].live)
            map[males[i].x][males[i].y] = 'M';

    int ateCount = 0;
    for (int i = 0; i < MAP_SIZE; i++)
        for (int j = 0; j < MAP_SIZE; j++)
            if (Map[i][j]) ateCount++;

    for (int i = 0; i < MAP_SIZE; i++)
    {
        for (int j = 0; j < MAP_SIZE; j++)
        {
            char cell = map[i][j];

            if (Map[i][j])          setColor(12, 0);
            else if (cell == 'R')   setColor(10, 8);
            else if (cell == 'F')   setColor(13, 8);
            else if (cell == 'M')   setColor(11, 8);
            else                    setColor(7, 8);

            cout << "[" << cell << "]";
        }

        setColor(7, 0);
        cout << "    ";
        if (i == 0) cout << "Alive rabbits: " << rabbits.size() << "    ";
        if (i == 1) cout << "Female wolves: " << females.size() << "    ";
        if (i == 2) cout << "Male wolves:   " << males.size() << "    ";
        if (i == 4) cout << "R - rabbit";
        if (i == 5) cout << "F - female wolf";
        if (i == 6) cout << "M - male wolf";
        if (i == 7) cout << ". - empty field";
        if (i == 9) cout << "Step: " << step << "    ";

        cout << "\n";
    }

    setColor(7, 0);
    cout << "\n";
    if (ateCount > 0)
    {
        setColor(12, 0);
        cout << "Rabbits are eaten when a wolf catches them! (Eaten: " << ateCount << ")      \n";
    }
    else
    {
        cout << "Rabbits are eaten when a wolf catches them.                         \n";
    }
    setColor(7, 0);

    step++;
}

void start(int rCount, int fCount, int mCount)
{
    vector<Rabbit> rabbits;
    vector<FemaleWolf> females;
    vector<MaleWolf> males;
    bool Map[MAP_SIZE][MAP_SIZE] = { false };

    for (int i = 0; i < rCount; i++)
    {
        rabbits.push_back(Rabbit(getRandom(0, MAP_SIZE - 1), getRandom(0, MAP_SIZE - 1)));
    }
    for (int i = 0; i < fCount; i++)
    {
        females.push_back(FemaleWolf(getRandom(0, MAP_SIZE - 1), getRandom(0, MAP_SIZE - 1)));
    }
    for (int i = 0; i < mCount; i++)
    {
        males.push_back(MaleWolf(getRandom(0, MAP_SIZE - 1), getRandom(0, MAP_SIZE - 1)));
    }

    while (true)
    {
        print(rabbits, females, males, Map);

        if (rabbits.empty() && females.empty() && males.empty())
        {
            break;
        }

        Sleep(400);

        for (int i = 0; i < MAP_SIZE; i++)
        {
            for (int j = 0; j < MAP_SIZE; j++)
            {
                Map[i][j] = false;
            }
        }

        vector<Rabbit> newRabbits;
        vector<FemaleWolf> newFemales;
        vector<MaleWolf> newMales;

        for (size_t i = 0; i < rabbits.size(); i++)
        {
            rabbits[i].act(newRabbits);
        }
        for (size_t i = 0; i < females.size(); i++)
        {
            females[i].act(rabbits, Map);
        }
        for (size_t i = 0; i < males.size(); i++)
        {
            males[i].act(rabbits, females, newFemales, newMales, Map);
        }

        update(rabbits, newRabbits);
        update(females, newFemales);
        update(males, newMales);
    }
}