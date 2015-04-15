


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
	bool AddToContainer(Player newPlayer);			//Will add a player class to the Container.
	bool CreateNewPlayer(string playerName, string playerClass, string weaponPrimary, string weaponSecondary, string weaponMelee, int numberOfHats = 0);	//Takes new input from view class and stores in container.
	bool DeleteFromContainer(string playerName);	//Will delete a player class from the Container.
	void DeleteContainer(void);						//Deletes the entire Container.

	//Accesors
	Player* GetByName(string searchName);	//Searches for a specific player by name.
	string GetPlayerInfo(string searchName);	//Returns the players info in a single string.
	string SearchByClass(string searchClass);	//Searches for players by class.
	string SearchByHats(int numOfHats);			//Searches for players by number of hats.

	//Methods.
	bool RetreiveFromFile(void);	//Retreives container information from a file.
	bool StoreInFile(void);			//Stores the container information in a file.

	
	bool CrossFieldValidation(Player playerToValidate);		//Goes through each of he possible cross field validations for the player object.
	

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