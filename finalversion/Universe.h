#pragma once
#pragma once
#include "Jedi.h"
#include "JediType.h"
#include <iostream>
#include "Planet.h"

class Universe 
{
private:
	Planet* planetArr;
	void deallocate();
	void copy(const Universe& other);
	void resize();
	int capacity = 2;
	int current = 0;
public:
	Universe();
	Universe(const Universe& other);
	~Universe();
	Universe& operator = (const Universe& other);
	 void removeJedi(const char planetName[], const char jediName[]);
	 void createJedi(const char planetName[],const char jediName[], JediType jediRank, int jediAge, const char jediSaberColor[], double jediStrength);
	 void getStrongestJedi(const char planetName[]);
	 void getYoungestJedi(const char planetName[], JediType jediRank);
	 char* getMostUsedSaberColor(const char planetName[], JediType jedirank);
	 char* getMostUsedSaberColor(const char planetName[]);
	 void printInfo(const char planetName[]) const;
	void addPlanet(const char name[]);
	void promote(const char* jediName,double multiplier);
	void demote(const char* jediName, double multiplier);
	void add(const char* planetName1, const char* planetName2);
	void printJedi(const char* jediname);
};