#pragma once
#include <iostream>
#include "String.h"
#include <fstream>
#include <map>
#include <string>

using namespace std;
class VacebMap
{
	
public:
	VacebMap();
	~VacebMap();

	void split(const string& str)
	{
		ifstream file("pont.txt");
		if (file.is_open())
		{
			string text;
			while (file >> text)
			{
				cout << text << endl;
			}
		}
		else
		{
			return;
		}
	};
};