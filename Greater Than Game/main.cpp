/*
 * Greater Than Game
 * Ariane Krumel
 * Created 5/14/14
 *
 */

#include <iostream>
#include "database.h"
#include "player.h"
#include <cstdlib>
#include <locale>
#include <map>
#include <fstream>

#include <sstream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

using namespace std;

int playGame(map<string, int> & gameMap)
{
    
    /* Start timer */
    clock_t start, stop;
    double t = 0.0;
    assert((start = clock())!=-1);
    
    cout << "Play Game\n";
    
    // Game variables
    string gameInput = "";
    int numQs = 0;
    int numCorrect = 0;
    bool quitGame = false;
    string gameMenu = "Enter a letter if Left or Right is greater/equal: L  E  R\nQ: Quit\n";
    map<string,int>::iterator itemL;
    string left = "";
    int leftValue = 0;
    map<string,int>::iterator itemR;
    string right = "";
    int rightValue = 0;
    int answer = 0;
    int brainIndex = 0;
    
    // Get expressions
    itemL = gameMap.begin();
    advance( itemL, rand() % 20 + 0 );
    left = itemL->first;
    leftValue = itemL->second;
    
    itemR = gameMap.begin();
    advance( itemR, rand() % 20 + 0 );
    right = itemR->first;
    rightValue = itemR->second;
    
    cout << left << "\t\t" << right << "\n";
    
    // Display menu and retrieve user answer
    cout << gameMenu;
    getline(cin, gameInput);
    
    // Continue asking until user quits
    while (!quitGame){
        
        // Validate length of input
        if (gameInput.length() == 1)
        {
            
            switch ( tolower(gameInput[0]) )
            {
                    // Record valid inputs
                case 'l':
                    cout << "Answer: " << gameInput << "\n";
                    answer = leftValue - rightValue;
                    if(answer > 0)
                    {
                        cout << "Correct\n";
                        numCorrect = numCorrect + 1;
                    }
                    else
                    {
                        cout << "Incorrect\n";
                    }
                    numQs++;
                    cout << "\n";
                    // Get expressions
                    itemL = gameMap.begin();
                    advance( itemL, rand() % 20 + 0 );
                    left = itemL->first;
                    leftValue = itemL->second;
                    
                    itemR = gameMap.begin();
                    advance( itemR,  rand() % 20 + 0 );
                    right = itemR->first;
                    rightValue = itemR->second;
                    
                    cout << left << "\t\t" << right << "\n";
                    cout<< gameMenu;
                    getline(cin, gameInput);
                    break;
                case 'e':
                    cout << "Answer: " << gameInput << "\n";
                    answer = leftValue - rightValue;
                    if(answer == 0)
                    {
                        cout << "Correct\n";
                        numCorrect = numCorrect + 1;
                    }
                    else
                    {
                        cout << "Incorrect\n";
                    }
                    numQs++;
                    cout << "\n";
                    // Get expressions
                    itemL = gameMap.begin();
                    advance( itemL, rand() % 20 + 0 );
                    left = itemL->first;
                    leftValue = itemL->second;
                    
                    itemR = gameMap.begin();
                    advance( itemR,  rand() % 20 + 0 );
                    right = itemR->first;
                    rightValue = itemR->second;
                    
                    cout << left << "\t\t" << right << "\n";
                    cout<< gameMenu;
                    getline(cin, gameInput);
                    break;
                case 'r':
                    cout << "Answer: " << gameInput << "\n";
                    answer = leftValue - rightValue;
                    if(answer < 0)
                    {
                        cout << "Correct\n";
                        numCorrect = numCorrect + 1;
                    }
                    else
                    {
                        cout << "Incorrect\n";
                    }
                    numQs++;
                    cout << "\n";
                    // Get expressions
                    itemL = gameMap.begin();
                    advance( itemL, rand() % 20 + 0 );
                    left = itemL->first;
                    leftValue = itemL->second;
                    
                    itemR = gameMap.begin();
                    advance( itemR,  rand() % 20 + 0 );
                    right = itemR->first;
                    rightValue = itemR->second;
                    
                    cout << left << "\t\t" << right << "\n";
                    cout<< gameMenu;
                    getline(cin, gameInput);
                    break;
                    
                    // Process quit request
                case 'q':
                    // Display total of questions answers
                    cout << "Number of questions: " << numQs << "\t" << "Score: " << numCorrect << "\n";
                    brainIndex = numCorrect * 1000;
                    cout << "Brain index is: " << brainIndex << "\n";
                    
                    // Confirm quit and exit or return to main menu
                    cout << "Enter to return to main menu.";
                    if (cin.get()=='\n')
                    {
                        cout << "Thanks for playing!\n";
                        quitGame = true;
                    }
                    else
                    {
                        cout << "\n" << gameMenu;
                        getline(cin, gameInput);
                    }
                    break;
                    
                default:
                    // If incorrect character, give error and return to menu
                    cout << "Error. Invalid option (character). Select L - E - R.\n";
                    getline(cin, gameInput);
            }
            
        }
        
        else
        {
            // If incorrect length, give error and return to menu
            cout << "Error. Invalid option (length). Select L - E - R.\n";
            getline(cin, gameInput);
        }
        
    }
    
    /* Stop timer */
    stop = clock();
    t = (double) (stop-start)/CLOCKS_PER_SEC;
    
    return brainIndex;
}

