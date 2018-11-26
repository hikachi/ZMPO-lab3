#pragma once
#include <iostream>

using namespace std;
class CMenuItem
{
public:
	string getName();
	string getCommand();


	int level;
	string zmiana;
	virtual void run() = 0;
	string command;
	string name;
};

