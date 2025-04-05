

/*
	int col = 2;
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
	}
	*/

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

			////4 ôåâð
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
			//1.ÔÅÂÐÀËßßßß

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
			cout  <<" Âñåãî "<< count << " íóëåé " << endl;*/


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
			//cout << "ÏÍ ÂÒ ÑÐ ×Ò ÏÒ ÑÁ ÂÑ ";

			//for (int i = 1; i <=30; i++)
			//{
			//	cout << setw(3) << i;
			//	if (i % 7 == 0)
			//		cout << endl;
			//}
			//cout << endl;

			//SetColor(White, Black);
			//cout << "-----Ñ³÷åíü-----" << endl;
			//cout << " ÑÐ ×Ò ÏÒ ÑÁ ÂÑ ÏÍ ÂÒ" << endl;
			//for (int i = 1; i <=30; i++)
			//{
			//	cout << setw(3) << i;
			//	if (i % 7 == 0)
			//		cout <<  endl;
			//}