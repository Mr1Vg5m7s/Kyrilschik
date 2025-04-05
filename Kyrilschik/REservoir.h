#pragma once
#include "string.h"
#include<iostream>
#include<Windows.h>
#include<iomanip>
#include<fstream>
#include<algorithm>

using namespace std;

enum class ReservoirType
{
	OCEAN, SEA, RIVER, LAKE, POND, PUDDLE, UNDEFINE =-1
};

const char* getReservoirType(ReservoirType type)
{
	switch (type)
	{
	case ReservoirType::OCEAN:  return "Ocean";
	case ReservoirType::SEA:    return "Sea";
	case ReservoirType::RIVER:  return "River";
	case ReservoirType::LAKE:   return "Lake";
	case ReservoirType::POND:   return "Pond";
	case ReservoirType::PUDDLE: return "Puddle";
	default:            		return "Undefined";
	}
}

class Reservoir
{
	ReservoirType type;
	String name;
	double width;
	double length;
	double depth;

public:
	Reservoir(ReservoirType type, String name, double width, double length, double depth)
	{
		this->type = type;
		this->name = name;
		this->width = width;
		this->length = length;
		this->depth = depth;
	}

	void printRes() const
	{
		cout << "Type: " << getReservoirType(type) << endl;
		cout << "Name:"  << name.get() << endl;
		cout << "width:" << width << endl;
		cout << "length:" << length << endl;
		cout << "depth:" << depth << endl;
	}

	void Sres()
	{

	}

	void ReservoirOneType()
	{

	}



};