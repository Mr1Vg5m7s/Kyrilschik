#include<iostream>
#include<Windows.h>
#include<iomanip>
#include<fstream>
#include<algorithm>

#include"BTree.h"
#include"Array.h"
#include"string.h"
#include"List.h"
#include"Акфсешщт.h"
#include"Time.h"
#include"var.h"
#include "Queue.h"
#include"ForwardList.h"
#include"BasePolice.h"
#include"Relation.h"
#include"Inherit.h"
#include"Passport.h"
#include"Animal.h"
#include "Sh.h"
#include"WarofWorld.h"
#include"Logger.h"
#include "System.h"



using namespace std;

void starLine(int count = 10, char symbol = '*')
{
	for (size_t i = 0; i < count; i++)
	{
		cout << symbol;
	}
	cout << endl;
}

double avg(int a, int b, int c)
{
	return (a + b + c) / 3.;
}

template<class T>
void printArray(T* arr, int size)
{
	for (size_t i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}


void setArray(int arr[], int size, int min, int max)
{
	for (size_t i = 0; i < size; i++)
	{
		arr[i] = rand() % (max - min + 1) + min;
	}
}

/*void setArray(int arr[], int size, int min, int max)
{
	for (size_t i = 0; i < size; i++)
	{
		arr[i] = rand() % (max - min + 1) + min;
	}
}*/

template<class T>
void bubbleSort(T arr[], int size)
{
	for (size_t i = 0; i < size - 1; i++)
	{
		for (size_t j = 0; j < size - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(arr[j], arr[j + 1]);
			}
		}
	}
}

bool isPrime(int n)
{
	for (size_t i = 2; i < n; i++)
	{
		if (n % i == 0)
			return false;
	}
	return true;
}


template<class T>
T maxValueArray(T arr[], int size)
{
	T maxElem = arr[0];
	for (size_t i = 0; i < size; i++)
	{
		if (arr[i] > maxElem)
		{
			maxElem = arr[i];
		}
	}
	return maxElem;
}


template<class T>
int lineSearch(T arr[], int size, T key)
{
	for (size_t i = 0; i < size; i++)
	{
		if (arr[i] == key)
		{
			return i;
		}
	}
	return -1;
}
void Swap(int a, int b)
{
	int t = a;
	a = b;
	b = t;
	cout << a << " " << b << endl;
}


template<class T>
void addElemArray(T*& arr, int& size, T elem)
{
	T* temp = new T[size + 1];
	for (size_t i = 0; i < size; i++)
	{
		temp[i] = arr[i];
	}
	temp[size] = elem;
	delete arr;
	size++;
	arr = temp;
}

template<class T>
void delElemArray(T*& arr, int& size)
{
	T* temp = new T[size - 1];
	for (size_t i = 0; i < size-1; i++)
	{
		temp[i] = arr[i];
	}
	delete arr;
	size--;
	arr = temp;
}

template<class T>
void addElemArray(T*& arr, int& size, int index, T elem) {
	T* temp = new T[size + 1];
	for (size_t i = 0; i < index; i++)
	{
		temp[i] = arr[i];
	}
	temp[index] = elem;
	for (size_t i = index; i < size; i++)
	{
		temp[i+1] = arr[i];
	}
	delete arr;
	size++;
	arr = temp;
}


template<class T>
void delElemArray(T*& arr, int& size, int index) {
	T* temp = new T[size - 1];
	for (size_t i = 0; i < index; i++)
	{
		temp[i] = arr[i];
	}
	for (size_t i = index+1; i < size; i++)
	{
		temp[i - 1] = arr[i];
	}
	delete arr;
	size--;
	arr = temp;
}

template<class T>
void printArray2D(T** arr, int row, int col)
{
	for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0; j < col; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}


void setArray2D(int** arr, int row, int col, int min = 0, int max = 9)
{
	for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0; j < col; j++)
		{
			arr[i][j] = rand() % (max - min + 10) + min;
		}
	}
}
template<class T>
T** createArray2D(int row, int col)
{
	if (row > 0 && col > 0)
	{
		T** p = new T* [row];
		for (size_t i = 0; i < row; i++)
		{
			p[i] = new T[col];
		}
		return p;
	}
	else {
		cout << "error";
	}
}

template<class T>
void createArray2D(T**& p, int row, int col)
{
	p = createArray2D<T>(row, col);
}

