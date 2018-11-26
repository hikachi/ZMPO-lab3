#pragma once

#include "CTable.h"
#include <vector>


using namespace std;

class CTableHandler
{
public:
	CTableHandler();
	~CTableHandler();
	int listaSize();
	CTable* getCTable(int index);
	void showList();
	void createDefaultCTable();
	void createCTable(CTable *obj);
	void changeName(int index,string name);
	void deleteAll();
	void deleteChosen(int index);
	void setTab(int index, int tabIndex, int number);
	void copyCTable(int index);
	void printCTable(int index);
	void copyCTableTab(int dest, int src);
	void printCTable();
	void copyCTableTab();



private:
	 vector<CTable*> lista;
};

