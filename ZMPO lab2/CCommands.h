#pragma once
#include "CCommand.h"
#include <string>
#include "CMenuCommand.h"
#include "CTable.h"
#include <vector>
#include "CTableHandler.h"
using namespace std;


class CCommandOpenYT:public CCommand
{
public:
	void runCommand();
};

class CCommandShowList: public CCommand
{
public:
	CCommandShowList(CTableHandler *handler);
	CTableHandler *tableHandler;
	void runCommand() ;
};

class CCommandCreateDefaultCTable :public CCommand
{
public :
	CCommandCreateDefaultCTable(CTableHandler *handler);
	CTableHandler *tableHandler;
	void runCommand();
};

class CCommandCreateCTable:public CCommand
{
public:
	CCommandCreateCTable(CTableHandler *handler);
	CTableHandler *tableHandler;
	void runCommand();
};

class CCommandChangeName:public CCommand
{
public:
	CCommandChangeName(CTableHandler *handler);
	CTableHandler *tableHandler;
	void runCommand();
};

class CCommandDeleteAll:public CCommand
{
public:
	CCommandDeleteAll(CTableHandler *handler);
	CTableHandler *tableHandler;
	void runCommand();
};

class CCommandDeleteChosen:public CCommand
{
public:
	CCommandDeleteChosen(CTableHandler *handler);
	CTableHandler *tableHandler;
	void runCommand();
};

class CCommandSetTab:public CCommand
{
public:
	CCommandSetTab(CTableHandler *handler);
	CTableHandler *tableHandler;
	void runCommand();
};

class CCommandCopyCTable:public CCommand
{
public:
	CCommandCopyCTable(CTableHandler *handler);
	CTableHandler *tableHandler;
	void runCommand();
};

class CCommandPrintCTable:public CCommand
{
public:
	CCommandPrintCTable(CTableHandler *handler);
	CTableHandler *tableHandler;
	void runCommand();
};

class CCommandCopyCTableTab:public CCommand
{
public:
	CCommandCopyCTableTab(CTableHandler *handler);
	CTableHandler *tableHandler;
	void runCommand();
};