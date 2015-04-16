#include "Container.h"



///
/// \class 
/// 
/// \brief Default Constructor for the Container class
/// \details <b>Details</b>
///
/// This class is a database that holds Player objects. It stores each Player in a vector.
/// The Player's are stored in order alphabeticaly. (Using ASCII)
///
/// \param input - This methode takes no inputs.
///
/// \return - This methode returns nothing.
///
Container::Container()
{
	//Nothing happens in Constructor currently.
}


///
/// \brief Destructor for the Container class
/// \details <b>Details</b>
///
/// This methode destroys a Container object that has been instantiated.
/// It cleans up after the object.
///
/// \param input - This methode takes no inputs.
///
/// \return This methode returns nothing.
///
Container::~Container()
{
	//Nothing happens in destructor currently.
}


///
/// \brief Add one new Item to the Container
/// \details <b>Details</b>
///
/// This methode is used to add a single item to the container.
/// It will add the entire class in to the specific spot it belongs in the list based on Player name.
///
/// \param input - <b>Player</b> - This is the new Player object that is to be added to the Container.
///
/// \return - <b>bool</b> - true if the object was added to the Container. false if it was not (Due to duplicate name).
///
bool Container::AddToContainer(Player newPlayer)
{
	bool returnValue = false;		//If it was added to the Container or not.
	bool continueLooping = true;	//Too continue looping or not.

	if (containerVector.size() == 0)
	{
		containerVector.push_back(newPlayer);
		returnValue = true;
	}
	else
	{
		myVectorIter = containerVector.begin();	//Set iterator to the first element of our list.
		while (((continueLooping == true) && myVectorIter != containerVector.end()))	//Go until the end of list.
		{
			if (newPlayer.GetName() < myVectorIter->GetName())		//If the newPlayer goes before what it is looking at it will be added.
			{
				containerVector.insert(myVectorIter, newPlayer);	//Insert the newPlayer
				returnValue = true;
				continueLooping = false;
			}
			else if (newPlayer.GetName() == myVectorIter->GetName())	//If the names are the same return with an error.
			{
				continueLooping = false;
			}

			if (continueLooping == true)	//increment our Iterator value.
			{
				myVectorIter++;
			}			
		}

		if (returnValue == false && continueLooping == true)		//If the newPlayer was not added to the database yet and it is not a duplicate it will be added.
		{
			containerVector.push_back(newPlayer);
			returnValue = true;
		}
	}

	return returnValue;
}

///
/// \brief Creates and adds a new player to the container
/// \details <b>Details</b>
///
/// This methode is used to create and add a single object to the container.
/// It will take input as the diffrent field of the object and use them to fill it in.
///
/// \param input - <b>string</b> - playerName - This is the player's name. Must be original.
/// \param input - <b>string</b> - playerClass - This is the class the player plays.
/// \param input - <b>string</b> - weaponPrimary - This is the players Primary weapon.
/// \param input - <b>string</b> - weaponSecondary - This is the players Secondary weapon.
/// \param input - <b>string</b> - weaponMelee - This is the players Melee weapon.
/// \param input - <b>int</b> -  numberOfHats - This integet represents the number of hats the player owns.
///
/// \return - <b>bool</b> - true if the object was added to the Container. false if it was not.
///
bool Container::CreateNewPlayer(std::string playerName, std::string playerClass, std::string weaponPrimary, std::string weaponSecondary, std::string weaponMelee, int numberOfHats)
{
	Player tempPlayer;
	bool returnValue = true;

	if (tempPlayer.SetName(playerName) == false)	//Validates and adds the name to the tempPlayer.
	{
		returnValue = false;
		throw ("This name is not valid.");
	}

	if (tempPlayer.SetPlayerClass(playerClass) == false)	//Validates and adds the class to the tempPlayer.
	{
		returnValue = false;
		throw ("This class is not valid.");
	}
	
	if (tempPlayer.SetPrimaryWeapon(weaponPrimary) == false)	//Validates and adds the primary to the tempPlayer.
	{
		returnValue = false;
		throw ("This primary weapon is not valid.");
	}
	
	if (tempPlayer.SetSecondaryWeapon(weaponSecondary) == false)	//Validates and adds the secondary  to the tempPlayer.
	{
		throw ("This secondary weapon is not valid.");
		returnValue = false;
	}
	
	if (tempPlayer.SetMeleeWeapon(weaponMelee) == false)	//Validates and adds the melee to the tempPlayer.
	{
		returnValue = false;
		throw ("This melee weapon is not valid.");
	}
	
	if (tempPlayer.SetNumberOfHats(numberOfHats) == false)	//Validates and adds the number of hats to the tempPlayer.
	{
		returnValue = false;
		throw ("This number of hats is not valid.");
	}
	
	//Cross field validation.
	if (CrossFieldValidation(tempPlayer) == false)
	{
		returnValue = false;
	}


	if (AddToContainer(tempPlayer) == false)	//Checks if the tempPlayer was succesfully added to the container.
	{
		returnValue = false;
	}

	return returnValue;
}


