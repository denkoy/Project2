#pragma once
#include "Jedi.h"
#include "JediType.h"
#include <iostream>
#include <cstring>
#include <cstddef>
#pragma warning(disable : 4996)
#include "Planet.h"
using namespace std;

void Planet::deallocate()
{
	delete[] arr;
    delete[] name;
}
void Planet::copy(const Planet& other)
{
    this->name = new (std::nothrow) char[strlen(other.name) + 1];
    if (!this->name)
    {
        std::cout << "Memory problem!" << std::endl;
        return;
    }
    strcpy(this->name, other.name);
    //
    arr = new (std::nothrow) Jedi[other.capacity];
    if (!this->arr)
    {
        std::cout << "Memory problem" << std::endl;
        return;
    }

    for (std::size_t i = 0; i < other.current; ++i)
    {
        arr[i] = other.arr[i];
    }

    this->current = other.current;
    this->capacity = other.capacity;
}
char* Planet::getName() const
{
    return name;
}
void Planet::resize()
{

    Jedi* newArr = new (std::nothrow) Jedi[capacity * 2];
    if (!newArr)
    {
        std::cout << "Memory problem!" << std::endl;
        return;
    }
    char* newName = new(std::nothrow) char[50];
    strcpy(newName, name);
    for (std::size_t i = 0; i < current; ++i)
    {
        newArr[i] = arr[i];
    }

    this->deallocate();
    this->arr = newArr;
    this->name = newName;
    this->capacity *= 2;
}

Planet::Planet()
{
    name = new char[50];
    strcpy(name, "");
    arr = new (std::nothrow) Jedi[INITIAL_CAPACITY];
    current = 0;
    capacity = INITIAL_CAPACITY;
}
void Planet::setName(const char _name[])
{
    strcpy(name, _name);
}
Planet::Planet(const Planet& other)
{
    this->copy(other);
}
Planet& Planet::operator = (const Planet& other)
{

    if (this != &other)
    {
        this->deallocate();
        this->copy(other);
    }

    return *this;
}
Planet::~Planet()
{
    deallocate();
}
void Planet::removeJedi(const char planetName[],const char jediName[])
{
    bool flag = 0;
    for (size_t i = 0; i < current; i++)
    {
        if (strcmp(arr[i].getName(), jediName) == 0)
        {
            flag = 1;
            Jedi temp;
            temp = arr[i];
            arr[i] = arr[current - 1];
            arr[current - 1] = temp;
            current -= 1;
            cout << "Removal was successful!" << endl;
            break;
            
        }
    }
    if (flag == 0)
    {
       cout << "Removal wasn't succesful"<<endl;
    }
}
void Planet::createJedi(const char planetName[],const char jediName[], JediType jediRank, int jediAge, const  char jediSaberColor[], double jediStrength)
{
    bool flag = 0;
    for (size_t i = 0; i < current; i++)
    {
        if (strcmp(jediName, arr[i].getName()) == 0)
        {
            flag = 1;
            break;
        }
    }
    if (flag == 1)
    {
        cout << "Already existing Jedi" << endl;
    }
    else
    {
        if (current == capacity)
        {
            this->resize();
        }
        arr[current] = Jedi(jediName, jediRank, jediAge, jediSaberColor, jediStrength);
        current++;
    }
}

