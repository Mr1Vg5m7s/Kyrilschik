#pragma once
#include <iostream>

using namespace std;

class Array
{
	int* arr;
	int size;

public:
	Array()
	{
		size = 0;
		arr = nullptr;
	}

	explicit Array(int s)
	{
		size = s;
		arr = new int[size];
	}

	~Array()
	{
		delete arr;
	}

	Array(const Array& obj)
	{
		cout << "copy constructor" << endl;
		size = obj.size;
		arr = new int[size + 1];
		for (size_t i = 0; i <= size; i++)
		{
			arr[i] = obj.arr[i];
		}
	}
};