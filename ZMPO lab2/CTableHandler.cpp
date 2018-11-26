#include "pch.h"
#include "CTableHandler.h"


CTableHandler::CTableHandler()
{
	vector<CTable*> lista;
}


CTableHandler::~CTableHandler()
{
	for(int i=0;i<lista.size();i++)
	{
		delete lista[i];
	}
	lista.clear();
}

int CTableHandler::listaSize()
{
	return lista.size();
}

CTable* CTableHandler::getCTable(int index)
{
	if(index<=lista.size())
	{
		return lista[index];
	}
}
void CTableHandler::showList()
{
	for (int i = 0; i < lista.size(); i++) {
		cout << to_string(i) << ". " << lista[i]->toString() << endl;
	}
}


void CTableHandler::createDefaultCTable()
{
	lista.push_back(new CTable());
}

void CTableHandler::createCTable(CTable *obj)
{
	lista.push_back(obj);
}

void CTableHandler::changeName(int index,string name)
{
	lista[index]->SetName(name);
}

void CTableHandler::deleteAll()
{
	if (lista.size() == 0) {
		cout << "List jest pusta" << endl;
	}
	else {
		for (int i = 0; i < lista.size(); i++) {
			delete lista[i];
		}

	}
	lista.clear();
}

void CTableHandler::deleteChosen(int index)
{
	delete lista.at(index);
	lista.erase(lista.begin() + index);
}

void CTableHandler::setTab(int index,int tabIndex,int number)
{
	lista[index]->setTab(tabIndex, number);
}

void CTableHandler::copyCTable(int index)
{
	lista.push_back(lista[index]->copyObject());
}

void CTableHandler::printCTable(int index)
{
	cout<<lista[index]->toString()<<endl;
}

void CTableHandler::copyCTableTab(int dest,int src)
{
	lista[dest]->copyTab(*lista[src]);
}

