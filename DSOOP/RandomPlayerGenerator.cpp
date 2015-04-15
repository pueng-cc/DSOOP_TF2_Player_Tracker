#include "RandomPlayerGenerator.h"

std::string RandomPlayerGenerator::RandomString(int length)
{
	std::string newRandomString = "";
	int lengthCounter = 0;

	newRandomString.resize(length);

	while (lengthCounter < length)
	{
		// 94 + 32
		srand(time(NULL));
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
		srand(time(NULL));
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
	return std::string();
}

std::string RandomPlayerGenerator::RandomPlayerClass()
{
	std::string newRandomClass = "";
	int randomNumber = 0;

	srand(time(NULL));
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
	return std::string();
}

std::string RandomPlayerGenerator::RandomSecondaryWeapon(string playerClass)
{
	return std::string();
}

std::string RandomPlayerGenerator::RandomMeleeWeapon(string playerClass)
{
	return std::string();
}

std::string RandomPlayerGenerator::RandomNumberOfHats(string playerClass)
{
	return std::string();
}

Player RandomPlayerGenerator::RandomPlayer()
{
	Player newRandomPlayer;

	return newRandomPlayer;
}
