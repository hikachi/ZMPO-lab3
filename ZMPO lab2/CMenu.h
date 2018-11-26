#pragma once
#include "CMenuItem.h"
#include <vector>
#include <string>

using namespace std;
class CMenu : public CMenuItem
{
public:
	CMenu(string name,string command);
	~CMenu();
	void run();
	vector<CMenuItem*> getLista();
	
	
	void addToList(CMenuItem* pointer);
	bool findAndRun();
	
private:
	void showMenu();
	vector<CMenuItem*> list;
	
		
};

