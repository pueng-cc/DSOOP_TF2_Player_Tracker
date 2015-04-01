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
	std::string lowerCasePrimaryWeapon = "";

	lowerCasePrimaryWeapon = tolowerString(primaryWeapon);

	if (lowerCasePrimaryWeapon.find("shotgun") != -1)
	{
		isValid = true;
	}

	return isValid;
}

bool Player::ValidateSoldier()
{
	bool isValid = false;
	std::string lowerCaseSecondaryWeapon = "";

	lowerCaseSecondaryWeapon = tolowerString(secondaryWeapon);

	if (lowerCaseSecondaryWeapon.find("shotgun") != -1)
	{
		isValid = true;
	}
	return isValid;
}

bool Player::ValidatePyro()
{
	bool isValid = false;
	std::string lowerCasePrimaryWeapon = "";
	std::string lowerCaseSecondaryWeapon = "";
	std::string lowerCaseMeleeWeapon = "";

	lowerCasePrimaryWeapon = tolowerString(primaryWeapon);
	lowerCaseSecondaryWeapon = tolowerString(secondaryWeapon);
	lowerCaseMeleeWeapon = tolowerString(meleeWeapon);

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
