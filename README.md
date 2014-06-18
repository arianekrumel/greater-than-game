Greater Than Game
=================

What is it?
-----------

This program code is simple game development project. It provides
a main menu with selction options and tracks valid inputs.


Design Process
--------------

* The main program (main.cpp) is built with a single method 
  encapsulating the user interface of the project. 

* The Player class contains private variables for all basic user 
  information, accessor methods, constructors and utility methods such 
  as display. 

* The Database class is based on a queue container to hold Player objects.


Running Instructions
--------------------
  
In terminal, run the following statement to compile all files:<br />
<code>$ g++ -o main main.cpp database.cpp player.cpp</code>

Then, run the following statement to run the lab:<br />
<code>$ lab2</code>
  
The Stayfit Brain game first presents as a general menu.
* Select 1 to add a new player.<br />
    Will give error message if given blank name.<br />
    Will give error message if given blank email.<br />
    Will give error message if given blank age.<br />
    Will give error message if not given one character for gender.<br />
* Select 2 to list all players in comma-separated list, in order of registration.<br />
    Will give error message if database currently has no players <br />
    registered.<br />
* Select 3 to play game.<br />
    Will give error message if player is not registered.<br />
* Select 4 to retrieve a registered user by name and display all info.<br />
    Will give error message if database currently has no players <br />
    registered.<br />
    Must search for a player that exists in database.<br />
* Select Q to quit program.<br />
   Upon selecting the 3rd option, the game menu will start and present<br />
   a new menu of options.<br />
* Select L, E or R to submit and save valid answer<br />
* Select Q to call up quit confirmation dialog where player can press<br />
   "Enter" to quit game and return to general menu<br />
