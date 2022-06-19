#include "Jedi.h"
#include "JediType.h"
#include <iostream>
#pragma warning(disable : 4996).
using namespace std;

Jedi::Jedi()
{
	name = new char[50];
	colorOfSword = new char[50];
	strcpy(name, "");
	strcpy(name, "");
	power = 0.0;
	type = JediType::NONE;
	age = 0;
}
Jedi::~Jedi()
{
	delete[] name;
	delete[] colorOfSword;
}
Jedi::Jedi(const Jedi& other)
{

	this->name = new (std::nothrow) char[strlen(other.name) + 1];
	if (!this->name)
	{
		std::cout << "Memory problem!" << std::endl;
		return;
	}
	strcpy(this->name, other.name);
	this->colorOfSword = new (std::nothrow) char[strlen(other.colorOfSword) + 1];
	if (!this->colorOfSword)
	{
		std::cout << "Memory problem!" << std::endl;
		return;
	}
	strcpy(this->colorOfSword, other.colorOfSword);
	this->age = other.age;
	this->power = other.power;
	this->type = other.type;
}
Jedi& Jedi::operator = (const Jedi& other)
{
	if (this != &other)
	{
		delete[] name;
		delete[] colorOfSword;
		this->name = new (std::nothrow) char[strlen(other.name) + 1];
		if (!this->name)
		{
			std::cout << "Memory problem!" << std::endl;
			
		}
		strcpy(this->name, other.name);
		this->colorOfSword = new (std::nothrow) char[strlen(other.colorOfSword) + 1];
		if (!this->name)
		{
			std::cout << "Memory problem!" << std::endl;
			
		}
		strcpy(this->colorOfSword, other.colorOfSword);
		this->age = other.age;
		this->power = other.power;
		this->type = other.type;
	}
	return *this;
}
Jedi::Jedi(const char _name[], JediType _type, int _age,const char _colorOFSword[], double _power)
{
	name = new char[50];
	colorOfSword = new char[50];
	
	strcpy(name, _name);
	type = _type;
	age = _age;
	strcpy(colorOfSword, _colorOFSword);
	power = _power;
}
void Jedi::promote(double multiplier)
{
	/*Повишава дадения джедай с един ранг нагоре в
стълбицата и увеличава силата му по формулата
jedi_strength *= (1 + multiplier) (не може да
се повишава повече от ранг GRAND_MASTER и
multiplier трябва да е положително число от тип
double*/
	if (int(type) + 1 < 8 && multiplier >= 0)
	{
		type = JediType(int(type) + 1);
		
	}
	if (multiplier >= 0)
	{
		power *= (1 + multiplier);
	}
}
void Jedi::demote(double multiplier)
{
	if (int(type) - 1 > -1 && multiplier >= 0)
	{
		type = JediType(int(type) - 1);
		power *= (1 - multiplier);
		if (power < 0)
		{
			cout << "Strength cant be below 0! So it will be converted to 0" << endl;
			power = 0;
		}
	}
}
double Jedi::getPower() const
{
	return power;
}
int Jedi::getAge() const
{
	return age;
}
char* Jedi::getColorOfSword() const
{
	return colorOfSword;
}
char* Jedi::getName() const
{
	return name;
}
JediType Jedi::getType() const
{
	return type;
}
void Jedi::printInfo() const
{
	cout << "Name of jedi: " << name << endl;
	cout << "Strength: " << power << endl;
	cout << "Age: " << age << endl;
	cout << "Color of sword: " << colorOfSword << endl;
	cout << "Rank: " << int(type) << endl;
}