template<class T>
void AddRadokto2D(T**& p, int& row, int col)
{
	T** temp = new T * [row+1];
	for (size_t i = 0; i < row; i++)
	{
		temp[i] = p[i];
	}
	temp[row] = new T[col]{0};
	delete p;
	row++;
	p = temp;
}

template<class T>
void delRadokto2D(T**& p, int& row)
{
	T** tempM = new T * [row - 1];
	for (size_t i = 0; i < row-1; i++)
	{
		tempM[i] = p[i];
	}
	delete p[row - 1];
	delete p;
	row--;
	p = tempM;
}

template<class T>
void AddRadoktoStart2D(T**& p, int& row, int col)
{
	T** tempS = new T * [row + 1];
	tempS[0] = new T[col]{ 0 };
	for (size_t i = 0; i < row; i++)
	{
		tempS[i+1] = p[i];
	}
	delete p;
	row++;
	p = tempS;
}

template<class T>
void AddRadoktoINDEX2D(T**& p, int& row, int col, int index)
{
	T** temp = new T * [row + 1];
	for (size_t i = 0; i < index; i++)
	{
		temp[i] = p[i];
	}
	temp[index] = new T[col]{ 0 };
	for (size_t i = index; i < row; i++)
	{
		temp[i + 1] = p[i];
	}
	delete p;
	row++;
	p = temp;
}
template<class T>
void delRadoktoINDEX2D(T**& p, int& row, int col, int index) {
	T** temp = new T*[size - 1];
	for (size_t i = 0; i < index; i++)
	{
		temp[i] = p[i];
	}
	for (size_t i = index + 1; i < row; i++)
	{
		temp[i - 1] = p[i];
	}
	delete p;
	row--;
	p = temp;
}
template<class T>
void addStolbtoINDEX2D(T**& p, int& row, int col, int index=0)
{
	for (size_t i = 0; i < row; i++)
	{
		addElemArray(p[i], col, 0, index);
		col--;
		/*T* temp = new T[col + 1];
		for (size_t j = 0; j < index; i++)
		{
			temp[j] = p[i][j];
		}
		temp[index] = 0;
		for (size_t j = index; j < col; i++)
		{
			temp[j + 1] = p[i][j];
		}
		delete p[i];
		p[i] = temp;*/
	}
	col++;
}
/*
void division(int a, int b, FileLogger* flog)
{
	if (b == 0)
	{
		flog->logError("Деление на ноль невозможно!");
		return;
	}

	cout << (double)a / b << endl;
}*/

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout.setf(ios::boolalpha);
	//0960600380


	system("cls");
	Computer* pc = new Computer("PC", 16, "NVIDIA RTX 3060");
	cout << pc << endl;
	cout << endl;
	/////
	/*PersonalComputer* ppc = new PersonalComputer("PPc", 32, "NVIDIA RTX 3080", true, "Realtek", "Logitech");
	ppc->info();
	cout << endl;
	/////
	Laptop* lp = new Laptop("Laptop", 8, "NVIDIA RTX 2060", 15, 5, 2);
	lp->info();
	cout << endl;
	/////
	PortServer* ps = new PortServer("PortServer45", 16, "NVIDIA RTX 5090", 16, 900, 40, 20, 4, "626444", true, "IP333", "Windows 10");
	ps->info();
	cout << endl;*/



	//Animal* c = new Cat("Tom", 3);
	//war.game();

	//int a = 9;
	//int b = 7;
	//ConsoleLogger* clog = new ConsoleLogger();

	//FileLogger* flog = new FileLogger("log.txt");
	//division(a, b, flog);

	//Dark* Me = new Skeleton(1, 0);
	//cout << Me << endl;

	/*
	Circle c("cicle", 5);
	c.getType();
	cout << "Area: " << c.Area() << endl;
	*/


	/*
	Cat c("Tom", 5);
 
	Animal* pm = new Mouse("Jerry", 3);

	Animal* pd = new Dog("Spike", 7);

	Animal* an[] = { pm, pd };
	for (size_t i = 0; i < 2; i++)
	{
		cout << c.getType() << endl;
		c.info();
		cout << c.voice() << endl;
		cout << endl;
	}
	*/


	//Human h("Svbg  erana", 16);
	//h.info();

	//FootbalPlayer fp;
	//fp.info();
	/*
	Engine1* engine= new Engine1;
	Car2 car2(engine);
	car2.info();

	
	STO sto;
	sto.stEngineToStend(car2.getEngine());
	sto.upPower(100);
	car2.info();

	car2.setEngine(sto.getEngine());
	car2.info();*/
	//BasePolice base;
