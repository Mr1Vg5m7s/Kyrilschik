#pragma once
#include <iostream>
#include <String.h>
using namespace std;
class Computer
{
	string name;
	int ram;
	string gpu;
public:
	Computer(string name, int ram, string gpu) : name(name), ram(ram), gpu(gpu) {}
	~Computer() {}

	void setName(const string& newName)    { name = newName; }
	void setRam(int newRam)                { ram = newRam; }
	void setGpu(const string& newGpu)      { gpu = newGpu; }

	virtual void info() const
	{
		cout << "Computer Name: " << name << endl;
		cout << "RAM: " << ram << " GB" << endl;
		cout << "GPU: " << gpu << endl;
	}
	//
	virtual ostream& print(ostream& out) const
	{
		out << "Computer Name: " << name << endl;
		out << "RAM: "           << ram << " GB" << endl;
		out << "GPU: "           << gpu << endl;
		return out;
	}

};
ostream& operator<<(ostream& out, const Computer* compik)
{
	return compik->print(out);
}
////                          SERVER
class Server
{
	int core;
	int chanel;
	string ip;
public:
	Server(int core, int chanel, string ip) : core(core), chanel(chanel), ip(ip) {}
	~Server() {}

	void setCore(int newCore) { core = newCore; }
	void setChanel(int newChanel) { chanel = newChanel; }
	void setIp(const string& newIp) { ip = newIp; }

	virtual void info() const
	{
		cout << "Server Core: " << core << endl;
		cout << "Channel: " << chanel << endl;
		cout << "IP Address: " << ip << endl;
	}
};
////                          PersonalComputer
class PersonalComputer : public Computer
{
	bool isAudio = true;
	string nameAudioGPU;
	string TMouse;
public:
	PersonalComputer(string name, int ram, string gpu, bool isAudio, string nameAudioGPU, string TMouse)
		: Computer(name, ram, gpu), isAudio(isAudio), nameAudioGPU(nameAudioGPU), TMouse(TMouse) {}
	~PersonalComputer() {}

	void getisAudio() const
	{
		if (isAudio)
			cout << "Audio is enabled." << endl;
		else
			cout << "Audio is disabled." << endl;
	}

	void info() const override
	{
		Computer::info();
		cout << "Audio GPU Name: " << nameAudioGPU << endl;
		cout << "Mouse Type: " << TMouse << endl;
	}
};
////                          Laptop
class Laptop : public Computer
{
	int diagonal;
	int TimeLifeBattery;
	int weight;
public:
	Laptop(string name, int ram, string gpu, int diagonal, int TimeLifeBattery, int weight)
		: Computer(name, ram, gpu), diagonal(diagonal), TimeLifeBattery(TimeLifeBattery), weight(weight) {}
	~Laptop() {}

	virtual void info() const override
	{
		Computer::info();
		cout << "Diagonal: " << diagonal << endl;
		cout << "Battery Life: " << TimeLifeBattery << endl;
		cout << "Weight: " << weight << endl;
	}

};
////                          PortServer
class PortServer : public Laptop, public Server
{
	bool isWiFi;
	string nameServer;
	string nameOC;
public:
	PortServer(string name, int ram, string gpu, int diagonal, int TimeLifeBattery, int weight,
		int core, int chanel, string ip, bool isWiFi, string nameServer, string nameOC)
		: Laptop(name, ram, gpu, diagonal, TimeLifeBattery, weight), Server(core, chanel, ip),
		isWiFi(isWiFi), nameServer(nameServer), nameOC(nameOC) {}
	~PortServer() {}

	void info() const override
	{
		Laptop::info();
		Server::info();
		cout << "WiFi Enabled: " << (isWiFi ? "Yes" : "No") << endl;
		cout << "Server Name: " << nameServer << endl;
		cout << "Operating System: " << nameOC << endl;
	}
};

