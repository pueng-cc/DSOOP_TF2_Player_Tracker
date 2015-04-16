// File name:			UI.cpp
// Project:				DSOOP_TF2_Player_Tracker
// Created by:			Ping Chang Ueng
//						Lauchlin Morrison
// Date created:		April 5, 2015
// Description:			Contains all UI elements, including menu, prompting user input, and 
//						display existing data.
#include "UI.h"

///
/// \brief Constructor of UI
/// \details <b>Details</b>
///
/// Requires a pointer to the container so UI can call Container's methods.
///
/// \param newContainer - <b>Container*</b> - The pointer to the container that UI is going to manipulate.
///
/// \return Nothing
///
UI::UI(Container *newContainer)
{
	theContainer = newContainer;
}

///
/// \brief Main Menu
/// \details <b>Details</b>
///
/// Main menu of the program. Loops until user selects "0".
///
/// \return Nothing
///
void UI::MainMenuUI()
{
	char userMenuInput = 0;
	bool complete = false;
	while (complete != true)
	{
		system("CLS");
		printf("Main Menu\n");
		printf("\n");
		printf("1) Add Player\n");
		printf("2) Delete Player\n");
		printf("3) Search Player\n");
		printf("4) Display Database\n");
		printf("5) Delete Database\n");
		printf("6) Generate Random Players\n");
		printf("\n");
		printf("0) Save and Exit\n");
		printf("\n");
		printf("Use number key to select menu items.\n");

		userMenuInput = getch();
		if (userMenuInput == '1')
		{
			AddPlayerUI();
		}
		else if (userMenuInput == '2')
		{
			DeletePlayerUI();
		}
		else if (userMenuInput == '3')
		{
			SearchPlayerUI();
		}
		else if (userMenuInput == '4')
		{
			DisplayDatabaseUI();
		}
		else if (userMenuInput == '5')
		{
			DeleteDatabaseUI();
		}
		else if (userMenuInput == '6')
		{
			GenerateRandomPlayersUI();
		}
		else if (userMenuInput == '0')
		{
			complete = true;
		}

	}
}

