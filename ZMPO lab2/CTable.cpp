
#include "pch.h"
#include "CTable.h"
#include "string.h"
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

const string CTable::default_name = "default";
const int CTable::default_length = 5;
const int CTable::default_value = -1;

CTable::CTable()
{
	tab_name = default_name;
	tab_length = default_length;
	tab = new int[default_length];
	for (int x = 0; x < tab_length; x++) {
		tab[x] = default_value;
	}
	cout << "bezp: '<" << tab_name << ">'" << endl;

}

CTable::CTable(string name, int length)
{
	tab_name = name;
	tab = new int[length];
	tab_length = length;
	for (int x = 0; x < tab_length; x++) {
		tab[x] = default_value;
	}
	cout << "parametr: '<" << tab_name << ">'" << endl;
}

CTable::CTable(const CTable  &copy)
{
	tab_name = copy.tab_name + "_copy";
	tab = new int[sizeof(copy.tab)];
	tab_length = copy.tab_length;
	memcpy(tab, copy.tab, tab_length * sizeof(int));
	cout << "kopiuj: '" << copy.tab_name << "'" << endl;

}

CTable::~CTable()
{
	delete[] tab;
	cout << "Usuwam: " << tab_name << endl;
}

CTable *CTable::copyObject()
{
	return new CTable(*this);
}

string CTable::getName()
{
	return tab_name;
}

int CTable::getTabLength()
{
	return tab_length;
}

void CTable::SetName(string new_tab_name)
{
	tab_name = new_tab_name;
}

void CTable::changeLength(int new_length)
{
	int *new_tab = new int[new_length];
	for (int x = 0; x < tab_length&&x < new_length; x++)
	{
		new_tab[x] = tab[x];
	}

	tab_length = new_length;
	delete[]tab;
	tab = new_tab;
}

void CTable::setTab(int position, int set_int)
{
	tab[position] = set_int;
}

string CTable::readTab(int position)
{
	return to_string(tab[position]);
}

void CTable::copyTab(CTable src)
{
	delete tab;
	tab = new int[src.tab_length];
	memcpy(tab, src.tab, src.tab_length * sizeof(int));

}

string CTable::toString()
{
	string val;
	for (int x = 0; x < tab_length; x++) {
		val += to_string(tab[x]) + ",";
	}
	return "NAME :" + tab_name + " Length: " + to_string(tab_length) + " values: " + val;
}

