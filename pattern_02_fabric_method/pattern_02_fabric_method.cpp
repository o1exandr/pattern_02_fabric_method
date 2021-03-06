/*
Завдання 2.
Створити клас Барак, що створює об’єкти типу Юніт.
Створити класи
o	Воєнний Барак, що створює об’єкти типу Морський Піхотинець,
o	Вчений Барак, що створює об’єкти типу Божевільний Вчений,
o	Медичний Барак, , що створює об’єкти типу Воєнний Лікар.
Побудувати відповідні ієрархії класів, коректно визначити фабричні методи створення. 
Юніти повинні відрізнятись характеристиками: здоров’я, максимальне пошкодження (damage).
Використати при  виконанні завдання Фабричний метод у класичній реалізації.
*/

#include "stdafx.h"
#include <iostream> 
#include <string>


using namespace std;


class Unit
{
private:

	int hp;
	int damage;

public:

	int getHp()
	{
		return hp;
	}

	void setHp(int newHp)
	{
		hp = newHp;
	}

	int getDamage()
	{
		return damage;
	}

	void setDamage(int newDamage)
	{
		damage = newDamage;
	}


	virtual void print() = 0;
};

//морський котик
class UnitMarines : public Unit
{
public:

	void print()
	{
		cout << "\n\tMarines\nHP:\t" << this->getHp() << "\nDamage:\t" << this->getDamage() << endl;
	}
};

//бодевілний вчений
class UnitCrazyScientist : public Unit
{
public:

	void print()
	{
		cout << "\n\tCrazy Scientist\nHP:\t" << this->getHp() << "\nDamage:\t" << this->getDamage() << endl;
	}
};

//військовий лікар
class UnitMilitaryDoctor : public Unit
{
public:

	void print()
	{
		cout << "\n\tMilitary Doctor\nHP:\t" << this->getHp() << "\nDamage:\t" << this->getDamage() << endl;
	}
};

//абстрактний барак
class Barrack
{
private:

	int hp;
	int damage;

protected:

	virtual Unit* CreateUnit() = 0;

public:

	int getHp()
	{
		return hp;
	}

	void setHp(int newHp)
	{
		hp = newHp;
	}

	int getDamage()
	{
		return damage;
	}

	void setDamage(int newDamage)
	{
		damage = newDamage;
	}
	
	
	Unit* show() {
		Unit* unit = CreateUnit();
		unit->setHp(this->getHp());
		unit->setDamage(this->getDamage());
		unit->print();
		return unit;
	}
	
};

//військойи барак
class MilitaryBarrack : public Barrack
{
public:
	MilitaryBarrack() 
	{
		this->setHp(25);
		this->setDamage(20);
	}

	virtual Unit* CreateUnit()
	{
		return new UnitMarines();
	}
};

//науковий барак
class ScientificBarrack : public Barrack
{
public:
	ScientificBarrack()
	{
		this->setHp(15);
		this->setDamage(10);
	}

	virtual Unit* CreateUnit()
	{
		return new UnitCrazyScientist();
	}
};

//медичний барак
class MedicalBarrack : public Barrack
{
public:
	MedicalBarrack()
	{
		this->setHp(20);
		this->setDamage(15);
	}

	virtual Unit* CreateUnit()
	{
		return new UnitMilitaryDoctor();
	}
};



int main()
{
	Barrack** barracks = new Barrack*[3];
	

	barracks[0] = new MilitaryBarrack();
	barracks[1] = new ScientificBarrack();
	barracks[2] = new MedicalBarrack();

	for (int i = 0; i < 3; i++) 
		Unit* unit = barracks[i]->show();

	for (int i = 0; i < 3; i++)
		delete barracks[i];

	delete[]barracks;


	cout << endl;
	system("pause");
	return 0;

}