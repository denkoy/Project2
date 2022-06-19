#pragma once
#include "JediType.h"
#include <cstddef>
using namespace std;
class Jedi
{
protected:
	char* name;
	JediType type;
	int age;
	char* colorOfSword;
	double power;
public:
	Jedi();
	Jedi(const char _name[], JediType _type, int _age,const char _colorOFSword[], double _power);
	void promote(double multiplier);
	void demote(double multiplier);
	double getPower() const;
	int getAge() const;
	char* getName() const;
	char* getColorOfSword() const;
	void printInfo() const;
	JediType getType() const;
	~Jedi();
	Jedi(const Jedi& other);
	Jedi& operator = (const Jedi& other);
}; 
