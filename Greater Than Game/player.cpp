/*
 * Player Class Implementation
 * Ariane Krumel
 * Created 5/21/14
 *
 */

#include "player.h"
#include <iostream>

using namespace std;

// Constructors
Player::Player()
{
    Player::name = "";
    Player::email = "";
    Player::age = 0;
    Player::gender = ' ';
}

Player::Player (string name, string email, int age, char gender)
{
    Player::name = name;
    Player::email = email;
    Player::age = age;
    Player::gender = gender;
}

// Accessor and Mutators
string Player::getName()
{
    return name;
}

string Player::getEmail()
{
    return email;
}

int Player::getAge()
{
    return age;
}

char Player::getGender()
{
    return gender;
}

void Player::setName(string newName)
{
    Player::name = newName;
}

void Player::setEmail(string newEmail){
    Player::email = newEmail;
}

void Player::setAge(int newAge){
    Player::age = newAge;
}

void Player::setGender(char newGender){
    Player::gender = newGender;
}

// More Methods
string Player::display()
{
    return name + " (" + email + ")";
}

// Destructors
Player::~Player()
{
}