///
/// \brief Add player UI
/// \details <b>Details</b>
///
/// Allows user to enter each field of a player's information. Will loop until 
/// the player information is saved to theContainer successfully or if the user 
/// choose to exit by pressing "0".
///
/// \return Nothing
///
void UI::AddPlayerUI()
{
	std::string newName = "";
	std::string newPlayerClass = "";
	std::string newPrimaryWeapon = "";
	std::string newSecondaryWeapon = "";
	std::string newMeleeWeapon = "";
	int newNumberOfHats = 0;
	std::string newNumberOfHatsStringBuffer = "";
	char userMenuInput = 0;
	bool complete = false;


	while (complete != true)
	{
		system("CLS");
		printf("Add Player Menu\n");
		printf("\n");
		printf("1) Edit Name\n");
		printf("2) Edit Class\n");
		printf("3) Edit Primary Weapon\n");
		printf("4) Edit Secondary Weapon\n");
		printf("5) Edit Melee Weapon\n");
		printf("6) Edit Number of Hats\n");
		printf("\n");
		printf("9) Save Player\n");
		printf("0) Return To Main Menu\n");
		printf("\n");
		printf("Current Player Info: \n");
		printf("\n");
		printf("Name:             %s\n", newName.c_str());
		printf("Class:            %s\n", newPlayerClass.c_str());
		printf("Primary Weapon:   %s\n", newPrimaryWeapon.c_str());
		printf("Secondary Weapon: %s\n", newSecondaryWeapon.c_str());
		printf("Melee Weapon:     %s\n", newMeleeWeapon.c_str());
		printf("Number of Hats:   %d\n", newNumberOfHats);
		printf("\n");
		printf("User number key to select menu item.\n");

		userMenuInput = getch();
		std::cin.clear();
		fflush(stdin);
		if (userMenuInput == '1')
		{
			system("CLS");
			printf("Enter Name: ");
			getline(std::cin, newName);
		}
		else if (userMenuInput == '2')
		{
			system("CLS");
			printf("Select a Class: \n");
			printf("1) Scout\n");
			printf("2) Soldier\n");
			printf("3) Pyro\n");
			printf("4) Demoman\n");
			printf("5) Heavy\n");
			printf("6) Engineer\n");
			printf("7) Medic\n");
			printf("8) Sniper\n");
			printf("9) Spy\n");
			userMenuInput = 0;

			while (userMenuInput < '1' || userMenuInput > '9')
			{
				userMenuInput = getch();

				if (userMenuInput == '1')
				{
					newPlayerClass = "Scout";
				}
				else if (userMenuInput == '2')
				{
					newPlayerClass = "Soldier";
				}
				else if (userMenuInput == '3')
				{
					newPlayerClass = "Pyro";
				}
				else if (userMenuInput == '4')
				{
					newPlayerClass = "Demoman";
				}
				else if (userMenuInput == '5')
				{
					newPlayerClass = "Heavy";
				}
				else if (userMenuInput == '6')
				{
					newPlayerClass = "Engineer";
				}
				else if (userMenuInput == '7')
				{
					newPlayerClass = "Medic";
				}
				else if (userMenuInput == '8')
				{
					newPlayerClass = "Sniper";
				}
				else if (userMenuInput == '9')
				{
					newPlayerClass = "Spy";
				}
			}
			userMenuInput = 0;
		}
		else if (userMenuInput == '3')
		{
			system("CLS");
			printf("Enter Primary Weapon: ");
			getline(std::cin, newPrimaryWeapon);
		}
		else if (userMenuInput == '4')
		{
			system("CLS");
			printf("Enter Secondary Weapon: ");
			getline(std::cin, newSecondaryWeapon);
		}
		else if (userMenuInput == '5')
		{
			system("CLS");
			printf("Enter Melee Weapon: ");
			getline(std::cin, newMeleeWeapon);
		}
		else if (userMenuInput == '6')
		{
			system("CLS");
			printf("Enter Number of Hats: ");
			getline(std::cin, newNumberOfHatsStringBuffer);
			newNumberOfHats = atoi(newNumberOfHatsStringBuffer.c_str());
		}
		else if (userMenuInput == '9')
		{
			try
			{
				complete = theContainer->CreateNewPlayer(newName, newPlayerClass, newPrimaryWeapon, newSecondaryWeapon, newMeleeWeapon, newNumberOfHats);
				if (complete == true)
				{
					system("CLS");
					printf("Player has been added to the container!\n");
					printf("\n");
					printf("Press any key to continue.\n");
					getch();
				}
				else
				{
					system("CLS");
					printf("Why didn't this error throw an exception?\n");
					printf("\n");
					printf("Press any key to continue.\n");
					getch();
				}
			}
			catch (char* exceptionMessage)
			{
				system("CLS");
				printf("Error: %s\n", exceptionMessage);
				printf("\n");
				printf("Press any key to continue.\n");
				getch();
			}
		}
		else if (userMenuInput == '0')
		{
			complete = true;
		}
	}
}

///
/// \brief Delete player UI
/// \details <b>Details</b>
///
/// Prompts user for a name. Delete entry with matching name from the container.
/// Display whether the entry has been deleted or not.
///
/// \return Nothing
///
void UI::DeletePlayerUI()
{
	std::string nameToDelete = "";
	bool deleteSuccess = false;
	system("CLS");
	printf("Enter Name of the player to be deleted: ");
	std::cin >> nameToDelete;
	deleteSuccess = theContainer->DeleteFromContainer(nameToDelete);
	printf("\n");
	if (deleteSuccess == true)
	{
		printf("Delete Successful.\n");
	}
	else
	{
		printf("Error: Player with matching name cannot be found.\n");
	}
	printf("\n");
	printf("Press any key to continue.\n");
	getch();
}

///
/// \brief Search Player UI
/// \details <b>Details</b>
///
/// Search Player menu to redirect user to one of the search method.
///
/// \return Nothing
///
void UI::SearchPlayerUI()
{
	char userMenuInput = 0;

	while (userMenuInput != '0')
	{
		system("CLS");
		printf("Select Search Parameter\n");
		printf("\n");
		printf("1) Search By Name\n");
		printf("2) Search By Class\n");
		printf("3) Search By Number Of Hats\n");
		printf("\n");
		printf("0) Return to Main Menu\n");
		userMenuInput = getch();
		if (userMenuInput == '1')
		{
			SearchByNameUI();
		}
		else if (userMenuInput == '2')
		{
			SearchByClassUI();
		}
		else if (userMenuInput == '3')
		{
			SearchByNumberOfHatsUI();
		}
	}
}

