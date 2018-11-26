#include "pch.h"
#include "CCommands.h"
#include "CCommand.h"
#include <string>
#include <iostream>
#include "CTable.h"
#include <vector>
#include  <Windows.h>


using namespace std;




CCommandShowList::CCommandShowList(CTableHandler* handler)
{
	tableHandler = handler;
}

void CCommandShowList::runCommand()
{
	tableHandler->showList();
}
//CREATE DEF
CCommandCreateDefaultCTable::CCommandCreateDefaultCTable(CTableHandler* handler)
{
	tableHandler = handler;
}

void CCommandCreateDefaultCTable::runCommand()
{
	tableHandler->createDefaultCTable();
}
//CREATE CTABLE
CCommandCreateCTable::CCommandCreateCTable(CTableHandler* handler)
{
	tableHandler = handler;
}

void CCommandCreateCTable::runCommand()
{
	string CTable_name;
	int CTable_length;
	cout << "Wprowadz nazwe : " << endl;
	cin >> CTable_name;
	cout << "Podaj dlugosc tablicy : " << endl;
	cin >> CTable_length;
	if (cin.fail()) {
		cout << "Wrong input! Exptected INT" << endl;
		cin.clear();
		cin.ignore();
		return;
	}
	if (CTable_length <= 0) {
		cout << "Wartosc <0" << endl;
	}
	else {
		CTable *object = new CTable(CTable_name, CTable_length);
		tableHandler->createCTable(object);
	}
}

//CHANGE NAME
CCommandChangeName::CCommandChangeName(CTableHandler* handler)
{
	tableHandler = handler;
}

void CCommandChangeName::runCommand()
{
	string CTable_name;
	int position;
	cout << "Wybierz CTable" << endl;
	cin >> position;

	if (cin.fail()) {
		cout << "Wrong input! Exptected INT" << endl;
		cin.clear();
		cin.ignore();
		return;
	}

	if (position >= tableHandler->listaSize() || position < 0) {
		cout << "Zly zakres" << endl;
	}
	else {
		cout << "Podaj nowa nazwe: " << endl;
		cin >> CTable_name;
		tableHandler->changeName(position, CTable_name);
	}
}

//DELETE ALL
CCommandDeleteAll::CCommandDeleteAll(CTableHandler* handler)
{
	tableHandler = handler;
}

void CCommandDeleteAll::runCommand()
{
	tableHandler->deleteAll();
}

//DELETE CHOSEN
CCommandDeleteChosen::CCommandDeleteChosen(CTableHandler* handler)
{
	tableHandler = handler;
}

void CCommandDeleteChosen::runCommand()
{
	int position;
	cout << "Ktory usunac?" << endl;
	cin >> position;
	
	if (cin.fail()) {
		cout << "Wrong input! Exptected INT" << endl;
		cin.clear();
		cin.ignore();
		return;
	}

	if (position >= 0 && position < tableHandler->listaSize()) {
		tableHandler->deleteChosen(position);
	}
	else {
		cout << "Zly zakres" << endl;
	}
}

//SET TAB
CCommandSetTab::CCommandSetTab(CTableHandler* handler)
{
	tableHandler = handler;
}

void CCommandSetTab::runCommand()
{
	int position;
	int lista_position;
	int number;
	cout << "Podaj ktora CTable" << endl;
	cin >> lista_position;
	
	if (cin.fail()) {
		cout << "Wrong input! Exptected INT" << endl;
		cin.clear();
		cin.ignore();
		return;
	}

	if (lista_position >= tableHandler->listaSize() || lista_position < 0) {
		cout << "Zly zakres" << endl;
	}
	else {
		cout << "Podaj ktora pozycja CTable[]" << endl;
		cin >> position;
		
		if (cin.fail()) {
			cout << "Wrong input! Exptected INT" << endl;
			cin.clear();
			cin.ignore();
			return;
		}

		if (position >= tableHandler->getCTable(lista_position)->getTabLength() || position < 0) {
			cout << "Zly zakres" << endl;
		}
		else {
			cout << "Podaj co wpisac" << endl;
			cin >> number;
			
			if (cin.fail()) {
				cout << "Wrong input! Exptected INT" << endl;
				cin.clear();
				cin.ignore();
				return;
			}

			tableHandler->setTab(lista_position, position, number);
		}
	}
}

//COPY CTABLE
CCommandCopyCTable::CCommandCopyCTable(CTableHandler* handler)
{
	tableHandler = handler;
}

void CCommandCopyCTable::runCommand()
{
	int position;
	cout << "Podaj ktora CTable skopiowac" << endl;
	cin >> position;
	if (cin.fail()) {
		cout << "Wrong input! Exptected INT" << endl;
		cin.clear();
		cin.ignore();
		return;
	}

	if (position >= tableHandler->listaSize() || position < 0) {
		cout << "Zly zakres" << endl;
	}
	else {
		
		tableHandler->copyCTable(position);
	}
}

//PRINT CTABLE
CCommandPrintCTable::CCommandPrintCTable(CTableHandler* handler)
{
	tableHandler = handler;
}

void CCommandPrintCTable::runCommand()
{
	int position;
	cout << "Podaj ktora CTable wyswietlic" << endl;
	cin >> position;
	if (cin.fail()) {
		cout << "Wrong input! Exptected INT" << endl;
		cin.clear();
		cin.ignore();
		return;
	}
	if (position >= tableHandler->listaSize() || position < 0) {
		cout << "Zly zakres" << endl;
	}
	else {
		tableHandler->printCTable(position);
	}
}


//COPY CTABLE TAB
CCommandCopyCTableTab::CCommandCopyCTableTab(CTableHandler* handler)
{
	tableHandler = handler;
}

void CCommandCopyCTableTab::runCommand()
{
	int CTableSrc;
	int CTableDest;
	cout << "Podaj zrodlo tablicy CTable" << endl;
	cin >> CTableSrc;

	if (cin.fail()) {
		cout << "Wrong input! Exptected INT" << endl;
		cin.clear();
		cin.ignore();
		return;
	}

	if (CTableSrc >= tableHandler->listaSize() || CTableSrc < 0) {
		cout << "Zly zakres" << endl;
	}
	else {
		cout << "Podaj Ctable gdzie skopiowac tablice" << endl;
		cin >> CTableDest;

		if (cin.fail()) {
			cout << "Wrong input! Exptected INT" << endl;
			cin.clear();
			cin.ignore();
			return;
		}

		if (CTableDest >= tableHandler->listaSize() || CTableDest < 0) {
			cout << "Zly zakres" << endl;
		}
		else {
			tableHandler->copyCTableTab(CTableDest, CTableSrc);
		}
	}
}

void CCommandOpenYT::runCommand()
{
	ShellExecute(0, 0, L"http://www.google.com", 0, 0, SW_SHOW);
	
}
