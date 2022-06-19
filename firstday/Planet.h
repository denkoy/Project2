#pragma once
#include "Jedi.h"
#include "JediType.h"
#include <iostream>
using namespace std;
const size_t INITIAL_CAPACITY = 2;
const size_t INCREASE_STEP = 2;

class Planet
{
protected:
	char *name;
	Jedi* arr;
	int current;
	int capacity;
	void deallocate();
	void copy(const Planet& other);
	void resize();
public:
	Planet();
	void setName(const char _name[]);
	Planet(const Planet& other);
	Planet& operator = (const Planet& other);
	Planet& operator + (const Planet& other);

	~Planet();
	char* getName() const;
	 void removeJedi(const char planetName[],const char jediName[]);
     void createJedi(const char planetName[], const char jediName[], JediType jediRank, int jediAge,const char jediSaberColor[], double jediStrength);
     void getStrongestJedi(const char planetName[]);
	 void getYoungestJedi(const char planetName[],JediType jediRank);
	 char* getMostUsedSaberColor(const char planetName[],JediType jedirank);
	 char* getMostUsedSaberColor(const char planetName[]);
	 void printInfo(const char planetName[]) const ;
	 void promote(const char jediName[], double multiplier);
	 void demote(const char jediName[], double multiplier);
	 void printJedi(const char* jediname);


};
