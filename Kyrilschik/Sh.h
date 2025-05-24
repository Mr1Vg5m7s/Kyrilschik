#pragma once
#include <iostream>
#include <initializer_list>
#include "Node.h"
#include "String.h"

class Shapa
{
public:
	string name;
	Shapa(string t) : name(t) {}
	virtual ~Shapa() { cout << "destr Shapa " << endl; }
	virtual float Area() = 0;
	virtual void getType()
	{
		cout << "Type: " << name << endl;
	}
};
//-------------------------------------
class Rectangle : public Shapa
{
	
public:
	Rectangle(string t) : Shapa(t) {}

	virtual ~Rectangle() { cout << "destr Reg " << endl; }

	
};
//-------------------------------------
class Circle : public Shapa
{
	float radius;
public:
	Circle(string t, float radius) : Shapa(t), radius(radius) {}
	virtual float Area() override
	{
		return 3.1415 * radius * radius;
	}
	~Circle() { cout << "destr Cir " << endl; }

	virtual void getType() override
	{
		Shapa::getType();
		cout << "Radius: " << radius << endl;
	}
};
//-------------------------------------