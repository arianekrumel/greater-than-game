Greater Than Game
=================

What is it?
-----------

This program code is a simple game development project. It provides a player 
  menu to add, delete and select players with information stored on username, 
  age, email, gender and scores. The featured game compares a pair of expressions.


Design Process
--------------

* The main program (main.cpp) is built with a single method called
  main encapsulating the user interface of the project with helper secondary
  methods for some functionality such as game play.

* The Player class (player.h and player.cpp) contains private variables for all 
  basic user information, accessor methods, constructors and utility methods such 
  as display. 

* The Database class (database.h and database.cpp) is based on a vector container 
  to hold Player objects.


Running Instructions
--------------------
  
In terminal, run the following statement to compile all files:<br />
<code>$ g++ -o main main.cpp database.cpp player.cpp</code>

Then, run the following statement to run the program:<br />
<code>$ main</code>
  
The Stayfit Brain game first presents as a general menu.
* Select 1 to select a registered player.<br />
    Provides a numbered list of all registered players.<br />
    Allows user to select a player for gameplay and information retrieval by 
    number.<br />
    Will give error message if database currently has no players.<br />
* Select 2 to add a new player.<br />
    Will give error message if given blank name.<br />
    Will give error message if given blank email.<br />
    Will give error message if invalid integer for age.<br />
    Will give error message if not given one character for gender.<br />
* Select 3 to remove a player.<br />
    Provides a numbered list of all registered players.<br />
    Will give error message if database currently has no players 
    registered.<br />
* Select 4 to retrieve basic information on currently selected player.<br />
    Provides the name, email, gender and age of current selected player.<br />
    Will give error message if database currently has no players 
    registered.<br />
    Will give error message if no player is currently selected.<br />
    Must search for a player that exists in database.<br />
* Select 5 to list all players in order of score.<br />
    Will give error message if database currently has no players 
    registered.<br />
* Select 6 to play game.<br />
    Provides interface for gameplay.<br />
    Updates currently selected player with recent score.<br />
    Will give error message if player is not registered.<br />
* Select Q to quit program.<br />

Upon selecting the 6th option, the game menu will start and present
   a new menu of options.<br />
* Select L, E or R to submit and save valid answer<br />
* Select Q to call up quit confirmation dialog where player can press<br />
   "Enter" to quit game and return to general menu<br />
