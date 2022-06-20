#pragma once
#include "Jedi.h"
#include "JediType.h"
#include <iostream>
#include "Planet.h"
#include "Universe.h"
#pragma warning(disable : 4996)
void Universe::deallocate()
{
    delete[] planetArr;
}

void Universe::copy(const Universe& other)
{
    planetArr = new (std::nothrow) Planet[other.capacity];
    if (!this->planetArr)
    {
        std::cout << "Memory problem" << std::endl;
        return;
    }

    for (std::size_t i = 0; i < other.current; ++i)
    {
        this->planetArr[i] = other.planetArr[i];
    }

    this->current = other.current;
    this->capacity = other.capacity;
}

void Universe::resize()
{
    Planet* newUniverse = new (std::nothrow) Planet[capacity * INCREASE_STEP];
    if (!newUniverse)
    {
        std::cout << "Memory problem!" << std::endl;
        return;
    }

    for (std::size_t i = 0; i < this->current; ++i)
    {
        newUniverse[i] = this->planetArr[i];
    }

    this->deallocate();
    this->planetArr = newUniverse;
    this->capacity *= INCREASE_STEP;
}
Universe::Universe()
{
    planetArr = new (std::nothrow) Planet[INITIAL_CAPACITY];
    if (!this->planetArr)
    {
        std::cout << "Memory problem" << std::endl;
        return;
    }

    this->capacity = INITIAL_CAPACITY;
    this->current = 0;
}
Universe::Universe(const Universe& other)
{
    this->copy(other);
}
Universe::~Universe()
{
    this->deallocate();
}
Universe& Universe::operator = (const Universe& other)
{
    if (this != &other)
    {
        this->deallocate();
        this->copy(other);
    }

    return *this;
}
void Universe::removeJedi(const char planetName[], const char jediName[])
{
    for (int i = 0; i < current; i++)
    {
        if (strcmp(planetName, planetArr[i].getName()) == 0)
        {
            planetArr[i].removeJedi(planetName, jediName);
        }
    }
}
void Universe::createJedi(const char planetName[], const char jediName[], JediType jediRank, int jediAge, const char jediSaberColor[], double jediStrength)
{
    for (int i = 0; i < current; i++)
    {
        if (strcmp(planetName, planetArr[i].getName()) == 0)
        {
            planetArr[i].createJedi(planetName, jediName, jediRank, jediAge, jediSaberColor, jediStrength);
        }
    }
}
void Universe::getStrongestJedi(const char planetName[])
{
    for (int i = 0; i < current; i++)
    {
        if (strcmp(planetName, planetArr[i].getName()) == 0)
        {
            planetArr[i].getStrongestJedi(planetName);
        }
    }
}
void Universe::getYoungestJedi(const char planetName[], JediType jediRank)
{
    for (int i = 0; i < current; i++)
    {
        if (strcmp(planetName, planetArr[i].getName()) == 0)
        {
            planetArr[i].getYoungestJedi(planetName, jediRank);
        }
    }
}
char* Universe::getMostUsedSaberColor(const char planetName[], JediType jedirank)
{
    bool flag = 0;
    for (int i = 0; i < current; i++)
    {
        if (strcmp(planetName, planetArr[i].getName()) == 0)
        {
            flag = 1;
            char* tempo;
            tempo = new char[strlen(planetArr[i].getMostUsedSaberColor(planetName,jedirank)) + 1];
            strcpy(tempo, planetArr[i].getMostUsedSaberColor(planetName,jedirank));
            return tempo;
        }
    }
    if (flag = 0)
    {
        char asd[15];
        strcpy(asd, "error");
        return asd;
    }

}
char* Universe::getMostUsedSaberColor(const char planetName[])
{
    bool flag = 0;
    for (int i = 0; i < current; i++)
    {
        if (strcmp(planetName, planetArr[i].getName()) == 0)
        {
            flag = 1;
            char* tempo;
            tempo = new char[strlen(planetArr[i].getMostUsedSaberColor(planetName))+1];
            strcpy(tempo, planetArr[i].getMostUsedSaberColor(planetName));
            return tempo;
        }
    }
    if (flag = 0)
    {
        char asd[15];
        strcpy(asd, "error");
        return asd;
    }
}
void Universe::printInfo(const char planetName[]) const
{
    for (int i = 0; i < current; i++)
    {
        if (strcmp(planetName, planetArr[i].getName()) == 0)
        {
            planetArr[i].printInfo(planetName);
        }
    }
}
void Universe::addPlanet(const char planetName[])
{
    bool flag = 0;
    for (size_t i = 0; i < current; i++)
    {
        if (strcmp(planetName, planetArr[i].getName()) == 0)
        {
            flag = 1;
            break;
        }
    }
    if (flag == 1)
    {
        cout << "Already existing Planet" << endl;
    }
    else
    {
        if (current == capacity)
        {
            this->resize();
        }
        planetArr[current].setName(planetName);
        current++;
    }
}
void Universe::promote(const char* jediName,double multiplier)
{
    for (size_t i = 0; i < current; i++)
    {
        planetArr[i].promote(jediName,multiplier);
        
    }
}
void Universe::demote(const char* jediName,double multiplier)
{
    for (size_t i = 0; i < current; i++)
    {
        planetArr[i].demote(jediName, multiplier);

    }
}
void Universe::add(const char* planetName1, const char* planetName2)
{
    int tempindex1 = -1;
    int tempindex2 = -1;
    for (size_t i = 0; i < current; i++)
    {
       

        if (strcmp(planetName1, planetArr[i].getName()) == 0)
        {
            tempindex1 = i;
        }
        if (strcmp(planetName2, planetArr[i].getName()) == 0)
        {
            tempindex2 = i;
        }
    }
    if (tempindex1 == -1 || tempindex2 == -1)
    {
        cout << "Planet not found" << endl;
    }
    if (tempindex1 != -1 && tempindex2 != -1)
    {
        planetArr[tempindex1] + planetArr[tempindex2];
    }
}
void Universe::printJedi(const char* jediname)
{
    for (size_t i = 0; i < current; i++)
    {
        
        planetArr[i].printJedi(jediname);
    }
}