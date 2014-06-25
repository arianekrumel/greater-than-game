/*
 * Database Class Implementation
 * Ariane Krumel
 * Created 5/21/14
 *
 */

#include "database.h"
#include <iostream>

using namespace std;

// Constructors
Database::Database ()
{
    Database::size = 0;
}

// Accessor and Mutators
int Database::getSize()
{
    return size;
}

// More methods
void Database::display(string type)
{
    if(type.compare("default") == 0)
    {
        for (int i=0; i < Database::roster.size(); ++i) {
            cout << Database::roster[i].display() << ", ";
        }
    }
    if(type.compare("numbered") == 0)
    {
        for (int i=0; i < Database::roster.size(); ++i) {
            cout << "  " << i+1 << ". " << Database::roster[i].display() << "\n";
        }
    }
    if(type.compare("score") == 0)
    {
        for (int i=0; i < Database::roster.size(); ++i) {
            cout << "  " << i+1 << ". " << Database::roster[i].display() << "\t" << Database::roster[i].getScore() << "\n";
        }
    }
}

void Database::add(Player newPlayer)
{
    Database::size = Database::size + 1;
    Database::roster.push_back(newPlayer);
}

void Database::remove(int position)
{
    Database::size = Database::size - 1;
    Database::roster.erase (Database::roster.begin()+position-1);
}

Player Database::retrieve(int position)
{
    Player thisPlayer = Database::roster.at(position - 1);
    return thisPlayer;
}