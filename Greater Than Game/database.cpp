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
void Database::display()
{
    for (int i=0; i < Database::roster.size(); ++i) {
        cout << Database::roster[i].display() << ", ";
    }
}

void Database::add(Player newPlayer)
{
    Database::size = Database::size + 1;
    Database::roster.push_back(newPlayer);
}

Player Database::retrieve(string name)
{
    Player thisPlayer = Database::roster.front();
    
    for (int i=0; i < Database::roster.size(); ++i) {
        cout << Database::roster[i].display() << ", ";
        if(Database::roster[i].getName() == name){
            thisPlayer = Database::roster.front();
        }
    }
    return thisPlayer;
}
