#include "pch.h"
#include "CMenuInitalizer.h"
#include "CCommands.h"
#include "CMenu.h"
#include "CTableHandler.h"

CMenuInitalizer::CMenuInitalizer()
{
}


CMenuInitalizer::~CMenuInitalizer()
{
}

void CMenuInitalizer::initMain(CMenu* main)
{
	
	CCommandOpenYT *openYT = new CCommandOpenYT();
	CMenuCommand *openYTCommand = new CMenuCommand("Open yt", "yt", openYT);
	main->addToList(openYTCommand);

	CMenu *ctableMenu = new CMenu("CTable Menu", "ctable");
	main->addToList(ctableMenu);

	CMenu *test = new CMenu("test1", "test1");
	main->addToList(test);

	CMenu *test2 = new CMenu("test2", "test2");
	test->addToList(test2);

	//CTABLE
	CTableHandler *handler = new CTableHandler();
	
	CCommandCreateDefaultCTable *createDefaultCTable = new CCommandCreateDefaultCTable(handler);
	CMenuCommand *createDefaultCTableCommand = new CMenuCommand("Create default CTable", "def", createDefaultCTable);
	ctableMenu->addToList(createDefaultCTableCommand);

	CCommandCreateCTable *createCTable = new CCommandCreateCTable (handler);
	CMenuCommand *createCTableCommand = new CMenuCommand("Create CTable", "create", createCTable);
	ctableMenu->addToList(createCTableCommand);

	CCommandShowList *showList = new CCommandShowList(handler);
	CMenuCommand *showListCommand = new CMenuCommand("Show all lists", "show", showList);
	ctableMenu->addToList(showListCommand);

	CCommandPrintCTable *printCTable = new CCommandPrintCTable(handler);
	CMenuCommand *printCTableCommand = new CMenuCommand("Print Ctable","print",printCTable);
	ctableMenu->addToList(printCTableCommand);

	CCommandChangeName *changeName = new CCommandChangeName(handler);
	CMenuCommand *changeNameCommand = new CMenuCommand("Change CTable name", "name", changeName);
	ctableMenu->addToList(changeNameCommand);
	
	CCommandSetTab *setTab = new CCommandSetTab(handler);
	CMenuCommand *setTabCommand = new CMenuCommand("Change value -index of CTable", "value", setTab);
	ctableMenu->addToList(setTabCommand);

	CCommandCopyCTable *copyCTable = new CCommandCopyCTable(handler);
	CMenuCommand *copyCTableCommand = new CMenuCommand("Copy Ctable", "copy", copyCTable);
	ctableMenu->addToList(copyCTableCommand);

	CCommandCopyCTableTab *copyCTableTab = new CCommandCopyCTableTab(handler);
	CMenuCommand *copyCTableTabCommand = new CMenuCommand("Copy CTable tab", "copytab", copyCTableTab);
	ctableMenu->addToList(copyCTableTabCommand);

	CCommandDeleteChosen *deleteChosen = new CCommandDeleteChosen(handler);
	CMenuCommand *deleteChosenCommand = new CMenuCommand("Delete selected CTable", "delete", deleteChosen);
	ctableMenu->addToList(deleteChosenCommand);

	CCommandDeleteAll *deleteAll = new CCommandDeleteAll(handler);
	CMenuCommand *deleteAllCommand = new CMenuCommand("Delete all CTables", "deleteall", deleteAll);
	ctableMenu->addToList(deleteAllCommand);

}
