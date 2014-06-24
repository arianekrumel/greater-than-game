/*
 * Database Header Implementation
 * Ariane Krumel
 * Created 5/21/14
 *
 */

#ifndef __Greater_Than_Game__database__
#define __Greater_Than_Game__database__
#include <deque>
#include "player.h"

using namespace std;

class Database {
private:
    deque<Player> roster;
    int size;
    
public:
    // Constructors
    Database ();
    
    // Accessor and Mutators
    int getSize();
    
    // More methods
    void display();
    void add(Player newPlayer);
    Player retrieve(string name);
};

#endif /* defined(__Greater_Than_Game__database__) */