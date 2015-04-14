#pragma once

#include <vector>
#include <string>
#include "Player.h"

using namespace std;

class Container
{
private:
	vector <Player> containerVector;
	vector <Player>::iterator myVectorIter;


public:

	//Constructors
	Container(void);
	//container(File stuffs);	//For reading in from a file.

	//Destructor
	~Container();

	//Mutators
	void AddToContainer(Player newPlayer);	//Will add a player class to the list.
	void DeleteFromContainer(Player deletePlayer);	//Will delete a player class from the list.
	void DeleteContainer(void);	//Deletes the entire list.

	//Accesors
	Player SearchByName(string searchName);	//Searches for a specific player. //Could be changed to a char depends on how we get input form the user.
	//SearchByClass(string searchClass)		//Not quite sure how to return a list of them yet. Depends how we do the view layer.
	//SearchByHats(int numOfHats)

	//Methods.
	bool retreiveFromFile(void);	//Working on theis.
	bool storeInFile(void);	
	

	void displayContainer(void);	//Will display the entire list.	//Depends how we do view layer.

};



/*
Needs to be able to:
- Add Item
- Delete item
- delete entire database
- find and display item (Databse will just find it. View layer should display it.)
- Display entire database. (Could be tricky to do only from view layer.)
- load database from file if it exits whenprogram starts.
- add random items (might do this from view layer)
- save database to file. Do this automaticaly when exiting. (Put it in destructor?)
*/