void addPlayer(Database & allPlayers)
{
    // General menu variables
    string option = "";
    string name = "";
    string email = "";
    string ageString = "";
    int age = 0;
    string genderString = "";
    char gender = ' ';
    
    // Request new player basic data
    cout << "Please enter your basic data. \n";
    cout << "Name: ";
    getline(cin, name);
    while(name.length() < 1)
    {
        cout << "Cannot be blank. Name: ";
        getline(cin, name);
    }
    
    cout << "Email: ";
    getline(cin, email);
    while(email.length() < 1)
    {
        cout << "Cannot be blank. Email: ";
        getline(cin, email);
    }
    
    cout << "Age: ";
    getline(cin, ageString);
    age = atoi(ageString.c_str());
    while(age <= 0 || age > 100)
    {
        cout << "Please enter valid integer (1-100). Age: ";
        getline(cin, ageString);
        age = atoi(ageString.c_str());
    }
    
    cout << "Gender (M/F): ";
    getline(cin, genderString);
    while((genderString.length() != 1) || (genderString != "M" && genderString != "m" && genderString != "F" && genderString != "f"))
    {
        if(genderString.length() != 1)
        {
            cout << "Must be one character. Gender: ";
            getline(cin, genderString);
        }
        if(genderString != "M" && genderString != "m" && genderString != "F" && genderString != "f")
        {
            cout << "Must be characters M or F. Gender: ";
            getline(cin, genderString);
        }
    }
    gender = toupper(genderString[0]);
    
    // Create new player object
    Player newPlayer (name, email, age, gender);
    
    // Add new player to database
    allPlayers.add(newPlayer);
    
    // Display confirmation
    cout << "Player created and added: ";
    cout << newPlayer.display() << "\n\n";
}