///
/// \brief Deletes one Item from the Container
/// \details <b>Details</b>
///
/// This methode will delete a single Item from the Container based on the name.
/// Uses the SearchByName() methode to find the name then deletes is using the iter that gets stored.
///
/// \param input - <b>string</b> - The name of the player you wish to delete gets passed in.
///
/// \return - This methode retuns nothing.
///
bool Container::DeleteFromContainer(std::string playerName)
{
	bool returnValue = false;
	if (GetByName(playerName) != NULL)
	{
		containerVector.erase(myVectorIter);	//Deletes What is at the iter set by the Search methode.
		returnValue = true;
	}

	return returnValue;
}


///
/// \brief Deletes entire Container
/// \details <b>Details</b>
///
/// This methode will delete all contents of the container.
/// Accomplished using the Vector's clear methode.
///
/// \param input - This methode takes no parameters.
///
/// \return - This methode returns nothing.
///
void Container::DeleteContainer(void)
{
	containerVector.clear();
}


///
/// \brief Searches for a player in the Container
/// \details <b>Details</b>
///
/// This methode will search for a player in the Container using their name.
/// As there can only be one of each player name it will return a single name if it exists.
/// It will return NULL other wise as an indication that that player does not exist.
///
/// \param input - <b>string</b> - This is the player name to search for in the Container.
///
/// \return <b>Player*</b> - Will return a pointer to the object if it exists. Otherwise will return NULL.
///
Player* Container::GetByName(std::string searchName)
{
	Player* searchResult = NULL;
	bool foundItem = false;
	int iterCount = 0;

	myVectorIter = containerVector.begin();	//Set iterator to the first element of our list.
	while ((myVectorIter != containerVector.end()) && (foundItem != true))	//Go until the end of list.
	{

		if (myVectorIter->GetName().compare(searchName) == 0)	//Compare the name field to the attribute passed in.
		{
			searchResult = &containerVector[iterCount];
			foundItem = true;	//Change foundItem to true if it is the same.
		}


		if (foundItem != true)	//If the item has been found, skip over the iterIncrement and exit the search while.
		{
			myVectorIter++;
			iterCount++;
		}
	}

	return searchResult;
}

///
/// \brief Gets a the player information
/// \details <b>Details</b>
///
/// This methode will get the players information and return all the fields in a single string.
/// Each field will be delimited by a "\n".
///
/// \param input - <b>string</b> - Takes the class to search for.
///
/// \return <b>string</b> - Will return a string containing the name of each player by that class.
/// \see GetByName()
std::string Container::GetPlayerInfo(std::string searchClass)
{
	std::string returnString;
	Player* tempPlayer = GetByName(searchClass);
	int tempInt = 0;

	if (tempPlayer != NULL)
	{
		returnString.append(tempPlayer->GetName());				//Appends the name and then a new line.
		returnString.append("\n");

		returnString.append(tempPlayer->GetPlayerClass());		//Appends the class and then a new line.
		returnString.append("\n");

		returnString.append(tempPlayer->GetPrimaryWeapon());	//Appends the primary weapon and then a new line.
		returnString.append("\n");

		returnString.append(tempPlayer->GetSecondaryWeapon());	//Appends the secondary weapon and then a new line.
		returnString.append("\n");

		returnString.append(tempPlayer->GetMeleeWeapon());		//Appends the melee weapon and then a new line.
		returnString.append("\n");

		tempInt = tempPlayer->GetNumberOfHats();				//Store the number of hats in an int.
		returnString.append(to_string(tempInt));				//Then Appends the numberOfHats and then a new line. "to_string()" converts the int to a string.
	}

	return returnString;
}

///
/// \brief Gets a list of the players of that class
/// \details <b>Details</b>
///
/// This methode will get a list of all the players that have that number of hats.
/// It will add each name to a list each seperated by a "\n" so the view layer can retreive it.
///
/// \param input - <b>string</b> - Takes the class to search for.
///
/// \return <b>string</b> - Will return a string containing the name of each player by that class.
///
std::string Container::SearchByClass(std::string searchClass)
{
	std::string returnString;
	bool firstMember = true;

	myVectorIter = containerVector.begin();	//Set iterator to the first element of our list.
	while (myVectorIter != containerVector.end())	//Go until the end of list.
	{
		if (myVectorIter->GetPlayerClass() == searchClass)
		{
			if (firstMember == true)
			{
				firstMember = false;
			}
			else
			{
				returnString.append("\n");
			}
			returnString.append(myVectorIter->GetName());
		}
		myVectorIter++;
	}

	return returnString;
}


