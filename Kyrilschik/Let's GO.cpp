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


using namespace std;
enum Color
{
	Black = 0, Blue = 1, Green = 2, Cyan = 3, Red = 4, Magenta = 5, Brown = 6, LightGray = 7, DarkGray = 8,
	LightBlue = 9, LightGreen = 10, LightCyan = 11, LightRed = 12, LightMagenta = 13, Yellow = 14, White = 15
};

void SetColor(int text, int background)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (WORD)((background << 4) | text));
}

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


int idCount = 0;

struct Account
{
	char name[4];
	float balance = 0;
	char number[17];

	void print()
	{
		cout << name << " " << number << " " << setw(6) << balance << endl;
	}



	void addSumm()
	{
		system("cls");
		cout << "Внесення коштів " << endl;
		int sum;
		cout << "Введите сумму" << endl;
		cin >> sum;
		balance += sum;
		cout << "Кошті введені до рахунку" << endl;
		system("pause");
	}

	void withDraw()
	{
		system("cls");
		cout << "Зняття коштів " << endl;
		int sum;
		cout << "Введите сумму" << endl;
		cin >> sum;
		balance += sum;
		if (balance - sum < 0)
		{
			SetColor(LightRed, Black);
			cout << "Не достатньо коштів, бімж" << endl;
			SetColor(LightRed, Black);
		}
		else
		{
			balance -= sum;
			cout << "Кошти зняті з рахунку" << endl;
		}
		system("pause");
	}

	void menu()
	{
		while (true)
		{
			system("cls");
			cout << " --- Меню рахунку ---" << number << endl;
			cout << endl;
			print();
			cout << endl;
			cout << "1.Внесення коштів " << endl;
			cout << "2.Зняття коштів " << endl;
			cout << "3.Вихід" << endl;
			int choice;
			cin >> choice;
			cin.ignore();
			switch (choice)
			{
			case 1: addSumm(); break;
			case 2: withDraw(); break;
			case 3: return;
			default: break;
			}

		}
	}
};

struct Client
{
	int id;
	char* name;
	Account* accounts = nullptr;
	int size = 0;

	void addAccount()
	{
		system("cls");
		cout << "Відкриття нового рахунку" << endl;
		cout << "------------------------" << endl;
		Account account;
		cout << "Виберіть валюту :" << endl;
		cout << "1. UAH\n2. USD\n3. EUR\n";
		int c;
		cin >> c;
		cin.ignore();
		switch (c)
		{
		case 1: strcpy_s(account.name, 4, "UAH"); break;
		case 2: strcpy_s(account.name, 4, "USD"); break;
		case 3: strcpy_s(account.name, 4, "EUR"); break;
		default: strcpy_s(account.name, 4, "---"); break;
		}
		for (size_t i = 0; i < 16; i++)
		{
			account.number[i] = rand() % 10 + '0';
		}
		account.number[16] = '\0';

		addElemArray(accounts, size, account);

		cout << "Рахунок відкрито :" << endl;
		account.print();
		system("pause");
	}

	void printAccounts()
	{
		system("cls");
		SetColor(LightMagenta, Black);
		cout << "kjfdslkfj" << name << endl;
		cout << "------------------------" << endl;
		SetColor(LightGray, Black);
		for (size_t i = 0; i < size; i++)
		{
			accounts[i].print();
		}
		system("pause");
	}

	void workWithAccount()
	{
		system("cls");
		cout << "Выбор счёта" << endl;
		for (size_t i = 0; i < size; i++)
		{
			cout << i + 1 <<" ";
			accounts[i].print();
		}
		int choice;
		cout << "Номер счёта";
		cin >> choice;
		cin.ignore();
		accounts[choice - 1].menu();

	}

	void menu()
	{
		while (true)
		{
			system("cls");
			cout << " --- Меню клієнта ---" << endl;
			cout << "1. Відкрити рахунок" << endl;
			cout << "2. Стан рахунків" << endl;
			cout << "3. Працювати з рахунком" << endl;
			cout << "4. Вихід" << endl;
			int choice;
			cin >> choice;
			cin.ignore();
			switch (choice)
			{
			case 1: addAccount(); break;
			case 2: printAccounts(); break;
			case 3: workWithAccount(); break;
			case 4: return;

			default:
				break;
			}

		}
	}
	void print()
	{
		cout << setw(3) << id << ". " << name << endl;
	}
};


struct Bank
{
	Client* clients = nullptr;
	int size = 0;

	void addClients()
	{
		system("cls");
		cout << "Створення нового клієнта" << endl;
		cout << "------------------------" << endl;
		Client client;
		client.id = ++idCount;
		char buff[50];
		cout << "Ім'я : ";
		cin.getline(buff, 50);
		client.name = new char[strlen(buff) + 1];
		strcpy_s(client.name, strlen(buff) + 1, buff);
		addElemArray(clients, size, client);
		cout << "Клієнт створений" << endl;
		system("pause");
	}

