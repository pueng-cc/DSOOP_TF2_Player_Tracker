#include "UI.h"

UI::UI(Container *newContainer)
{
	theContainer = newContainer;
}

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
		printf("Name: %s\n", newName.c_str());
		printf("Class: %s\n", newPlayerClass.c_str());
		printf("Primary Weapon: %s\n", newPrimaryWeapon.c_str());
		printf("Secondary Weapon: %s\n", newSecondaryWeapon.c_str());
		printf("Melee Weapon: %s\n", newMeleeWeapon.c_str());
		printf("Number of Hats: %d\n", newNumberOfHats);
		printf("\n");
		printf("User number key to select menu item.\n");

		userMenuInput = getch();
		cin.clear();
		fflush(stdin);
		if (userMenuInput == '1')
		{
			system("CLS");
			printf("Enter Name: ");
			getline(cin, newName);
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
			getline(cin, newPrimaryWeapon);
		}
		else if (userMenuInput == '4')
		{
			system("CLS");
			printf("Enter Secondary Weapon: ");
			getline(cin, newSecondaryWeapon);
		}
		else if (userMenuInput == '5')
		{
			system("CLS");
			printf("Enter Melee Weapon: ");
			getline(cin, newMeleeWeapon);
		}
		else if (userMenuInput == '6')
		{
			system("CLS");
			printf("Enter Number of Hats: ");
			getline(cin, newNumberOfHatsStringBuffer);
			newNumberOfHats = atoi(newNumberOfHatsStringBuffer.c_str());
		}
		else if (userMenuInput == '9')
		{
			try
			{
				complete = theContainer->ConvertInputToPlayer(newName, newPlayerClass, newPrimaryWeapon, newSecondaryWeapon, newMeleeWeapon, newNumberOfHats);
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
			catch(string exceptionMessage)
			{
				system("CLS");
				printf("Error: \n", exceptionMessage.c_str());
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

void UI::DeletePlayerUI()
{

}

void UI::SearchPlayerUI()
{
}

void UI::DisplayDatabaseUI()
{
}

void UI::DeleteDatabaseUI()
{
}

void UI::GenerateRandomPlayersUI()
{
}

void UI::UIDriver()
{
	MainMenuUI();
}