///
/// \brief Gets a list of the players with n number of hats
/// \details <b>Details</b>
///
/// This methode will get a list of all the players that have n number of hats.
/// It will add each name to a list each seperated by a "\n" so the view layer can read and display them.
///
/// \param input - <b>int</b> - Takes and integer representing the number of hats to search for.
///
/// \return <b>string</b> - Returns a string containing the name of each player with n number of hats.
///
std::string Container::SearchByHats(int numOfHats)
{
	std::string returnString;
	bool firstMember = true;

	myVectorIter = containerVector.begin();	//Set iterator to the first element of our list.
	while (myVectorIter != containerVector.end())	//Go until the end of list.
	{
		if (myVectorIter->GetNumberOfHats() == numOfHats)
		{
			if (firstMember == true)
			{
				firstMember = false;
			}
			else
			{
				returnString.append("\n");
			}
			returnString.append(myVectorIter->GetName());
			
		}
		myVectorIter++;
	}

	return returnString;
}


///
/// \brief Stores the Container to a file
/// \details <b>Details</b>
///
/// This methode will store the content of the Container database to a file in the current directory.
/// It stores each object seperated by a "\n" and each feild of the object is seperated by a "|".
/// If there is no present it will create a new one.
///
/// \param input - This methode takes no parameters.
///
/// \return <b>bool</b> - Will return a true value if the file was succesfully stored. False otherwise.
///
bool Container::StoreInFile(void)
{
	std::fstream dataFile;

	bool returnValue = false;
	bool errorStatus = false;
	int iterCount = 0;

	dataFile.open("LauchlinMor.txt", ios::in | ios::binary);

	if (dataFile.fail())
	{
		dataFile.clear();
		dataFile.open("LauchlinMor.txt", ios::out | ios::binary);
		if (dataFile.fail())
		{
			errorStatus = true;
			throw ("File does not exist!");
		}
	}

	myVectorIter = containerVector.begin();	//Set iterator to the first element of our list.
	while (myVectorIter != containerVector.end())	//Go until the end of list.
	{
		dataFile << myVectorIter->GetName() << "\n";
		dataFile << myVectorIter->GetPlayerClass() << "\n";
		dataFile << myVectorIter->GetPrimaryWeapon() << "\n";
		dataFile << myVectorIter->GetSecondaryWeapon() << "\n";
		dataFile << myVectorIter->GetMeleeWeapon() << "\n";
		dataFile << myVectorIter->GetNumberOfHats() << "\n";

		myVectorIter++;
		iterCount++;
	}

	dataFile.close();

	return returnValue;
}


///
/// \brief Retreive Container from a file
/// \details <b>Details</b>
///
/// This methode will retreive the content of the Container database from a file in the current directory.
///
/// \param input - This methode takes no parameters.
///
/// \return <b>bool</b> - Will return a true value if the file was succesfully retreived. False otherwise.
///
bool Container::RetreiveFromFile(void)
{
	std::fstream dataFile;
	Player tempPlayer;
	std::string attribute;
	int tempNum = 0;


	bool returnValue = false;
	bool errorStatus = false;

	dataFile.open("LauchlinMor.txt", ios::in | ios::binary);

	if (dataFile.fail())
	{
		dataFile.clear();
		dataFile.open("LauchlinMor.txt", ios::out | ios::binary);
		if (dataFile.fail())
		{
			errorStatus = true;
			throw ("File does not exist!");
		}
	}


	while (getline(dataFile, attribute))
	{
		tempPlayer.SetName(attribute);

		getline(dataFile, attribute);
		tempPlayer.SetPlayerClass(attribute);

		getline(dataFile, attribute);
		tempPlayer.SetPrimaryWeapon(attribute);

		getline(dataFile, attribute);
		tempPlayer.SetSecondaryWeapon(attribute);

		getline(dataFile, attribute);
		tempPlayer.SetMeleeWeapon(attribute);

		getline(dataFile, attribute);
		tempNum = atoi(attribute.c_str());
		tempPlayer.SetNumberOfHats(tempNum);

		AddToContainer(tempPlayer);		//Add temp player to the database.
	}

	return returnValue;
}




