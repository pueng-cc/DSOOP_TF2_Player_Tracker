#include "RandomPlayerGenerator.h"

std::string RandomPlayerGenerator::RandomString(int length)
{
	std::string newRandomString = "";
	int lengthCounter = 0;

	srand(time(NULL));

	newRandomString.resize(length);

	while (lengthCounter < length)
	{
		// 94 + 32
		
		newRandomString[lengthCounter] = rand() % 94 + 32;
		lengthCounter++;
	}

	return newRandomString;
}

std::string RandomPlayerGenerator::RandomName(string playerClass)
{
	std::string newRandomName = "";
	int randomNumber = 0;
	
	newRandomName = RandomString(12);

	if (playerClass.compare("Demoman") == 0)
	{
		
		randomNumber = rand() % 5;
		if (randomNumber == 0)
		{
			newRandomName.append(" Smith");
		}
		else if (randomNumber == 1)
		{
			newRandomName.append(" Brown");
		}
		else if (randomNumber == 2)
		{
			newRandomName.append(" Wilson");
		}
		else if (randomNumber == 3)
		{
			newRandomName.append(" Robertson");
		}
		else if (randomNumber == 1)
		{
			newRandomName.append(" Thomson");
		}
	}
	return newRandomName;
}

std::string RandomPlayerGenerator::RandomPlayerClass()
{
	std::string newRandomClass = "";
	int randomNumber = 0;

	
	randomNumber = rand() % 9;

	if (randomNumber == 0)
	{
		newRandomClass = "Scout";
	}
	else if (randomNumber == 1)
	{
		newRandomClass = "Soldier";
	}
	else if (randomNumber == 2)
	{
		newRandomClass = "Pyro";
	}
	else if (randomNumber == 3)
	{
		newRandomClass = "Demoman";
	}
	else if (randomNumber == 4)
	{
		newRandomClass = "Heavy";
	}
	else if (randomNumber == 5)
	{
		newRandomClass = "Engineer";
	}
	else if (randomNumber == 6)
	{
		newRandomClass = "Medic";
	}
	else if (randomNumber == 7)
	{
		newRandomClass = "Sniper";
	}
	else if (randomNumber == 8)
	{
		newRandomClass = "Spy";
	}

	return newRandomClass;
}

std::string RandomPlayerGenerator::RandomPrimaryWeapon(string playerClass)
{
	std::string newRandomPrimary = "";

	
	newRandomPrimary = RandomString(12);

	if (playerClass.compare("Scout") == 0)
	{
		newRandomPrimary.append(" Shotgun");
	}
	else if (playerClass.compare("Spy") == 0)
	{
		newRandomPrimary.insert(0, "Sneaky ");
	}
	return newRandomPrimary;
}

std::string RandomPlayerGenerator::RandomSecondaryWeapon(string playerClass)
{
	std::string newRandomSecondary = "";

	
	newRandomSecondary = RandomString(12);

	if (playerClass.compare("Soldier") == 0)
	{
		newRandomSecondary.append(" Shotgun");
	}
	else if (playerClass.compare("Spy") == 0)
	{
		newRandomSecondary.insert(0, "Silent ");
	}
	return newRandomSecondary;
}

std::string RandomPlayerGenerator::RandomMeleeWeapon(string playerClass)
{
	std::string newRandomMelee = "";
	int randomNumber = 0;

	if (playerClass.compare("Engineer") == 0)
	{
		
		randomNumber = rand() % 2;
		if (randomNumber == 0)
		{
			newRandomMelee = ("Chair");
		}
		else
		{
			newRandomMelee = ("Stool");
		}
	}
	else if (playerClass.compare("Heavy") == 0)
	{
		
		randomNumber = rand() % 3;
		if (randomNumber == 0)
		{
			newRandomMelee = ("Fist");
		}
		else if (randomNumber == 1)
		{
			newRandomMelee = ("Fists");
		}
		else
		{
			newRandomMelee = ("Sandvich");
		}
	}
	else
	{
		if (playerClass.compare("Pyro") == 0)
		{
			newRandomMelee.append("Rainbow ");
		}
		else if (playerClass.compare("Medic") == 0)
		{
			newRandomMelee.append("Heal Heal Heal ");
		}
		else if (playerClass.compare("Spy") == 0)
		{
			newRandomMelee.append("Discreet ");
		}
		newRandomMelee.append(RandomString(12));
	}
	return newRandomMelee;
}

int RandomPlayerGenerator::RandomNumberOfHats(string playerClass)
{
	int newRandomNumberOfHats = 0;

	
	newRandomNumberOfHats = rand() % 10000;

	if (playerClass.compare("Sniper") == 0)
	{
		newRandomNumberOfHats = newRandomNumberOfHats + 5;
	}
	
	return newRandomNumberOfHats;
}