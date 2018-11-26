#include "pch.h"
#include "CMenuCommand.h"
#include "CCommand.h"

using namespace std;


CMenuCommand::CMenuCommand(string s_name,string s_comm,CCommand* commandPointer)
{
	pointer = commandPointer;
	name = s_name;
	command = s_comm;
}

CMenuCommand::~CMenuCommand()
{
}

void CMenuCommand::run()
{
	if (pointer) {
		pointer->runCommand();
	}
	else
	{
		cout << "Pusta komenda" << endl;

	}
}

