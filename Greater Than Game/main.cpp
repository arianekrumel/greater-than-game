/*
 * Greater Than Game
 * Ariane Krumel
 * Created 5/14/14
 *
 */

# include <iostream>
#include "database.h"
#include "player.h"
#include <cstdlib>
#include <locale>

using namespace std;

int main()
{
    /*
     * Variable initiatization
     */
    // General menu variables
    string option = "";
    string name = "";
    string email = "";
    string ageString = "";
    int age = 0;
    string genderString = "";
    char gender = ' ';
    Database allPlayers;
    bool quit = false;
    
    while(!quit){
        
        /*
         * General Menu
         */
        // Display general menu
        cout << "StayfitBrain\n";
        cout << "  1. Add a Player\n  2. List players\n  3. Play Game\n  4. Retrieve Player\n Q. Quit\n";
        getline(cin, option);
        
        // Validate length of input
        while (option.length() > 1)
        {
            cout << "Please enter just one character.\n";
            getline(cin, option);
        }
        
        if( option[0] == '1')
        {
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
            while(ageString.length() < 1)
            {
                cout << "Cannot be blank. Age: ";
                getline(cin, ageString);
            }
            age = atoi(ageString.c_str());
            
            cout << "Gender (M/F): ";
            getline(cin, genderString);
            while(genderString.length() != 1)
            {
                cout << "Must be one character. Gender: ";
                getline(cin, genderString);
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
        else if( option[0] == '2')
        {
            // Check if database is empty
            if(allPlayers.getSize() == 0)
            {
                cout << "Sorry, no players are registered currently.\n\n";
            }
            else
            {
                // Show all registered players
                cout << "All Registered Players (in order of entry): ";
                allPlayers.display();
                cout << "\n\n";
            }
        }
        else if( option[0] == '3')
        {
            // Start new game
            
            // Game variables
            string gameInput = "";
            int numQs = 0;
            int numLs = 0;
            int numEs = 0;
            int numRs = 0;
            bool quitGame = false;
            string gameMenu = "Enter a letter if Left or Right is greater/equal: L  E  R\nQ: Quit\n";
            
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
                            numQs++;
                            numLs++;
                            cout << "\n" << gameMenu;
                            getline(cin, gameInput);
                            break;
                        case 'e':
                            cout << "Answer: " << gameInput << "\n";
                            numQs++;
                            numEs++;
                            cout << "\n" << gameMenu;
                            getline(cin, gameInput);
                            break;
                        case 'r':
                            cout << "Answer: " << gameInput << "\n";
                            numQs++;
                            numRs++;
                            cout << "\n" << gameMenu;
                            getline(cin, gameInput);
                            break;
                            
                            // Process quit request
                        case 'q':
                            // Display total of questions answers
                            cout << "TOTAL " << numQs << " Questions: " << numLs << " L, " << numEs << " E, " << numRs << " R" << "\n";
                            
                            // Confirm quit and exit or return to main menu
                            cout << "\nEnter to Quit.\n";
                            if (cin.get()=='\n')
                            {
                                cout << "Thanks for playing.\n\n";
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
            
        }
        else if( option[0] == '4')
        {
            // Check if database is empty
            if(allPlayers.getSize() == 0)
            {
                cout << "Sorry, no players are registered currently.\n\n";
            } else {
                string requestedPlayer = "";
                cout << "Please enter a name of a registered player: ";
                getline(cin, requestedPlayer);
                
                // Retrieve existing player by name
                Player retrieved = allPlayers.retrieve(requestedPlayer);
                cout << "\nPlayer retrieved:\n";
                cout << "Name: " << retrieved.getName() << "\n";
                cout << "Email: " << retrieved.getEmail() << "\n";
                cout << "Age: " << retrieved.getAge() << "\n";
                cout << "Gender: " << retrieved.getGender() << "\n\n";
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
