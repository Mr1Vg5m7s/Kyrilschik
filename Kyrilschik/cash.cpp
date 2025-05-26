/*
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
			cout << i + 1 << " ";
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
/*
struct Book
{
	char* name;
	char* avtor;
	char* data;
	int page;

	void print()
	{
		cout << name << "     " << avtor << "    " << data << "    " << page << endl;
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
*/


/*
* /*Library lib;
	lib.load();
	lib.print();
	lib.edit(1);
	lib.print();
	lib.add(0);
	lib.print();*/
	/*int size = 0;
	ifstream fin;
	fin.open("pont.txt");
	if (fin.is_open())
	{
		int a;
		while (fin >> a)
		{
		}
	}
	*/

	/*int* b = nullptr;
	int size = 0;
	ifstream fin;
	fin.open("text.txt");
	if (fin.is_open())
	{
		int a;
		while (fin >> a)
		{
			addElemArray(b, size, a);
		}
	}
	printArray(b, size);
	int* c = nullptr;
	fin.open("text.txt");
	for (size_t i = 0; i < 5; i++)
	{
		if (b[i] % 2 == 0)
		{
			c[i] == b[i];
		}
	}
	fin.close();
	printArray(b, size);*/
/*
	const int size = 10;
	Point p[size];
	for (size_t i = 0; i < size; i++)
	{
		p[i].name = 'A' + i;
		p[i].X = rand() % 10;
		p[i].Y = rand() % 10;

		p[i].print();
	}
	ofstream out("pont.txt");
	for (size_t i = 0; i < size; i++)
	{
		out << p[i].name << " " << p[i].X << " " << p[i].Y << endl;
	}*/

	/*ofstream fout;
	fout.open("text.txt");
	for (size_t i = 0; i < 5; i++)
	{
		fout << a[i]<< " ";
	}*/
	/*int col = 2;
	char buff[30];
	char** pib = nullptr;
	createArray2D(pib, col, 2);
	while (true)
	{
		for (size_t i = 0; i < row; i++)
		{
			for (size_t j = 0; j < col; j++)
			{

			}
		}
		cin.getline(buff, 30);
		int len = strlen(buff);

		char* t = strstr(st1, st2);
		for (size_t i = 0; i < size; i++)
		{
			if (t)
				cout << t << endl;
		}
	}*/

	/*int a = 9;
	int* pa = &a;
	int** ppa = &pa;

	int row, col;
	cin >> row >> col;*/

	/*int** p = createArray2D<int>(row, col);
	setArray2D(p, row, col);
	printArray2D(p, row, col);

	/*addStolbtoINDEX2D(p, row, col, 2);
	printArray2D(p, row, col);
	cout << endl;*/



	///////04.03///////



	/*int size = 5;
	char buff[30];

	char** pib = new char*[size];
	for (size_t i = 0; i < size; i++)
	{
		cin.getline(buff, 30);
		int len = strlen(buff);
		pib[i] = new char[len + 1];
		strcpy_s(pib[i], len + 1, buff);

	}
	for (size_t i = 0; i < size-1; i++)
	{
		for (size_t j = 0; j < size-1-i; j++)
		{
			if (pib[i] > pib[i + 1])
			{
				swap(pib[i], pib[i + 1]);
			}
		}
	}
	cout << endl;
	for (size_t i = 0; i < size; i++)
	{
		cout << pib[i] << endl;
	}*/

