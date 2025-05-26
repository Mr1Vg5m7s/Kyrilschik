#pragma once
#include<iostream>
#include<Windows.h>

#include"String.h"
#include"List.h"
#include"func.h"

using namespace std;

class Warrior;

class Skill
{
public:
	virtual void execute(Warrior* w) = 0;
};

class Poison : public Skill
{
public:
	virtual void execute(Warrior* w) override;
};

//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
class Warrior
{
	int hp;
	int damage;

	List<Skill*> skills;
public:
	Warrior(int hp, int damage) : hp(hp), damage(damage) {}
	~Warrior() {}

	int getHP() const
	{
		return hp;
	}
	int getDamage() const
	{
		return damage;
	}

	void setHP(int hp)
	{
		this->hp = hp;
	}

	void setDamage(int damage)
	{
		this->damage = damage;
	}

	virtual void skill(Warrior* w) = 0;
	virtual ostream& print(ostream& out) const
	{
		out <<"HP : " << hp << endl;
		out << "Damage: " << damage << endl;
		return out;
	}

	friend ostream& operator<<(ostream& out, const Warrior* w);

};
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

void Poison::execute(Warrior* w)
{
	w->setHP(0);
}

ostream& operator<<(ostream& out, const Warrior* w)
{
	return w->print(out);
}

class Light : public Warrior
{
public:
	Light(int hp, int damage) : Warrior(hp, damage) {}
};

class Dark : public Warrior
{
public:
	Dark(int hp, int damage) : Warrior(hp, damage) {}
};
//---------------------------------------------------------
class Swordsman : public Light                           //--
{
public:
	Swordsman(int hp, int damage) : Light(hp, damage) {}
	virtual void skill(Warrior* w) override
	{

	}

	virtual ostream& print(ostream& out) const
	{
		cout << "Swordsman" << endl;
		return Warrior::print(out);
	}
};

class Archer : public Light                              //--
{
public:
	Archer(int hp, int damage) : Light(hp, damage) {}
	virtual void skill(Warrior* w) override
	{

	}
	virtual ostream& print(ostream& out) const
	{
		cout << "Archer -> " << endl;
		return Warrior::print(out);
	}
};

class Rider : public Light                               //--
{
public:
	Rider(int hp, int damage) : Light(hp, damage) {}
	virtual void skill(Warrior* w) override
	{

	}
	virtual ostream& print(ostream& out) const
	{
		cout << "Rider -> " << endl;
		return Warrior::print(out);
	}
};
//------------------------------------------------------
class Zombi : public Dark
{
public:
	Zombi(int hp, int damage) : Dark(hp, damage) {}
	virtual void skill(Warrior* w) override
	{

	}
	virtual ostream& print(ostream& out) const
	{
		cout << "Zombi -> " << endl;
		return Warrior::print(out);
	}
};

class Ork : public Dark
{
public:
	Ork(int hp, int damage) : Dark(hp, damage) {}
	virtual void skill(Warrior* w) override
	{

	}
	virtual ostream& print(ostream& out) const
	{
		cout << "Ork -> " << endl;
		return Warrior::print(out);
	}
};

class Skeleton : public Dark
{
public:
	Skeleton(int hp, int damage) : Dark(hp, damage) {}
	virtual void skill(Warrior* w) override
	{

	}

	virtual ostream& print(ostream& out) const
	{
		cout << "Brother -> " << endl;
		return Warrior::print(out);
	}
};

class WarOfWorld
{
	List<Light*> lightes;
	List<Dark*> darkes;
public:
	WarOfWorld(int count) 
	{
		for (size_t i = 0; i < count; i++)
		{
			int r = rand() % 3;
			Light* l = nullptr;
			switch (r)
			{
			case 0:l = new Swordsman(rand() % 30 + 50, rand() % 10 + 20); break;
			case 1:l = new Archer(rand() % 30 + 50, rand() % 10 + 20); break;
			case 2:l = new Rider(rand() % 30 + 50, rand() % 10 + 20); break;
			}
			lightes.push_back(l);
		}

		for (size_t i = 0; i < count; i++)
		{
			int r = rand() % 3;
			Dark* d = nullptr;
			switch (r)
			{
			case 0: d = new Zombi(rand() % 30 + 50, rand() % 10 + 20); break;
			case 1: d = new Ork(rand() % 30 + 50, rand() % 10 + 20); break;
			case 2: d = new Skeleton(rand() % 30 + 50, rand() % 10 + 20); break;
			}
			darkes.push_back(d);
		}
	}

	Warrior* fight(Light* war1, Dark* war2)
	{
		if (false)
		{
			war1->skill(war2);
			return war1;
		}
		else if (true)
		{
			return war2;
		}
		else
		{
			return nullptr;
		}
	}


	void game()
	{
		while (true)
		{
			system("cls");
			cout << "        ------ LIGHT SOULS ------" << endl;
			lightes.print();

			gotoxy(50, 0);
			cout << "        ------ DARK SOULS------";
			darkes.print(50, 1);

			int ind_l = rand() % lightes.length();
			int ind_d = rand() % darkes.length();

			Warrior* lose = fight(lightes[ind_l], darkes[ind_d]);
			if (lightes[ind_l] == lose)
			{
				lightes.remove(ind_l);
			}
			else if (darkes[ind_d] == lose)
			{
				darkes.remove(ind_d);
			}

			system("pause");
		}
		
	}
};