//	base.addProtocol();
//	base.addProtocol();
//	base.addProtocol();
//	base.printAll();

	/*BTree<int, int> bt;
	bt.push_r(20, 20);
	bt.push_r(10, 10);
	bt.push_r(40, 40);
	bt.push_r(70, 70);
	bt.push(5, 5);
	bt.push(34, 34);
	bt.print();*/


	/*List<int> ls1 = {1,2,3};
	ls1.print();
	ls1.push_back(3);
	ls1.push_back(5);
	ls1.push_back(9);
	ls1.remove(1);
	ls1.print();*/


	/*
	ForwardList<int> fl = { 1,8,6,1,4,5 };
	fl.print();
	fl.remove(2);
	fl.print();
	fl.sort();

	for (size_t i = 0; i < fl.length(); i++)
	{
		fl[i] *= 2;
	}
	fl.print();	*/
	//Queue<int> q = { 1,5,7,6 };
	//q.print();
	//q.enqueue(10);
	//q.print();
	//q.clear();

	/*Array arr(10);
	arr.set();
	arr.print();
	arr.printIndex(5);
	//cout << arr["one"] << endl;
	//arr.print();
	arr(10);
	arr.print();
	//arr.sumarr();
	cout << ()*/

	/*Time t1(0, 0, 30);
	Time t2(0, 0, 50);
	Time t3 = t1 + t2;
	Time t4 = t1 + 10;
	t3.print();
	t4.print();
	Time t5 = 100 + t1;
	Time t6 = t1 - t2;
	t1 += t2;
	t1 -= t2;
	t1 <=> t2;
	int s = t1;
	t1.print();
	t1++;
	++t1;
	t1--;
	--t1;*/

	/*Fraction f1(1, 2);
	Fraction f2(1, 4);

	f1.print();				
	f1 += f2;
	Fraction f3 = f1 + 10;
	Fraction f4 = 10 + f1;
	f4.print();*/




	//Bank bank;
	////
	/*bank.size = 2;
	bank.clients = new Client[2];
	bank.clients[0].name = new char[] = { "Devil" };
	bank.clients[0].size = 1;
	bank.clients[0].id = ++idCount;
	bank.clients[0].accounts = new Account;
	strcpy_s(bank.clients[0].accounts[0].name, 4, "UAH");
	strcpy_s(bank.clients[0].accounts[0].number, 17, "2569824");

	bank.clients[1].name = new char[] = { "God" };
	bank.clients[1].size = 1;
	bank.clients[1].id = ++idCount;
	bank.clients[1].accounts = new Account;
	strcpy_s(bank.clients[1].accounts[0].name, 4, "USD");
	strcpy_s(bank.clients[1].accounts[0].number, 17, "669832424");*/
	//cin.getline(st2, 80);
	//strcpy_s(st2, 80, st1); // копирует из 1 в 2
	//strncpy_s(st2, 80, st1, 5); // коопирует до указаного числа ( 5 )
	//strcar_s(st2, 80, st1); // cклеить два рядка ( сначал st2 > st1 )
	//strncat(st2, 80, st1, 5); // добавляет к 1 второй рядок НО только до (5) символов
	//strcmp(st2, st1); // если 1 больше второго (>1) == (0) если 2 больше (<1)
	//strncmp(st2,st1, 4) // сранения до числа (4)
	//stricmp(st2,st1, 4) // без регистра
	//strnicmp(st2,st1, 4) // и то и то
	//char* t = strchr(st1,'a'); // находит совпадение и віводит от него
	//if (t)
		//cout << t << endl;
		//char* t = strrchr(st1,'a'); // находит последние совпадение и віводит от него
		//if (t)
	//cout << t << endl;
	//char* t = strstr(st1,st2); // находит совпадение в другом рядке
		//if (t)
		//cout << t << endl;
	//cout << isalnum('a') << endl; // символ/цыфра
	//cout << isalpha('a') << endl; // являеться буквой?
	//cout << isdigit('a') << endl; // цыфра
		//cout << ispunct('a') << endl; // пунктир
	//cout << isprint('a') << endl; // печатное
	//cout << isspace('a') << endl; // пробел?
		//cout << isupper('a') << endl; // капслук
	//_strset_s(st1, '#'); //заполняет рядок ЭТИМ символом (#);
}