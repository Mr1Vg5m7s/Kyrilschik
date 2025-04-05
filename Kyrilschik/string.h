#pragma once
#include<iostream>
#include<Windows.h>
#include<iomanip>
#include<fstream>
#include<algorithm>

using namespace std;
class String
{
	char* str;
	int size;

	static int totalObjects;

public:

	String();

	explicit String(int size);

	String(const char* str);

	String& operator=(const String& obj);

	~String();

	void set(const char* str);

	void set();

	char* get() const;

	static int length(const char* str);
};

int String::totalObjects = 0;


String::String()
{
	size = 0;
	str = new char[1];
	totalObjects++;
	str[0] = '\0';
}

String::String(int size)
{
	this->size = size;
	str = new char[size + 1];
	for (size_t i = 0; i < size; i++)
	{
		str[i] = ' ';
	}
	str[size] = '\0';
	totalObjects++;
}

String::String(const char* str)
{
	this->set(str);
	totalObjects++;
}

String& String::operator=(const String& obj)
{
	if (this == &obj)
	{
		return *this;
	}

	if (str != nullptr)
	{
		delete[] str;
	}

	size = obj.size;
	str = new char[size + 1];
	for (size_t i = 0; i <= size; i++)
	{
		str[i] = obj.str[i];
	}

	return *this;
}

String::~String()
{
	delete[] str;
	totalObjects--;
}

void String::set(const char* str)
{
	char buff[800];
	cin.getline(buff, 800);

	this->set(buff);
}

void String::set()
{
	delete[] str;
	char buff[100];
	cin.getline(buff, 100);
	size = String::length(buff);
	str = new char[size + 1];
	for (size_t i = 0; i <= size; i++)
	{
		str[i] = buff[i];
	}
}

char* String::get() const
{
	return str;
}

int String::length(const char* str)
{
	int count = 0;
	while (str[count] != '\0')
	{
		count++;
	}
	return count;
}