int main()
{
    // Create game map
    map<string, int> gameMap;
    
    // Read file for all expressions
    string expression = "";
    ifstream infile;
    infile.open("num_exp.txt");
    getline(infile, expression);
    
    while (expression.compare("END") != 0)
    {
        // Add each expression to map
        int pos = expression.find(",");
        string first = expression.substr(0,pos);
        expression.erase(0, pos);
        string secondString = expression.substr(1);
        int second = atoi(secondString.c_str());
        gameMap.insert( pair<string,int>(first,second) );
        
        getline(infile, expression);
    }
    infile.close();
    
    /*
     * Variable initiatization
     */
    // General menu variables
    string option = "";
    int selectedPlayer = 0;
    string selectedPlayerString = "";
    Database allPlayers;
    bool quit = false;
    
    while(!quit){
        
        /*
         * General Menu
         */
        // Display general menu
        cout << "StayfitBrain\n";
        cout << "  1. Select Player\n  2. Add a Player\n  3. Remove a player\n  4. Retrieve Player\n  5. List players\n  6. Play Game\n  Q. Quit\nOption: ";
        getline(cin, option);
        
        // Validate length of input
        while (option.length() > 1)
        {
            cout << "Please enter just one character.\n";
            getline(cin, option);
        }
        
        if( option[0] == '1')
        {
            /*
             * Select a Player Option
             */
            
            // Check if database is empty
            if(allPlayers.getSize() == 0)
            {
                cout << "Sorry, no players are registered currently.\n\n";
            }
            else
            {
                // Select a player
                cout << "Select a Player:\n";
                allPlayers.display("numbered");
                cout << "I select player #: ";
                getline(cin, selectedPlayerString);
                selectedPlayer = atoi(selectedPlayerString.c_str());
                cout << "Selected Player: " << allPlayers.retrieve(selectedPlayer).getName() << "\n\n";
            }
            
        }
        else if( option[0] == '2')
        {
            /*
             * Add a Player Option
             */
            addPlayer(allPlayers);
        }
        else if( option[0] == '3')
        {
            /*
             * Remove a Player Option
             */
            if(allPlayers.getSize() != 0)
            {
                // Show all registered players
                cout << "Remove a Player:\n";
                allPlayers.display("numbered");
                cout << "I select player #: ";
                getline(cin, selectedPlayerString);
                selectedPlayer = atoi(selectedPlayerString.c_str());
                allPlayers.remove(selectedPlayer);
                cout << "Player #" << selectedPlayer << " removed!\n\n";
            }
            else if(allPlayers.getSize() == 0)
            {
                cout << "Sorry, no players are registered currently.\n\n";
            }
            
        }
        else if( option[0] == '4')
        {
            /*
             * Retrieve a Player Option
             */
            // Retrieve a player
            if(selectedPlayer != 0 && allPlayers.getSize() != 0)
            {
                Player retrievedPlayer = allPlayers.retrieve(selectedPlayer);
                cout << "  Name: " << retrievedPlayer.getName() << "\n";
                cout << "  Email: " << retrievedPlayer.getEmail() << "\n";
                cout << "  Gender: " << retrievedPlayer.getGender() << "\n";
                cout << "  Age: " << retrievedPlayer.getAge() << "\n\n";
            }
            else if(allPlayers.getSize() == 0)
            {
                cout << "Sorry, no players are registered currently.\n\n";
            }
            else 
            {
                cout << "Please select a player to view their information.\n\n";
            }
        }
        else if( option[0] == '5')
        {
            /* 
             * Display all players by ranking
             */
            
            // Check if database is empty
            if(allPlayers.getSize() == 0)
            {
                cout << "Sorry, no players are registered currently.\n\n";
            }
            else 
            {
                // Show all registered players
                cout << "Rank: Players listed by score\n";
                allPlayers.display("score");
                cout << "\n";
            }
        }
        else if( option[0] == '6')
        {
            // Play game a player
            if(selectedPlayer != 0 && allPlayers.getSize() != 0)
            {
                
                Player gamePlayer = allPlayers.retrieve(selectedPlayer);
                allPlayers.remove(selectedPlayer);
                
                // Clear screen
                cout << string( 100, '\n' );
                
                // Start new game
                int score = playGame(gameMap);
                
                // Save score
                gamePlayer.setScore(score);              
                allPlayers.add(gamePlayer);
                cout << "Current player, " << gamePlayer.getName() << ", score reset to: " << gamePlayer.getScore() << "\n\n";
                
            }
            else if(allPlayers.getSize() == 0)
            {
                cout << "Sorry, no players are registered currently.\n\n";
            }
            else 
            {
                cout << "Please select a player to play game.\n\n";
            }
            
        }
        else if( option[0] == 'q' || option[0] == 'Q')
        {
            // Quit game
            quit = true;
            cout << "Goodbye!\n";
        }
        else
        {
            // If invalid, go back to general menu
            cout << "Invalid entry. Return to general menu.\n\n";
        }
        
    }
    
    return 0;
}