///
/// \brief Display One Player UI
/// \details <b>Details</b>
///
/// Takes a string that contains a player's info. Parses the string and display the information.
/// pre-parsed format: [name]\n[playerClass]\n[primaryWeapon]\n[secondaryWeapon]\n[meleeWeapon]\n[numberOfHats]
/// parsed format:
/// Name: [name]
/// Class: [playerClass]
/// Primary Weapon: [primaryWeapon]
/// Secondary Weapon: [secondaryWeapon]
/// Melee Weapon: [meleeWeapon]
/// Number of Hats: [numberOfHats]
///
/// \param playerInfo - <b>std::string</b> - unparsed player info
///
/// \return Nothing
///
void UI::DisplayOnePlayerUI(std::string playerInfo)
{
	//string will be returned in "[name]\n[playerClass]\n[primaryWeapon]\n[secondaryWeapon]\n[meleeWeapon]\n[numberOfHats]" format.
	std::string bufferForParsing = playerInfo;
	std::string tempName = "";
	std::string tempPlayerClass = "";
	std::string tempPrimaryWeapon = "";
	std::string tempSecondaryWeapon = "";
	std::string tempMeleeWeapon = "";
	std::string tempNumberOfHats = ""; //going to display it anyway. no need to convert to int.
	size_t nextLineLocation = 0;

	nextLineLocation = bufferForParsing.find("\n");
	tempName = bufferForParsing.substr(0, nextLineLocation);
	bufferForParsing.erase(0, nextLineLocation + 1);

	nextLineLocation = bufferForParsing.find("\n");
	tempPlayerClass = bufferForParsing.substr(0, nextLineLocation);
	bufferForParsing.erase(0, nextLineLocation + 1);

	nextLineLocation = bufferForParsing.find("\n");
	tempPrimaryWeapon = bufferForParsing.substr(0, nextLineLocation);
	bufferForParsing.erase(0, nextLineLocation + 1);

	nextLineLocation = bufferForParsing.find("\n");
	tempSecondaryWeapon = bufferForParsing.substr(0, nextLineLocation);
	bufferForParsing.erase(0, nextLineLocation + 1);

	nextLineLocation = bufferForParsing.find("\n");
	tempMeleeWeapon = bufferForParsing.substr(0, nextLineLocation);
	bufferForParsing.erase(0, nextLineLocation + 1);

	tempNumberOfHats = bufferForParsing;

	printf("Name:             %s\n", tempName.c_str());
	printf("Class:            %s\n", tempPlayerClass.c_str());
	printf("Primary Weapon:   %s\n", tempPrimaryWeapon.c_str());
	printf("Secondary Weapon: %s\n", tempSecondaryWeapon.c_str());
	printf("Melee Weapon:     %s\n", tempMeleeWeapon.c_str());
	printf("Number of Hats:   %d\n", tempNumberOfHats);
}

///
/// \brief Display Many Players UI
/// \details <b>Details</b>
///
/// Takes a string with names of multiple existing players. Parses the names and search each 
/// of the name in theContainer. Calls DisplayOnePlayerUI() for each of the search result.
///
/// \param playerInfo - <b>std::string</b> - unparsed names of players.
///
/// \return Nothing
///
void UI::DisplayManyPlayersUI(std::string allTheNames)
{
	std::string namesToParse = allTheNames;
	std::string nameBuffer = "";
	int nextLineLocation = 0;
	bool allNamesParsed = false;
	int displayCounter = 0;

	while (allNamesParsed == false)
	{
		nextLineLocation = namesToParse.find("\n");
		if (nextLineLocation == -1)
		{
			allNamesParsed = true;
		}
		else
		{
			nameBuffer = namesToParse.substr(0, nextLineLocation);
			DisplayOnePlayerUI(theContainer->GetPlayerInfo(nameBuffer));
			printf("\n");
			namesToParse.erase(0, nextLineLocation + 1);
			displayCounter = displayCounter + 1;
		}
		if (displayCounter == 3 && allNamesParsed == false)
		{
			printf("Press any key to continue.\n");
			printf("\n");
			getch();
			displayCounter = 0;
		}
	}
}