void Planet::getStrongestJedi(const char planetName[])
{
    double temp = -1;
    int tempIndex = -1;
    for (int i = 0; i < current; i++)
    {
        if (arr[i].getPower() > temp)
        {
            temp = arr[i].getPower();
            tempIndex = i;
        }
    }
    arr[tempIndex].printInfo();
}
void Planet::getYoungestJedi(const char planetName[],JediType jediRank)
{
    int temp=99999;
    int tempIndex = -1;
    for (int i = 0; i < current; i++)
    {
        if (arr[i].getType() == jediRank)
        {
            if (temp > arr[i].getAge())
            {
                tempIndex = i;
                temp = arr[i].getAge();
            }
            else if (temp == arr[i].getAge())
            {
                if (strcmp(arr[tempIndex].getName(), arr[i].getName()) > 0)
                {
                    temp = arr[i].getAge();
                    tempIndex = i;
                }
                else
                {
                    ;
                }
            }
        }
    }
    if (tempIndex == -1)
    {
        cout << "The planet is empty and there aren't any Jedis" << endl;
    }
    else
    {
        arr[tempIndex].printInfo();
    }
}
char* Planet::getMostUsedSaberColor(const char planetName[],JediType jedirank)
{
    int colors[6];
    for (int i = 0; i < 5; i++)
    {
        colors[i] = 0;
    }
    int red = 0;
    int yellow = 0; 
    int green = 0; 
    int blue = 0; 
    int purple = 0; 
    int white = 0;
    for (size_t i = 0; i < current; i++)
    {
        if (arr[i].getType() == jedirank)
        {
            if (strcmp(arr[i].getColorOfSword(), "Red") == 00 || strcmp(arr[i].getColorOfSword(), "RED") == 0 || strcmp(arr[i].getColorOfSword(), "red") == 0)
            {
                red++;
                colors[0]++;
            }
            else if (strcmp(arr[i].getColorOfSword(), "Yellow") == 00 || strcmp(arr[i].getColorOfSword(), "YELLOW") == 0 || strcmp(arr[i].getColorOfSword(), "yellow") == 0)

            {
                yellow++;
                colors[1]++;
            }
            else if (strcmp(arr[i].getColorOfSword(), "Green") == 00 || strcmp(arr[i].getColorOfSword(), "GREEN") == 0 || strcmp(arr[i].getColorOfSword(), "green") == 0)

            {
                colors[2]++;
                green++;
            }
            else if (strcmp(arr[i].getColorOfSword(), "Blue") == 00 || strcmp(arr[i].getColorOfSword(), "BLUE") == 0 || strcmp(arr[i].getColorOfSword(), "blue") == 0)

            {
                colors[3]++;
                blue++;
            }
            else if (strcmp(arr[i].getColorOfSword(), "Purple") == 00 || strcmp(arr[i].getColorOfSword(), "PURPLE") == 0 || strcmp(arr[i].getColorOfSword(), "purple") == 0)

            {
                colors[4]++;
                purple++;
            }
            else if (strcmp(arr[i].getColorOfSword(), "White") == 00 || strcmp(arr[i].getColorOfSword(), "WHITE") == 0 || strcmp(arr[i].getColorOfSword(), "white") == 0)

            {
                colors[5]++;
                white++;

            }
        }
    }
    int pass = 0;
    int temp1 = 0;

    for (int i = 0; i < 6; i++) {
        for (int j = i + 1; j < 6; j++)
        {
            if (colors[j] < colors[i])
            {
                temp1 = colors[i];
                colors[i] = colors[j];
                colors[j] = temp1;
            }
        }
        pass++;
    }
    char color[15];
    if (colors[5] == red)
    {
        strcpy(color, "Red");
    }
    else if (colors[5] == yellow)
    {
        strcpy(color, "Yellow");
    }
    else if (colors[5] == green)
    {
        strcpy(color, "Green");
    }
    else if (colors[5] == blue)
    {
        strcpy(color, "Blue");
    }
    else if (colors[5] == purple)
    {
        strcpy(color, "Purple");
    }
    else if (colors[5] == white)
    {
        strcpy(color, "White");
    }
    return color;
}
char* Planet::getMostUsedSaberColor(const char planetName[])
{
    int colors[6];
    for (size_t i = 0; i < 6; i++)
    {
        colors[i] = 0;
    }
    int red = 0;
        int yellow = 0;
    int green = 0; 
    int blue = 0; 
    int purple = 0;
        int white = 0;
    for (size_t i = 0; i < current; i++)
    {
        if (strcmp(arr[i].getColorOfSword(), "Red")==00 || strcmp(arr[i].getColorOfSword(), "RED")==0 || strcmp(arr[i].getColorOfSword(), "red")==0)
        {
            red++;
            colors[0]++;
        }
        else if (strcmp(arr[i].getColorOfSword(), "Yellow") == 00 || strcmp(arr[i].getColorOfSword(), "YELLOW") == 0 || strcmp(arr[i].getColorOfSword(), "yellow") == 0)

        {
            yellow++;
            colors[1]++;
        }
        else if (strcmp(arr[i].getColorOfSword(), "Green") == 00 || strcmp(arr[i].getColorOfSword(), "GREEN") == 0 || strcmp(arr[i].getColorOfSword(), "green") == 0)

        {
            colors[2]++;
            green++;
        }
        else if (strcmp(arr[i].getColorOfSword(), "Blue") == 00 || strcmp(arr[i].getColorOfSword(), "BLUE") == 0 || strcmp(arr[i].getColorOfSword(), "blue") == 0)

        {
            colors[3]++;
            blue++;
        }
        else if (strcmp(arr[i].getColorOfSword(), "Purple") == 00 || strcmp(arr[i].getColorOfSword(), "PURPLE") == 0 || strcmp(arr[i].getColorOfSword(), "purple") == 0)

        {
            colors[4]++;
            purple++;
        }
        else if (strcmp(arr[i].getColorOfSword(), "White") == 00 || strcmp(arr[i].getColorOfSword(), "WHITE") == 0 || strcmp(arr[i].getColorOfSword(), "white") == 0)

        {
            colors[5]++;
            white++;

        }
    }
    int pass = 0;
    int temp1 = 0;

    for (int i = 0; i < 6; i++) {
        for (int j = i + 1; j < 6; j++)
        {
            if (colors[j] < colors[i]) {
                temp1 = colors[i];
                colors[i] = colors[j];
                colors[j] = temp1;
            }
        }
        pass++;
    }
    char color[15];
    if (colors[5] == red)
    {
        strcpy(color, "Red");
    }
    else if (colors[5] == yellow)
    {
        strcpy(color, "Yellow");
    }
    else if (colors[5] == green)
    {
        strcpy(color, "Green");
    }
    else if (colors[5] == blue)
    {
        strcpy(color, "Blue");
    }
    else if (colors[5] == purple)
    {
        strcpy(color, "Purple");
    }
    else if (colors[5] == white)
    {
        strcpy(color, "White");
    }
    ;
    return color;
}
void Planet::printInfo(const char planetName[]) const
{
    cout << "Name of planet: " << name << endl;
    Jedi temp;
    for (int i = 0; i < this->current; i++) {
        for (int j = i + 1; j < this->current; j++)
        {
            if (arr[i].getType() > arr[j].getType())
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
            else if (arr[i].getType() == arr[j].getType())
            {
                if (strcmp(arr[j].getName(), arr[i].getName()) > 0)
                {
                    temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
    }
    for (int i = this->current - 1; i >= 0; i--)
    {
        arr[i].printInfo();
    }
    /*for (size_t i = 0; i < current; i++)
    {
        cout << "Jedi number: " << temp << endl;
        temp++;
        arr[i].printInfo();
    }*/
}
Planet& Planet::operator + (const Planet& other)
{
    Jedi* combined;
    combined = new Jedi[this->current + other.current];
    for (size_t i = 0; i < this->current; i++)
    {
        combined[i] = this->arr[i];
    }
    int temp = 0;
    for (size_t j = this->current; j < this->current + other.current ; j++)
    {
        combined[j] = other.arr[temp];
        temp++;
    }

    int pass = 0;
    Jedi temp1;
    for (int i = 0; i < this->current + other.current; i++) {
        for (int j = i + 1; j < this->current + other.current; j++)
        {
            if (strcmp(combined[j].getName() ,combined[i].getName())>0)
            {
                temp1 = combined[i];
                combined[i] = combined[j];
                combined[j] = temp1;
            }
        }
        pass++;
    }
    for (int i = this->current + other.current-1; i >=0 ; i--)
    {
        combined[i].printInfo();
    }
    delete[] combined;
    return *this;
}
void Planet::promote(const char jediName[], double multiplier)
{
    for (int i = 0; i < current; i++)
    {
        if (strcmp(jediName, arr[i].getName()) == 0)
        {
            arr[i].promote(multiplier);
        }
    }
}
void Planet::demote(const char jediName[], double multiplier)
{
    for (int i = 0; i < current; i++)
    {
        if (strcmp(jediName, arr[i].getName()) == 0)
        {
            arr[i].demote(multiplier);
        }
    }
}
void Planet::printJedi(const char* jediname)
{
    bool flag = 0;
    for (size_t i = 0; i < current; i++)
    {
        if (strcmp(jediname, arr[i].getName()) == 0)
        {
            flag = 1;
            arr[i].printInfo();
            
        }
    }

    if (flag == 0)
    {
       
        cout << "Not existing jedi on planet "<< getName() << endl;
    }
}

