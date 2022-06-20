using namespace std;
#include <string>
#include <cstring>
#include "Universe.h"
#include "helpfunctions.h"
#include <iostream>
#pragma warning(disable : 4996)
//start = -1, YOUNGLING = 0, INITIATE = 1,
//PADAWAN = 2, KNIGHTASPIRANT = 3, KNIGHT = 4, MASTER = 5, BATTLE_MASTER = 6,
//GRAND_MASTER = 7, NONE = 8
JediType converter(char* type)
{
    if (strcmp(type, "YOUNGLING") == 0)
    {
        JediType temp;
        temp = JediType::YOUNGLING;
        return temp;
    }
    else if (strcmp(type, "INITIATE") == 0)
    {
        JediType temp;
        temp = JediType::INITIATE;
        return temp;
    }
    else if (strcmp(type, "PADAWAN") == 0)
    {
        JediType temp;
        temp = JediType::PADAWAN;
        return temp;
    }
    else if (strcmp(type, "KNIGHTASPIRANT") == 0)
    {
        JediType temp;
        temp = JediType::KNIGHTASPIRANT;
        return temp;
    }
    else if (strcmp(type, "KNIGHT") == 0)
    {
        JediType temp;
        temp = JediType::KNIGHT;
        return temp;
    }
    else if (strcmp(type, "MASTER") == 0)
    {
        JediType temp;
        temp = JediType::MASTER;
        return temp;
    }
    else if (strcmp(type, "BATTLE_MASTER") == 0)
    {
        JediType temp;
        temp = JediType::BATTLE_MASTER;
        return temp;
    }
    else if (strcmp(type, "GRAND_MASTER") == 0)
    {
        JediType temp;
        temp = JediType::GRAND_MASTER;
        return temp;
    }
}
void cmdblock()
{
    Universe milkyWay;
    cout << "Welcome to Star Wars" << endl;
    cout << "Made by Denis Bakir 1MI0800176" << endl;
    cout << "List of available commands:" << endl;
    cout << "add_planet - to add a planet" << endl;
    cout << "create_jedi - to create jedi on a existing planet" << endl;
    cout << "removeJedi - to remove jedi on a existing planet" << endl;
    cout << "promote_jedi - to promote a existing jedi" << endl;
    cout << "demote_jedi - to demote a existing jedi" << endl;
    cout << "get_strongest_jedi - to see info about the strongest jedi on a planet" << endl;
    cout << "get_most_used_saber_color - to see the most used saber color on a planet" << endl;
    cout << "print - to see info about planet or jedi, etc." << endl;
    cout << "+ - to see the combined information about two planets" << endl;
    cout << "exit - to end the game" << endl;
    cout << "ATTENTION!!! THE PERSON WHO IS WORKING WITH THE PROGRAM IS OBLIGED TO PROVIDE RIGHT VALUES TO THE VARIABLES" << endl;
    while (true)
    {
        cout << "Please select your command: ";
        char command[100];
        cin.getline(command, 100);
        if (strcmp(command, "exit") == 0)
        {
            cout << "See you soon!" << endl;
            break;
        }
        else if (strcmp(command, "add_planet") == 0)
        {
            cout << "In order to add planet type planet name: " << endl;
            char name[50];
            cin.getline(name, 50);
            milkyWay.addPlanet(name);
        }
        else if (strcmp(command, "create_jedi") == 0)
        {
            char nameOfJedi[64];

            int age;
            char colorOfSword[20];
            double power;
            cout << "Name of planet: " << endl;
            char nameofPlanet[64];
            cin.getline(nameofPlanet, 64);
            cout << "Name of jedi: " << endl;
            cin.getline(nameOfJedi, 64);
            cout << "Type of jedi: " << endl;
            cout << "Type might be YOUNGLING = 0, INITIATE = 1,PADAWAN = 2, KNIGHTASPIRANT = 3, KNIGHT = 4, MASTER = 5, BATTLE_MASTER = 6, GRAND_MASTER = 7" << endl;
            char _type[64];
            cin.getline(_type, 64);
            while (strcmp(_type, "YOUNGLING") != 0 && strcmp(_type, "INITIATE") != 0 && strcmp(_type, "PADAWAN") != 0 && strcmp("KNIGHTASPIRANT", _type) != 0 && strcmp(_type, "KNIGHT") != 0 && strcmp(_type, "MASTER") && strcmp(_type, "BATTLE_MASTER") != 0 && strcmp(_type, "GRAND_MASTER") != 0)
            {

                cout << "Wrong rank" << endl;
                cin.getline(_type, 20);

            }
            cout << "Age of jedi: " << endl;
            cin >> age;
            cout << "Color of the sword of jedi: " << endl;
            cout << "Color of sword might be- Red,Blue,Green,Yellow,Purple,White" << endl;
            cin.ignore();
            cin.getline(colorOfSword, 20);
            while (strcmp(colorOfSword, "Red") != 0 && strcmp(colorOfSword, "Blue") != 0 && strcmp(colorOfSword, "Green") != 0 && strcmp(colorOfSword, "Yellow") != 0 && strcmp(colorOfSword, "Purple") != 0 && strcmp(colorOfSword, "White") != 0)
            {
                
                cout << "Wrong color" << endl;
                cin.getline(colorOfSword, 20);
               
            }
            cout << "Strength of Jedi: ";
            cin >> power;
            cin.ignore();
            milkyWay.createJedi(nameofPlanet, nameOfJedi, converter(_type), age, colorOfSword, power);
        }
        else if (strcmp(command, "removeJedi") == 0)
        {
            cout << "In order to remove a jedi type planet name and name of jedi: " << endl;
            char nameJedi[50];
            char namePlanet[50];

            cout << "jedi name:  " << endl;
            cin.getline(nameJedi, 50);
            cout << "planet name:  " << endl;
            cin.getline(namePlanet, 50);
            milkyWay.removeJedi(namePlanet, nameJedi);

        }
        else if (strcmp(command, "demote_jedi") == 0)
        {
            ;
            cout << "In order to demote jedi type name of jedi and multiplier" << endl;
            char name[50];
            cout << "type the name of Jedi: " << endl;
            cin.getline(name, 50);
            double multiplier;
            cout << "multiplier: " << endl;
            cin >> multiplier;
            ;
            cin.ignore();
            milkyWay.demote(name, multiplier);
        }
        else if (strcmp(command, "promote_jedi") == 0)
        {
            ;
            cout << "In order to promote jedi type name of jedi and multiplier" << endl;
            char name[50];
            cout << "type the name of Jedi: " << endl;
            cin.getline(name, 50);
            double multiplier;
            cout << "multiplier: " << endl;
            cin >> multiplier;
            cin.ignore();
            milkyWay.promote(name, multiplier);
        }
        else if (strcmp(command, "get_youngest_jedi") == 0)
        {
            cout << "Type name of planet:" << endl;
            char name[50];
            cin.getline(name, 50);
            JediType asd;


            cout << "Type jedi rank: " << endl;
            cout << "Type might be YOUNGLING = 0, INITIATE = 1,PADAWAN = 2, KNIGHTASPIRANT = 3, KNIGHT = 4, MASTER = 5, BATTLE_MASTER = 6, GRAND_MASTER = 7" << endl;

            char _type[64];
            cin.getline(_type, 64);
            while (strcmp(_type, "YOUNGLING") != 0 && strcmp(_type, "INITIATE") != 0 && strcmp(_type, "PADAWAN") != 0 && strcmp("KNIGHTASPIRANT", _type) != 0 && strcmp(_type, "KNIGHT") != 0 && strcmp(_type, "MASTER") && strcmp(_type, "BATTLE_MASTER") != 0 && strcmp(_type, "GRAND_MASTER") != 0)
            {

                cout << "Wrong rank" << endl;
                cin.getline(_type, 20);

            }
            milkyWay.getYoungestJedi(name, converter(_type));
        }
        else if (strcmp(command, "get_strongest_jedi") == 0)
        {
            cout << "Type name of planet:" << endl;
            char name[50];
            cin.getline(name, 50);
            milkyWay.getStrongestJedi(name);
        }
        else if (strcmp(command, "get_most_used_saber_color") == 0)
        {
            cout << "Type name of planet:" << endl;
            char name[50];
            cin.getline(name, 50);
            cout << "DO YOU WANT TO SORT YOUR SEARCH BY JEDI RANK?" << endl << "possible answers: YES / NO" << endl;
            char temp[5];
            cin.getline(temp, 5);
            ;
            if (strcmp(temp, "YES") == 0)
            {
                JediType asd;

                cout << "Type jedi rank: " << endl;
                cout << "Type might be YOUNGLING = 0, INITIATE = 1,PADAWAN = 2, KNIGHTASPIRANT = 3, KNIGHT = 4, MASTER = 5, BATTLE_MASTER = 6, GRAND_MASTER = 7" << endl;

                char _type[64];
                cin.getline(_type, 64);
                while (strcmp(_type, "YOUNGLING") != 0 && strcmp(_type, "INITIATE") != 0 && strcmp(_type, "PADAWAN") != 0 && strcmp("KNIGHTASPIRANT", _type) != 0 && strcmp(_type, "KNIGHT") != 0 && strcmp(_type, "MASTER") && strcmp(_type, "BATTLE_MASTER") != 0 && strcmp(_type, "GRAND_MASTER") != 0)
                {

                    cout << "Wrong rank" << endl;
                    cin.getline(_type, 20);

                }
                cout << "Most used saber color: " << milkyWay.getMostUsedSaberColor(name, converter(_type)) << endl;

            }
            else if (strcmp(temp, "NO") == 0)
            {
                cout << "Most used saber color: " << milkyWay.getMostUsedSaberColor(name) << endl;;
            }
            else
            {
                cout << "Wrong command" << endl;
            }
        }
        else if (strcmp(command, "print") == 0)
        {
        
            cout << "Do you want to print a single jedi info or whole planet info?" << endl << "Possible answers: JEDI / PLANET ." << endl;
            char cmd[10];
            cin.getline(cmd, 10);
            if (strcmp(cmd, "JEDI") == 0)
            {
                char jediname[50];
                cout << "Pick jedi name: " << endl;
                cin.getline(jediname, 50);

                milkyWay.printJedi(jediname);
            }
            else if (strcmp(cmd, "PLANET") == 0)
            {
                char planetname[50];
                cout << "Pick planet name: " << endl;
                cin.getline(planetname, 50);
                milkyWay.printInfo(planetname);
            }
            else
            {
                cout << "Wrong command" << endl;
            }
        }
        else if (strcmp(command, "+") == 0)
        {
            char name1[50];
            char name2[50];
            cout << "Type name for planet 1: " << endl;
            cin.getline(name1, 50);
            cout << "Type name for planet 2: " << endl;
            cin.getline(name2, 50);
            milkyWay.add(name1, name2);
        }
        else
        {
        cout << "Wrong cmd" << endl;
        }
    }

}