///
/// \brief Search by Name UI
/// \details <b>Details</b>
///
/// This UI will prompt user to enter name of a player. It will then call Container::GetPlayerInfo() to 
/// retrieve info of the player with matching name. If such player exists, it'll call 
/// DisplayOnePlayerUI() to display the info of the player.
///
/// \return Nothing
///
void UI::SearchByNameUI()
{
	std::string nameToSearch = "";
	std::string searchResult = "";
	system("CLS");
	printf("Search By Name\n");
	printf("\n");
	printf("Enter Name: ");
	std::cin >> nameToSearch;
	searchResult = theContainer->GetPlayerInfo(nameToSearch);
	system("CLS");
	if (searchResult.compare("") == 0)
	{
		printf("Error: Player with \"%s\" as name cannot be found\n", nameToSearch);
	}
	else
	{
		DisplayOnePlayerUI(searchResult);
	}
	printf("\n");
	printf("Press any key to continue.\n");
	getch();
}

///
/// \brief Search by Class UI
/// \details <b>Details</b>
///
/// Prompts user to select a class to search with. It will call Container::SearchByClass() to 
/// retrieve a string containing all players with matching class. It will call DisplayManyPlayersUI() 
/// to display the info of all matching players.
///
/// \return Nothing
///
void UI::SearchByClassUI()
{
	std::string classToSearch = "";
	std::string searchResult = "";
	char userMenuInput = 0;
	system("CLS");

	printf("Search By Class\n");
	printf("\n");
	printf("1) Scout\n");
	printf("2) Soldier\n");
	printf("3) Pyro\n");
	printf("4) Demoman\n");
	printf("5) Heavy\n");
	printf("6) Engineer\n");
	printf("7) Medic\n");
	printf("8) Sniper\n");
	printf("9) Spy\n");
	printf("\n");
	printf("Use number key to select\n");

	while (userMenuInput < '1' || userMenuInput > '9')
	{
		userMenuInput = getch();

		if (userMenuInput == '1')
		{
			classToSearch = "Scout";
		}
		else if (userMenuInput == '2')
		{
			classToSearch = "Soldier";
		}
		else if (userMenuInput == '3')
		{
			classToSearch = "Pyro";
		}
		else if (userMenuInput == '4')
		{
			classToSearch = "Demoman";
		}
		else if (userMenuInput == '5')
		{
			classToSearch = "Heavy";
		}
		else if (userMenuInput == '6')
		{
			classToSearch = "Engineer";
		}
		else if (userMenuInput == '7')
		{
			classToSearch = "Medic";
		}
		else if (userMenuInput == '8')
		{
			classToSearch = "Sniper";
		}
		else if (userMenuInput == '9')
		{
			classToSearch = "Spy";
		}
	}
	system("CLS");
	searchResult = theContainer->SearchByClass(classToSearch);
	DisplayManyPlayersUI(searchResult);
	printf("All players with matching class have been displayed.\n");
	getch();
}

///
/// \brief Display Many Players UI
/// \details <b>Details</b>
///
/// Prompts user to enter a number. Calls Container::SearchByHats() to retrieve names of 
/// all players with matching number of hats. Calls DisplayManyPlayersUI() to display info 
/// of all the matching players.
///
/// \return Nothing
///
void UI::SearchByNumberOfHatsUI()
{
	std::string numberOfHatsToSearchString = "";
	std::string searchResult = "";
	int numberOfHatsToSearch = 0;
	system("CLS");
	printf("Search By Name\n");
	printf("\n");
	printf("Enter Name: ");
	std::cin >> numberOfHatsToSearchString;
	numberOfHatsToSearch = atoi(numberOfHatsToSearchString.c_str());
	searchResult = theContainer->SearchByHats(numberOfHatsToSearch);
	system("CLS");
	if (searchResult.compare("") == 0)
	{
		printf("Error: Player with %d hats cannot be found.\n", numberOfHatsToSearch);
	}
	else
	{
		DisplayOnePlayerUI(searchResult);
	}
	printf("All players with matching number of hats have been displayed.\n");
	getch();
}


