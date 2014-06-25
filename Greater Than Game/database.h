/*
 * Database Header Implementation
 * Ariane Krumel
 * Created 5/21/14
 *
 */

#ifndef __Greater_Than_Game__database__
#define __Greater_Than_Game__database__
#include <vector>
#include "player.h"

using namespace std;

class Database {
private:
    vector<Player> roster;
    int size;
    
public:
    // Constructors
    Database ();
    
    // Accessor and Mutators
    int getSize();
    
    // More methods
    void display(string type);
    void add(Player newPlayer);
    void remove(int position);
    Player retrieve(int position);
};

#endif
