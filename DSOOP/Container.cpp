#include "Container.h"



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
Container::Container()
{

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

	if (containerVector.size() < 1)
	{
		containerVector.push_back(newPlayer);
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
void Container::DeleteFromContainer(string playerName)
{
	if (SearchByName(playerName) != NULL)
	{
		containerVector.erase(myVectorIter);	//Deletes What is at the iter set by the Search methode.
	}
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
Player* Container::SearchByName(string searchName)
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



bool Container::storeInFile(void)
{
	ofstream dataFile;

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
			cout << "File does not exist!" << endl;
			errorStatus = true;
		}
	}

	myVectorIter = containerVector.begin();	//Set iterator to the first element of our list.
	while (myVectorIter != containerVector.end())	//Go until the end of list.
	{
		dataFile << containerVector[iterCount];
		myVectorIter++;
		iterCount++;
	}

	dataFile.close();

	return returnValue;
}

bool Container::retreiveFromFile(void)
{
	ifstream dataFile;
	Player tempPlayer;

	bool returnValue = false;
	bool errorStatus = false;

	dataFile.open("LauchlinMor.txt", ios::in | ios::binary);

	if (dataFile.fail())
	{
		dataFile.clear();
		dataFile.open("LauchlinMor.txt", ios::out | ios::binary);
		if (dataFile.fail())
		{
			cout << "File does not exist!" << endl;
			errorStatus = true;
		}
	}

	myVectorIter = containerVector.begin();	//Set iterator to the first element of our list.
	while (!dataFile.eof())	//Go until the end of list.
	{
		dataFile >> tempPlayer;
		AddToContainer(tempPlayer);
	}

	dataFile.close();

	return returnValue;
}




//Temporary function. Sould probably be moved/integrated in the UI portion of the code.
void Container::displayContainer(void)
{
	myVectorIter = containerVector.begin();	//Set iterator to the first element of our list.
	while (myVectorIter != containerVector.end())	//Go until the end of list.
	{

		cout << myVectorIter->GetName() << endl;

		myVectorIter++;
	}
}


ofstream& operator<< (ofstream& output, Player& obj)
{
	output << obj.name << "|" << obj.playerClass << "|" << obj.primaryWeapon << "|" << obj.secondaryWeapon << "|" << obj.meleeWeapon << "|" << obj.numberOfHats << "|\n";
	return output;
}

ifstream& operator>> (ifstream& input, Player& obj)
{
	char fieldBreak;
	input >> obj.name >> fieldBreak >> obj.playerClass >> fieldBreak >> obj.primaryWeapon >> fieldBreak >> obj.secondaryWeapon >> fieldBreak >> obj.meleeWeapon >> fieldBreak >> obj.numberOfHats >> fieldBreak;
	return input;
}