void UI::DisplayDatabaseUI()
{
	DisplayManyPlayersUI(theContainer->ReturnContainer());
	printf("All players in database have been displayed.\n");
	getch();
}

///
/// \brief Delete Container
/// \details <b>Details</b>
///
/// Calls Container::DeleteContainer() to delete container. Will inform player that the container 
/// has been deleted.
///
/// \return Nothing
///
void UI::DeleteDatabaseUI()
{
	theContainer->DeleteContainer();
	system("CLS");
	printf("Database has been deleted.\n");
	printf("\n");
	printf("Press any key to continue.\n");
	getch();
}

///
/// \brief Generate Random Players
/// \details <b>Details</b>
///
/// Prompts user to enter a number. Generates same amount of random players. Calls Container::CreateNewPlayer() 
/// for each of the new random player. Will inform user how many random players have been added to container.
///
/// There's that very very very slight chance a Heavy would get "smart" in its field. I call hax if that happens.
///
/// \return Nothing
///
void UI::GenerateRandomPlayersUI()
{
	std::string tempName = "";
	std::string tempPlayerClass = "";
	std::string tempPrimaryWeapon = "";
	std::string tempSecondaryWeapon = "";
	std::string tempMeleeWeapon = "";
	int tempNumberOfHats = 0;
	std::string stringBuffer = "";
	int numberOfRandomPlayers = 0;
	int randomPlayerCounter = 0;
	int successCounter = 0;
	int errorCounter = 0;
	bool generateSuccessful = true;

	system("CLS");
	printf("Enter Number of Random Players to Generate: ");
	getline(std::cin, stringBuffer);
	numberOfRandomPlayers = atoi(stringBuffer.c_str());
	system("CLS");
	srand(time(NULL));
	while (randomPlayerCounter < numberOfRandomPlayers)
	{
		tempPlayerClass = RandomPlayerGenerator::RandomPlayerClass();
		tempName = RandomPlayerGenerator::RandomName(tempPlayerClass);
		tempPrimaryWeapon = RandomPlayerGenerator::RandomPrimaryWeapon(tempPlayerClass);
		tempSecondaryWeapon = RandomPlayerGenerator::RandomSecondaryWeapon(tempPlayerClass);
		tempMeleeWeapon = RandomPlayerGenerator::RandomMeleeWeapon(tempPlayerClass);
		tempNumberOfHats = RandomPlayerGenerator::RandomNumberOfHats(tempPlayerClass);
		try
		{
			generateSuccessful = theContainer->CreateNewPlayer(tempName, tempPlayerClass, tempPrimaryWeapon, tempSecondaryWeapon, tempMeleeWeapon, tempNumberOfHats);
		}
		catch (char* exceptionMessage)
		{
			printf("Error: %s\n", exceptionMessage);
		}
		if (generateSuccessful == true)
		{
			successCounter = successCounter + 1;
		}
		else
		{
			errorCounter = errorCounter + 1;
		}
		randomPlayerCounter = randomPlayerCounter + 1;
	}
	printf("Random Player Generation Successful: %d\n", successCounter);
	printf("Random Player Generation Failed: %d\n", errorCounter);
	printf("\n");
	printf("Press any key to continue.\n");
	getch();
}

///
/// \brief Main Driver
/// \details <b>Details</b>
///
/// The public class to be called by main(). Calls Container::RetrieveFromFile() before 
/// displaying the menu. Calls Container::StoreInFile() when user exits the menu.
///
/// \return Nothing
///
void UI::UIDriver()
{
	try
	{
		theContainer->RetreiveFromFile();
	}
	catch (char* exceptionMessage)
	{
		printf("Error: %s", exceptionMessage);
		printf("\n");
		printf("Press any key to continue.\n");
		getch();
	}

	MainMenuUI();

	try
	{
		theContainer->StoreInFile();
	}
	catch (char* exceptionMessage)
	{
		printf("Error: %s", exceptionMessage);
		printf("\n");
		printf("Press any key to continue.\n");
		getch();
	}
}