//////25.02
	/*setArray(p, size, 0, 100);
	printArray(p, size);
	addElemArray(p, size, 999);
	printArray(p, size);
	delElemArray(p, size);
	printArray(p, size);
	addElemArray(p, size, 5, 999);
	printArray(p, size);
	delElemArray(p, size, 3);
	printArray(p, size);*/

	///////////18.02
		/*int size;
		cin >> size;
		int* p = new int[size];
		setArray(p, size, 0, 100);
		printArray(p, size);
		int count = 0;

		for (size_t i = 0; i < size; i++)
		{
			if (p[i] % 2 == 0) {
				count += 1;
			}
		}
		int* Narr = new int[count];
		count = 0;
		for (size_t i = 0; i < size; i++)
		{
			if (p[i] % 2 == 0) {
				Narr[count++] = p[i];
			}
		}
		printArray(Narr, count);*/
		/////////////////////

			////4 февр
			/*const int size = 10;
			int arr[size];
			for (size_t i = 0; i < size; i++)
			{
				arr[i] = rand() % (max - min + 1) + min;
			}
			for (size_t i = 0; i < size; i++)
			{
				cout << arr[i] << " ";
			}
			cout << endl;
			for (size_t i = 0; i < size - 1; i++)
			{
				for (size_t j = 0; j < size-1; j++)
				{
					if (arr[j] > arr[j + 1])
					{
						int t = arr[j];
						arr[j] = arr[j + 1];
						arr[j + 1] = t;
					}
				}
			}
			for (size_t i = 0; i < size; i++)
			{
				cout << arr[i] << " ";
			}
			cout << endl;*/

			/*
			const int row = 4;
			const int col = 4;
			int arr[row][col];
			int min = 0, max = 9;
			for (size_t i = 0; i < row; i++)
			{
				for (size_t j = 0; j < col; j++)
				{
					arr[i][j] = rand() % (max - min + 1) + min;
				}
			}


			for (size_t i = 0; i < row; i++)
			{
				for (size_t j = 0; j < col; j++)
				{
					cout << arr[i][j] << " ";
				}
				cout << endl;
			}
			cout << endl;


			for (size_t i = 1; i < row+1; i++)
			{
				for (size_t j = 1+i; j < col+1; j++)
				{
					swap(arr[i][j], arr[j-1][i-1]);

				}
			}



			for (size_t i = 0; i < row; i++)
			{
				for (size_t j = 0; j < col; j++)
				{
					cout << arr[i][j] << " ";
				}
				cout << endl;
			}*/
			//1.ФЕВРАЛЯЯЯЯ

			/*srand(time(0));
			const int size = 10;
			int min = 0, max = 1;
			int arr[size];
			int count = 0;
			int vtoroe = 0;
			for (size_t i = 0; i < size; i++)
			{
				arr[i] = rand() % (max - min + 1) + min;
			}
			for (size_t i = 0; i < size; i++)
			{
				cout << arr[i] << " ";
			}
			for (size_t i = 0; i < size; i++)
			{
				if (arr[i] % 2 == 0) {
					count++;
				}
				for (arr[i] % 2 != 0)
				{
					vtoroe++;
					cout << vtoroe << endl;
				}
			}
			cout  <<" Всего "<< count << " нулей " << endl;*/


			/*int kol = 0;
			int maxElem = arr[0];
			int minElem = arr[0];
			for (size_t i = 0; i < size; i++)
			{
				if (arr[i] > maxElem)
				{
					maxElem = arr[i];
				}
				if(arr[i] < minElem)
				{
					minElem = arr[i];
				}
			}
			cout << endl;
			cout << "MAX:" << maxElem << endl;
			cout << "MIN:" << minElem << endl;*/


			//float price;
			//cin >> price;
			//for (float i = 12; i <= 20; i+=2)
			//{
			//cout << i/10.f << " kg - " << (i/10.) * price << " grn" << endl;
			//}

			//int N,rez;
			//cout << "N = ";
			//cin >> N;
			//cin >> rez;

			//for (size_t i = 1; i <= 2*N-1; i+=2)
			//{
			//	rez += i;

			//}
			//cout << rez << endl;

			//Mr1Vg5m7s

			//int A, N;
			//unsigned long long sum = 1;
			//cout << "A = ";
			//cin >> A;
			//cout << "N = ";
			//cin >> N;
			//float exp = A;
			//for (int i = 1; i < N; i++)
			//{
				//exp *= A;
				//sum += exp;
			//}
			//cout << sum + A;
			//SetColor(White, Black);
			//cout << "ПН ВТ СР ЧТ ПТ СБ ВС ";

			//for (int i = 1; i <=30; i++)
			//{
			//	cout << setw(3) << i;
			//	if (i % 7 == 0)
			//		cout << endl;
			//}
			//cout << endl;

			//SetColor(White, Black);
			//cout << "-----Січень-----" << endl;
			//cout << " СР ЧТ ПТ СБ ВС ПН ВТ" << endl;
			//for (int i = 1; i <=30; i++)
			//{
			//	cout << setw(3) << i;
			//	if (i % 7 == 0)
			//		cout <<  endl;
			//}