	void selectClients()
	{
		system("cls");
		cout << "--- Вибір клієнта ---" << endl;
		for (size_t i = 0; i < size; i++)
		{
			clients[i].print();
		}
		cout << "-------------------------" << endl;
		int choice;
		cout << "Номер клієнта : ";
		cin >> choice;
		cin.ignore();
		clients[choice - 1].menu();
	}

	void printClients()
	{
		system("cls");
		cout << "------- Клієнти -----" << endl;
		for (size_t i = 0; i < size; i++)
		{
			clients[i].print();
		}
		cout << endl;
		system("pause");
	}

	void menu()
	{
		while (true)
		{
			system("cls");
			cout << " --- Головне Меню ----" << endl;
			cout << "1. Створити клієнта" << endl;
			cout << "2. Вибрати клієнта" << endl;
			cout << "3. Надрукувати клієнтів" << endl;
			cout << "4. Вихід" << endl;
			int choice;
			cin >> choice;
			cin.ignore();
			switch (choice)
			{
			case 1: addClients(); break;
			case 2: selectClients(); break;
			case 3: printClients(); break;
			case 4: exit(0); break;

			default:
				break;
			}

		}
	}
};

struct Point
{
	char name;
	int X;
	int Y;

	void print()
	{
		cout << name << "(" << X << ", " << Y << ")" << endl;
	}
};
/*struct Date
{
	int day;
	int month;
	int year;
};*/
struct Book
{
	char* name;
	char* avtor;
	char* data;
	int page;

	void print()
	{
		cout << name<<"     " << avtor << "    " << data << "    " << page << endl;
	}
};

struct Library
{
	Book* library = nullptr;
	int size = 0;

	void print()
	{
		for (size_t i = 0; i < size; i++)
		{
			library[i].print();
		}
	}

	void edit(int index)
	{
		int choice;
		cout << "Что меняем:(1-название, 2-автора, 3-дату,4-кол-во стр)" << endl;
		cin >> choice;
		cin.ignore();
		Book b;
		ifstream fin("pont.txt");
		char buff[80];
		switch (choice)
		{
		case 1:
			cout << "Edit(" << library[index].name << ")=" << endl;
			cin.getline(buff, 80);

			delete library[index].name;
			library[index].name = new char[strlen(buff) + 1];
			strcpy_s(library[index].name, strlen(buff) + 1, buff);
			break;
		case 2:
			cout << "Edit(" << library[index].name << ")=" << endl;
			cin.getline(buff, 80);

			delete library[index].avtor;
			library[index].avtor = new char[strlen(buff) + 1];
			strcpy_s(library[index].avtor, strlen(buff) + 1, buff);
			break;
		case 3:
			cout << "Edit(" << library[index].name << ")=" << endl;
			cin.getline(buff, 80);

			delete library[index].data;
			library[index].data = new char[strlen(buff) + 1];
			strcpy_s(library[index].data, strlen(buff) + 1, buff);
			break;
		case 4:
			cout << "Edit(" << library[index].name << ")=" << endl;
			cin >> library[index].page;
			cin.ignore();
			break;
		default:
			break;
		}
	}

	void load()
	{
		Book b;
		ifstream fin("pont.txt");
		char buff[80];
		while (fin.getline(buff, 80))
		{
			b.name = new char[strlen(buff) + 1];
			strcpy_s(b.name, strlen(buff) + 1, buff);

			fin.getline(buff, 80);
			b.avtor = new char[strlen(buff) + 1];
			strcpy_s(b.avtor, strlen(buff) + 1, buff);

			fin.getline(buff, 80);
			b.data = new char[strlen(buff) + 1];
			strcpy_s(b.data, strlen(buff) + 1, buff);

			fin >> b.page;
			fin.get();

			addElemArray(library, size, b);
		}

	}

	void add(int index)
	{
		Book book;
		char buff[80];
		//
		cout << "Edits(" << "Book name" << ")=" << endl;
		cin.getline(buff, 80);

		book.name = new char[strlen(buff) + 1];
		strcpy_s(book.name, strlen(buff) + 1, buff);
		////////////////////////////////////////////////////////
		cout << "Edits(" << "Book avtor" << ")=" << endl;
		cin.getline(buff, 80);

		book.avtor = new char[strlen(buff) + 1];
		strcpy_s(book.avtor, strlen(buff) + 1, buff);
		////////////////////////////////////////////////////////
		cout << "Edits(" << "Book data" << ")=" << endl;
		cin.getline(buff, 80);

		book.data = new char[strlen(buff) + 1];
		strcpy_s(book.data, strlen(buff) + 1, buff);
		////////////////////////////////////////////////////////
		cout << "Edit(" << book.page << ")=" << endl;
		cin >> book.page;
		cin.ignore();
		///////////////////////////////////////////////////////
		add(book);
	}

	void add(Book item)

	{
		addElemArray(library, size, item);
	}

};

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout.setf(ios::boolalpha);


	BasePolice base;
	base.addProtocol();
	base.addProtocol();
	base.addProtocol();
	base.printAll();

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