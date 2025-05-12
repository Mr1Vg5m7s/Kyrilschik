#pragma once
#include"string.h"
#include"List.h"
#include"BTree.h"

using namespace std;

class Protocol
{
	String numTZ;
	String data;
	String tag;
	int summa;
	bool isPay = false;
public:
	String getNumTZ()
	{
		return numTZ;
	}

	friend istream& operator>>(istream& in, Protocol* p);
	friend ofstream& operator<<(ofstream& out,const Protocol* p);
};
istream& operator>>(istream& in, Protocol* p)
{
	cout << "NUM TZ  : "; cin >> p->numTZ;
	cout << "Data    : "; cin >> p->data;
	cout << "Tag     : "; cin >> p->tag;
	cout << "Summa   : "; cin >> p->summa;
	return in;
}
 ofstream& operator<<(ofstream& out, const Protocol* p)
{
	 out << "NUM TZ  : " << p->numTZ << endl;
	 out << "Data    : " << p->data << endl;
	 out << "Tag     : " << p->tag << endl;
	 out << "Summa   : " << p->summa << endl;
}

class BasePolice
{
	BTree < String, List <Protocol*>> base;

public:
	void addProtocol();
	void printAll();
	void printDiapozon(String beginNum, String endNum);
	void payProtocol();
};

void BasePolice::addProtocol()
{
	Protocol* p = new Protocol;
	cin >> p;

	List<Protocol*>* list = base.getValue(p->getNumTZ());
	if (list == nullptr)
	{
		List<Protocol*> newList;
		newList.push_back(p);
		base.push_r(p->getNumTZ(), newList);
		cout << "New protocol added" << endl;
	}
	else
	{
		list->push_back(p);
	}
	system("pause");
}

void BasePolice::printAll()
{
}

void BasePolice::printDiapozon(String beginNum, String endNum)
{

}

void BasePolice::payProtocol()
{

}
