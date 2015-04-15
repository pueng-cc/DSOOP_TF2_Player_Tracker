#pragma once

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
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
	bool AddToContainer(Player newPlayer);			//Will add a player class to the list.
	bool CreateNewPlayer(string playerName, string playerClass, string weaponPrimary, string weaponSecondary, string weaponMelee, int numberOfHats = 0);
	void DeleteFromContainer(string playerName);	//Will delete a player class from the list.
	void DeleteContainer(void);						//Deletes the entire list.

	//Accesors
	Player* SearchByName(string searchName);	//Searches for a specific player by name.
	string SearchByClass(string searchClass);	//Searches for players by class.
	string SearchByHats(int numOfHats);			//Searches for players by number of hats.

	//Methods.
	bool retreiveFromFile(void);	//Working on this.
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