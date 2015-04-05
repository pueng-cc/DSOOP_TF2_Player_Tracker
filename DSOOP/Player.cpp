#include "Player.h"

bool Player::ValidateName(std::string input)
{
	return ValidateString(input, 32);
}

bool Player::ValidatePlayerClass(std::string input)
{
	bool isValid = true;
	int iterCounter = 0;
	std::string lowerCaseInput = "";

	isValid = ValidateString(input, 10);

	if (isValid == true)
	{
		lowerCaseInput = tolowerString(input);
		if (lowerCaseInput.compare("scout") == 0 || lowerCaseInput.compare("soldier") == 0 ||
			lowerCaseInput.compare("pyro") == 0 || lowerCaseInput.compare("demoman") == 0 ||
			lowerCaseInput.compare("heavy") == 0 || lowerCaseInput.compare("engineer") == 0 ||
			lowerCaseInput.compare("medic") == 0 || lowerCaseInput.compare("sniper") == 0 ||
			lowerCaseInput.compare("spy") == 0)
		{
			isValid = true;
		}
		else
		{
			isValid = false;
		}
	}

	return false;
}

bool Player::ValidatePrimaryWeapon(std::string input)
{
	return ValidateWeapon(input);
}

bool Player::ValidateSecondaryWeapon(std::string input)
{
	return ValidateWeapon(input);
}

bool Player::ValidateMeleeWeapon(std::string input)
{
	return ValidateWeapon(input);
}

bool Player::ValidateNumberOfHats(int input)
{
	bool isValid = false;

	if (input >= 0)
	{
		isValid = false;
	}

	return isValid;
}

bool Player::ValidateString(std::string input, int maxLength)
{
	bool isValid = true;
	int iterCounter = 0;

	if (input.length() > maxLength)
	{
		isValid = false;
	}
	else
	{
		while (iterCounter < input.length())
		{
			if (input[iterCounter] < 32 || input[iterCounter] > 126)
			{
				isValid = false;
				break;
			}
			iterCounter++;
		}
	}

	return isValid;
}

bool Player::ValidateWeapon(std::string input)
{
	return ValidateString(input, 64);
}

std::string Player::tolowerString(std::string input)
{
	int iterCounter = 0;
	std::string lowerCaseInput = "";

	while (iterCounter < input.length())
	{
		lowerCaseInput[iterCounter] = tolower(input[iterCounter]);
		iterCounter++;
	}

	return lowerCaseInput;
}

bool Player::ValidateScout()
{
	bool isValid = false;
	std::string lowerCasePrimaryWeapon = tolowerString(primaryWeapon);

	if (lowerCasePrimaryWeapon.find("shotgun") != -1)
	{
		isValid = true;
	}

	return isValid;
}

bool Player::ValidateSoldier()
{
	bool isValid = false;
	std::string lowerCaseSecondaryWeapon = tolowerString(secondaryWeapon);

	if (lowerCaseSecondaryWeapon.find("shotgun") != -1)
	{
		isValid = true;
	}
	return isValid;
}

bool Player::ValidatePyro()
{
	bool isValid = false;
	std::string lowerCasePrimaryWeapon = tolowerString(primaryWeapon);
	std::string lowerCaseSecondaryWeapon = tolowerString(secondaryWeapon);
	std::string lowerCaseMeleeWeapon = tolowerString(meleeWeapon);

	if (lowerCasePrimaryWeapon.find("rainbow") != -1)
	{
		isValid = true;
	}
	else if (lowerCaseSecondaryWeapon.find("rainbow") != -1)
	{
		isValid = true;
	}
	else if (lowerCaseMeleeWeapon.find("rainbow") != -1)
	{
		isValid = true;
	}
	return isValid;
}

bool Player::MustBeDemoman()
{
	bool isValid = false;

	if (name.find("Smith") != -1)
	{
		isValid = true;
	}
	else if (name.find("Brown") != -1)
	{
		isValid = true;
	}
	else if (name.find("Wilson") != -1)
	{
		isValid = true;
	}
	else if (name.find("Robertson") != -1)
	{
		isValid = true;
	}
	else if (name.find("Thomson") != -1)
	{
		isValid = true;
	}

	return isValid;
}

bool Player::ValidateHeavy()
{
	bool isValid = false;
	std::string lowerCaseName = tolowerString(name);
	std::string lowerCasePrimaryWeapon = tolowerString(primaryWeapon);
	std::string lowerCaseSecondaryWeapon = tolowerString(secondaryWeapon);
	std::string lowerCaseMeleeWeapon = tolowerString(meleeWeapon);

	if (lowerCaseName.find("smart") != 0 && lowerCasePrimaryWeapon.find("smart") != 0 &&
		lowerCaseSecondaryWeapon.find("smart") != 0 && lowerCaseMeleeWeapon.find("smart") != 0)
	{
		if (lowerCaseMeleeWeapon.compare("fist") == 0 || lowerCaseMeleeWeapon.compare("fists") == 0 || lowerCaseMeleeWeapon.compare("sandvich") == 0)
		{
			isValid == true;
		}
	}

	return isValid;
}

