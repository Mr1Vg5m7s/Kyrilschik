#pragma once
#include <iostream>
#include <initializer_list>

#include "Node.h"
#include "String.h"


class Animal 
{
	string name;
	int age;

public:
	Animal(string n, int a) : name(n), age(a) {}

	virtual string getType()
	{
		return "Animal";
	}

	virtual void info()
	{
		cout << "name:" << name << endl;
		cout << "age:" << age << endl;
	}

	virtual string voice()
	{
		return "????????";
	}
};

class Cat : public Animal
{
public:
	Cat(string n, int a) : Animal(n, a) {}
	
	string getType()
	{
		return "Cat";
	}

	string voice()
	{
		return "ћ€у, когда есть?";
	}
};

class Mouse : public Animal
{
public:
	Mouse(string n, int a) : Animal(n, a) {}

	string getType()
	{
		return "Mouse";
	}

	string voice()
	{
		return "ѕи пи пи";
	}
};

class Dog : public Animal
{
public:
	Dog(string n, int a) : Animal(n, a) {}

	string getType()
	{
		return "Dog";
	}

	string voice()
	{
		return "√ав гав гав";
	}

};