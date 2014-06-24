/*
 * Player Class Header
 * Ariane Krumel
 * Created 5/21/14
 *
 */

#ifndef __Greater_Than_Game__player__
#define __Greater_Than_Game__player__
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class Player {
private:
    string name;
    string email;
    int age;
    char gender;
public:
    // Constructors
    Player();
    Player(string name, string email, int age, char gender);
    
    // Accessor and Mutators
    string getName();
    string getEmail();
    int getAge();
    char getGender();
    
    void setName(string newName);
    void setEmail(string newEmail);
    void setAge(int newAge);
    void setGender(char newGender);
    
    // More methods
    string display();
    // Destructor
    ~Player();
};

#endif /* defined(__Greater_Than_Game__player__) */
