#pragma once
#include "CMenuItem.h"
#include "CCommand.h"
using namespace std;
class CMenuCommand:public CMenuItem 	
{
public:
	CMenuCommand(string s_name, string s_comm, CCommand * commandPointer);
	~CMenuCommand();
	void run();
	CCommand* pointer;

};

