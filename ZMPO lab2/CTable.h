#pragma once
#include "pch.h"
#include "CTable.h"
#include "string.h"
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;
class CTable
{
public:

	static const string default_name;
	static const int default_length;
	static const int default_value;

	CTable();
	CTable(string tab_name, int tab_length);
	CTable(const CTable &copy);
	~CTable();
	CTable * copyObject();

	void SetName(string new_tab_name);
	void changeLength(int new_length);
	void setTab(int position, int set_int);
	void copyTab(CTable src);
	string readTab(int position);
	string toString();
	string getName();

	int getTabLength();



private:
	string  tab_name;
	int* tab;
	int tab_length;

}
;

