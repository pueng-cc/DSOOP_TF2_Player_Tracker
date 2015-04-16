// File name:			RandomPlayerGenerator.cpp
// Project:				DSOOP_TF2_Player_Tracker
// Created by:			Ping Chang Ueng
//						Lauchlin Morrison
// Date created:		April 12, 2015
// Description:			This one actually doesn't create a whole player, since UI won't be able 
//						to understand it if that's the case. The UI class within this file is 
//						capable to generate random name, random weapon name, random class, and 
//						random number for hats.

#include "RandomPlayerGenerator.h"

///
/// \brief Creates random string
/// \details <b>Details</b>
///
/// Creates a random string of ASCII 32~126. Length of the string is determined by 
/// parameter.
///
/// \param length - <b>int</b> - The length of the string to create.
///
/// \return <b>std::string</b> - The randomly generated string.
///
std::string RandomPlayerGenerator::RandomString(int length)
{
	std::string newRandomString = "";
	int lengthCounter = 0;

	newRandomString.resize(length);

	while (lengthCounter < length)
	{
		// 94 + 32
		
		newRandomString[lengthCounter] = rand() % 94 + 32;
		lengthCounter++;
	}

	return newRandomString;
}

///
/// \brief Creates random name
/// \details <b>Details</b>
///
/// Uses RandomString() to make a string with length of 12. Append class-specific 
/// limitations to the string afterward.
///
/// \param playerClass - <b>std::string</b> - The class of the player the name is for.
///
/// \return <b>std::string</b> - The randomly generated name.
///
std::string RandomPlayerGenerator::RandomName(std::string playerClass)
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

///
/// \brief Creates random class
/// \details <b>Details</b>
///
/// Returns one of the 9 classes at random.
/// This one is expected to be called prior to any other random generators.
///
/// \return <b>std::string</b> - The randomly generated class.
///
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

///
/// \brief Creates random primary weapon
/// \details <b>Details</b>
///
/// Calls RandomString() to generate a string of 12 characters long. Appends class-specific 
/// limitations afterward.
///
/// \param playerClass - <b>std::string</b> - The length of the string to create.
///
/// \return <b>std::string</b> - The randomly generated primary weapon.
///
std::string RandomPlayerGenerator::RandomPrimaryWeapon(std::string playerClass)
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

///
/// \brief Creates random secondary weapon
/// \details <b>Details</b>
///
/// Calls RandomString() to generate a string of 12 characters long. Appends class-specific 
/// limitations afterward.
///
/// \param playerClass - <b>std::string</b> - The length of the string to create.
///
/// \return <b>std::string</b> - The randomly generated secondary weapon.
///
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

///
/// \brief Creates random melee weapon
/// \details <b>Details</b>
///
/// Calls RandomString() to generate a string of 12 characters long. Appends class-specific 
/// limitations afterward.
///
/// \param playerClass - <b>std::string</b> - The length of the string to create.
///
/// \return <b>std::string</b> - The randomly generated melee weapon.
///
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

///
/// \brief Creates random number of hats
/// \details <b>Details</b>
///
/// Generates a random number between 0~9999. Add 5 more hats if player class is Sniper.
///
/// \param playerClass - <b>std::string</b> - The length of the string to create.
///
/// \return <b>int</b> - The randomly generated number for hats.
///
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