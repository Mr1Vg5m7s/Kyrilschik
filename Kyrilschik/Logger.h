#pragma once
#include <iostream>
#include <fstream>
using namespace std;

class Logger
{
public:
	virtual ~Logger() {}
	virtual void logError(string error) = 0;
};

class ConsoleLogger : public Logger
{
public:
	virtual void logError(string error) override
	{
		cout << error << endl;
	} 
};

class FileLogger : public Logger
{
	string path;
public:
	FileLogger(string path) : path(path) {}
	virtual void logError(string error) override
	{
		ofstream out(path);
		out << error << endl;
		out.close();
	}
};



