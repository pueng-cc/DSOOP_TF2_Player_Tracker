

#pragma once

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include "Player.h"

using namespace std;


///
/// \brief Default Constructor for the Container class
/// \details <b>Details</b>
///
/// This is the default constructor methode used by the 
/// Container objects on instantiation.
/// It currently does no special instantiation of any kind.
///
/// \param input - This methode takes no inputs.
///
/// \return - This methode returns nothing.
///
class Container
{
private:
	std::vector <Player> containerVector;
	std::vector <Player>::iterator myVectorIter;

public:

	//Constructors
	Container(void);
	//container(File stuffs);	//For reading in from a file.

	//Destructor
	~Container();

	//Mutators
	bool AddToContainer(Player newPlayer);			//Will add a player class to the Container.
	bool CreateNewPlayer(std::string playerName, std::string playerClass, std::string weaponPrimary, std::string weaponSecondary, std::string weaponMelee, int numberOfHats = 0);	//Takes new input from view class and stores in container.
	bool DeleteFromContainer(std::string playerName);	//Will delete a player class from the Container.
	void DeleteContainer(void);						//Deletes the entire Container.

	//Accesors
	Player* GetByName(std::string searchName);	//Searches for a specific player by name.
	std::string GetPlayerInfo(std::string searchName);	//Returns the players info in a single string.
	std::string SearchByClass(std::string searchClass);	//Searches for players by class.
	std::string SearchByHats(int numOfHats);			//Searches for players by number of hats.

	//Methods.
	bool RetreiveFromFile(void);	//Retreives container information from a file.
	bool StoreInFile(void);			//Stores the container information in a file.

	
	bool CrossFieldValidation(Player playerToValidate);		//Goes through each of he possible cross field validations for the player object.
	
	std::string Container::ReturnContainer(void);
	void DisplayContainer(void);	//Will display the entire list.	//Unused function.
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