bool Player::ValidateEngineer()
{
	bool isValid = false;

	if (primaryWeapon.find("Stool") != -1 || primaryWeapon.find("Chair") != -1 || primaryWeapon.find("Sittable") != -1 ||
		secondaryWeapon.find("Stool") != -1 || secondaryWeapon.find("Chair") != -1 || secondaryWeapon.find("Sittable") != -1 ||
		meleeWeapon.find("Stool") != -1 || meleeWeapon.find("Chair") != -1 || meleeWeapon.find("Sittable") != -1)
	{
		isValid = true;
	}

	return isValid;
}

bool Player::ValidateMedic()
{
	bool isValid = false;
	int healCounter = 0;
	bool noMoreHeal = false;
	size_t healIterator = 0;
	std::string combinedWeaponsName = "";

	combinedWeaponsName.append(primaryWeapon);
	combinedWeaponsName.append(" ");
	combinedWeaponsName.append(secondaryWeapon);
	combinedWeaponsName.append(" ");
	combinedWeaponsName.append(meleeWeapon);
	combinedWeaponsName = tolowerString(combinedWeaponsName);

	while (healCounter < 3 && noMoreHeal == false)
	{
		healIterator = combinedWeaponsName.find("heal");
		if (healIterator != -1)
		{
			healCounter++;
			combinedWeaponsName.erase(healIterator, 4);
		}
		else
		{
			noMoreHeal = true;
		}
	}

	if (healCounter >= 3)
	{
		isValid = true;
	}

	return isValid;
}

bool Player::ValidateSniper()
{
	bool isValid = true;
	if (numberOfHats < 5)
	{
		isValid = false;
	}
	return isValid;
}

bool Player::ValidateSpy()
{
	bool isValid = false;
	bool primaryIsValid = false;
	bool secondaryIsValid = false;
	bool meleeIsValid = false;

	if (primaryWeapon.find("Sneaky") != -1)
	{
		primaryIsValid = true;
	}
	else if (primaryWeapon.find("Silent") != -1)
	{
		primaryIsValid = true;
	}
	else if (primaryWeapon.find("Discreet") != -1)
	{
		primaryIsValid = true;
	}

	if (secondaryWeapon.find("Sneaky") != -1)
	{
		secondaryIsValid = true;
	}
	else if (secondaryWeapon.find("Silent") != -1)
	{
		secondaryIsValid = true;
	}
	else if (secondaryWeapon.find("Discreet") != -1)
	{
		secondaryIsValid = true;
	}

	if (meleeWeapon.find("Sneaky") != -1)
	{
		meleeIsValid = true;
	}
	else if (meleeWeapon.find("Silent") != -1)
	{
		meleeIsValid = true;
	}
	else if (meleeWeapon.find("Discreet") != -1)
	{
		meleeIsValid = true;
	}

	if (primaryIsValid == true && secondaryIsValid == true && meleeIsValid == true)
	{
		isValid = true;
	}

	return isValid;
}

Player::Player()
{
	name = "";
	playerClass = "";
	primaryWeapon = "";
	secondaryWeapon = "";
	meleeWeapon = "";
	numberOfHats = 0;
}

std::string Player::GetName()
{
	return name;
}

std::string Player::GetPlayerClass()
{
	return playerClass;
}

std::string Player::GetPrimaryWeapon()
{
	return primaryWeapon;
}

std::string Player::GetSecondaryWeapon()
{
	return secondaryWeapon;
}

std::string Player::GetMeleeWeapon()
{
	return meleeWeapon;
}

int Player::GetNumberOfHats()
{
	return numberOfHats;
}

bool Player::SetName(std::string input)
{
	bool isValid = false;

	if (ValidateName(input) == true)
	{
		name = input;
		isValid = true;
	}

	return isValid;
}

bool Player::SetPlayerClass(std::string input)
{
	bool isValid = false;

	if (ValidatePlayerClass(input) == true)
	{
		playerClass = input;
		isValid = true;
	}

	return isValid;
}

bool Player::SetPrimaryWeapon(std::string input)
{
	bool isValid = false;

	if (ValidatePrimaryWeapon(input) == true)
	{
		primaryWeapon = input;
		isValid = true;
	}

	return isValid;
}

bool Player::SetSecondaryWeapon(std::string input)
{
	bool isValid = false;

	if (ValidateSecondaryWeapon(input) == true)
	{
		secondaryWeapon = input;
		isValid = true;
	}

	return isValid;
}

bool Player::SetMeleeWeapon(std::string input)
{
	bool isValid = false;

	if (ValidateMeleeWeapon(input) == true)
	{
		meleeWeapon = input;
		isValid = true;
	}

	return isValid;
}

bool Player::SetNumberOfHats(int input)
{
	bool isValid = false;

	if (ValidateNumberOfHats(input) == true)
	{
		numberOfHats = input;
		isValid = true;
	}

	return isValid;
}
