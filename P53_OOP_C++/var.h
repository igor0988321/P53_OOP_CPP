#pragma once

#include <iostream>

using namespace std;


enum class TYPE
{
	INT, DOUDLE, STRING
};

class var
{
	TYPE type;
	void* value;
};

