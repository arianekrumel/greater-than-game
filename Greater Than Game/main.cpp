/*
 * Greater Than Game
 * Ariane Krumel
 * Created 5/14/14
 *
 */

# include <iostream>

using namespace std;

int main() {
    
    // Initialize useful variables
    string ans = "";
    int numQs = 0;
    int numLs = 0;
    int numEs = 0;
    int numRs = 0;
    bool quit = false;
    
    // Display menu and retrieve user answer
    cout << "Enter a letter if Left or Right is greater/equal: L  E  R\nQ: Quit\n";
    cin >> ans;
    
    // Continue asking until user quits
    while (!quit){
        
        // Validate length of input
        if (ans.length() == 1)
        {
            
            switch ( tolower(ans[0]) )
            {
                    // Record valid inputs
                case 'l':
                    cout << "Answer: " << ans << "\n";
                    numQs++;
                    numLs++;
                    cout << "\nEnter a letter if Left or Right is greater/equal: L  E  R\nQ: Quit\n";
                    cin >> ans;
                    break;
                case 'e':
                    cout << "Answer: " << ans << "\n";
                    numQs++;
                    numEs++;
                    cout << "\nEnter a letter if Left or Right is greater/equal: L  E  R\nQ: Quit\n";
                    cin >> ans;
                    break;
                case 'r':
                    cout << "Answer: " << ans << "\n";
                    numQs++;
                    numRs++;
                    cout << "\nEnter a letter if Left or Right is greater/equal: L  E  R\nQ: Quit\n";
                    cin >> ans;
                    break;
                    
                    // Process quit request
                case 'q':
                    // Display total of questions answers
                    cout << "TOTAL " << numQs << " Questions: " << numLs << " L, " << numEs << " E, " << numRs << " R" << "\n";
                    
                    // Confirm quit and exit or return to main menu
                    cout << "\nEnter to Quit.\n";
                    cin.get();
                    if (cin.get()=='\n')
                    {
                        cout << "Goodbye!\n";
                        quit = true;
                    }
                    else
                    {
                        cout << "\nEnter a letter if Left or Right is greater/equal: L  E  R\nQ: Quit\n";
                        cin >> ans;
                    }
                    break;
                    
                default:
                    // If incorrect character, give error and return to menu
                    cout << "Error. Invalid option (character). Select L - E - R.\n";
                    cin >> ans;
            }
            
        }
        
        else
        {
            // If incorrect length, give error and return to menu
            cout << "Error. Invalid option (length). Select L - E - R.\n";
            cin >> ans;
        }
        
    }
    
    return 0;
}