///
/// \brief Validates a Player object.
/// \details <b>Details</b>
///
/// This methode will validate a Player object passed in to it.
/// It ensures that the cross field validation is valid for all circumstances.
///
/// \param input - <b>Player</b> - This is the player object you wish to validate.
///
/// \return <b>bool</b> - Will return a true value if the validation was succesful. False otherwise.
///
bool Container::CrossFieldValidation(Player playerToValidate)
{
	bool returnValue = true;
	std::string playerClass = playerToValidate.GetPlayerClass();

	if (playerToValidate.MustBeDemoman() == true)
	{
		if (playerToValidate.IsADemoman() == false)
		{
			returnValue = false;
			throw ("If player's name includes \"Smith\", \"Brown\", \"Wilson\", \"Robertson\", or \"Thomson\", the only valid class is Demoman.");
		}
	}
	else
	{
		if (playerClass.compare("Scout") == 0)			//Validate if the player is a scout.
		{
			if (playerToValidate.ValidateScout() == false)
			{
				returnValue = false;
				throw ("Scout's primary weapon must contain \"shotgun\".");
			}
		}
		else if (playerClass.compare("Soldier") == 0)	//Validate if the player is a soldier.
		{
			if (playerToValidate.ValidateSoldier() == false)
			{
				returnValue = false;
				throw ("Soldier's secondary weapon must contain \"shotgun\".");
			}
		}
		else if (playerClass.compare("Pyro") == 0)		//Validate if the player is a pyro.
		{
			if (playerToValidate.ValidatePyro() == false)
			{
				returnValue = false;
				throw ("At least one of Pyro's weapon must contain \"rainbow\".");
			}
		}
		else if (playerClass.compare("Heavy") == 0)		//Validate if the player is a pyro.
		{
			if (playerToValidate.ValidateHeavy() == false)
			{
				returnValue = false;
				throw ("Heavy’s melee weapon can only be [blank], \"fist\", \"fists\", or \"sandvich\". None of its fields can contain \"smart\".");
			}
		}
		else if (playerClass.compare("Engineer") == 0)	//Validate if the player is a pyro.
		{
			if (playerToValidate.ValidateEngineer() == false)
			{
				returnValue = false;
				throw ("One of Engineer’s weapon must contain \"Stool\", \"Chair\", or \"Sittable\"(case sensitive)");
			}
		}
		else if (playerClass.compare("Medic") == 0)		//Validate if the player is a pyro.
		{
			if (playerToValidate.ValidateMedic() == false)
			{
				returnValue = false;
				throw ("The word \"heal\" must appear at least three times across the three weapons of a Medic.");
			}
		}
		else if (playerClass.compare("Sniper") == 0)	//Validate if the player is a pyro.
		{
			if (playerToValidate.ValidateSniper() == false)
			{
				returnValue = false;
				throw ("Sniper has to have at least 5 hats to be valid.");
			}
		}
		else if (playerClass.compare("Spy") == 0)		//Validate if the player is a pyro.
		{
			if (playerToValidate.ValidateSniper() == false)
			{
				returnValue = false;
				throw ("All of Spy's weapons must include the any of the following words: \"Sneaky\", \"Silent\", \"Discreet\".");
			}
		}
		
	}

	return returnValue;
}


///
/// \brief Displays all the container entries
/// \details <b>Details</b>
///
/// This methode will display all container entires in a formated fashion.
/// Normaly this would be done entirly through the View Layer.
///
/// \param input - This methode takes no parameters.
///
/// \return - This methode returns nothing.
///
void Container::DisplayContainer(void)
{
	int count = 0;
	myVectorIter = containerVector.begin();	//Set iterator to the first element of our list.
	while (myVectorIter != containerVector.end())	//Go until the end of list.
	{

		std::cout << "Name             : " << myVectorIter->GetName() << endl;
		std::cout << "Class            : " << myVectorIter->GetPlayerClass() << endl;
		std::cout << "Primary Weapon   : " << myVectorIter->GetPrimaryWeapon() << endl;
		std::cout << "Secondary Weapon : " << myVectorIter->GetSecondaryWeapon() << endl;
		std::cout << "Melee Weapon     : " << myVectorIter->GetMeleeWeapon() << endl;
		std::cout << "Number of Hats   : " << myVectorIter->GetNumberOfHats() << endl << endl;

		count++;
		myVectorIter++;
	}
}


///
/// \brief Returns the entire container
/// \details <b>Details</b>
///
/// This methode will return all the names that are in the container.
/// It appends each name to a string that is then returned. Each name is seperated by a "\n".
///
/// \param input - This methode takes no parameters.
///
/// \return - <b>string<b> - This methode a string of all the names in the database.
///
std::string Container::ReturnContainer(void)
{
	std::string returnString;
	bool firstMember = true;

	myVectorIter = containerVector.begin();	//Set iterator to the first element of our list.
	while (myVectorIter != containerVector.end())	//Go until the end of list.
	{
		if (firstMember == true)
		{
			firstMember = false;
		}
		else
		{
			returnString.append("\n");
		}
		returnString.append(myVectorIter->GetName());
	}

	return returnString;
}