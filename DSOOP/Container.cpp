#include "Container.h"



//Constructor
Container::Container()
{

}


//Destructor
Container::~Container()
{

}



//Adds a single item to the list.
void Container::AddToContainer(Player newPlayer)
{
	containerVector.push_back(newPlayer);
}


//Deletes the entire list.
void Container::DeleteContainer(void)
{
	containerVector.clear();
}


Player Container::SearchByName(string searchName)
{
	Player searchResult;
	bool foundItem = false;
	int iterCount = 0;

	myVectorIter = containerVector.begin();	//Set iterator to the first element of our list.
	while ((myVectorIter != containerVector.end()) && (foundItem != true))	//Go until the end of list.
	{

		if (myVectorIter->GetName().compare(searchName) == 0)	//Compare the name field to the attribute passed in.
		{
			searchResult = containerVector[iterCount];
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