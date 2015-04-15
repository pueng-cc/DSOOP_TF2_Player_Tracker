#include "Player.h"

///
/// \brief Validates player name
/// \details <b>Details</b>
///
/// Passes parameter to ValidateString(), with 32 characters as maximum length
///
/// \param input - <b>std::string</b> - The string to be validated.
///
/// \return <b>bool</b> - Whether the input is valid as a player name.
///
/// \see ValidateString()
///
bool Player::ValidateName(std::string input)
{
	return ValidateString(input, 32);
}

///
/// \brief Validates player class
/// \details <b>Details</b>
///
/// Unlike other string fields, player class only allows specific input:
/// scout, soldier, pyro, demoman, heavy, engineer, medic, sniper, and spy.
/// Non-case sensitive, since the string will be converted to lowercase during comparison.
///
/// \param input - <b>std::string</b> - The string to be validated.
///
/// \return <b>bool</b> - Whether the input is valid as a player class.
///
bool Player::ValidatePlayerClass(std::string input)
{
	bool isValid = true;
	int iterCounter = 0;
	std::string lowerCaseInput = "";

	// Use ValidateString() to check whether there are unwanted characters such as \n
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

///
/// \brief Validates primary weapon
/// \details <b>Details</b>
///
/// A redundant method that servces no purpose at the moment. This method is made just so it'll be less 
/// of a hassle if we decide to add per-weapon validations in the future.
///
/// \param input - <b>std::string</b> - The string to be validated.
///
/// \return <b>bool</b> - Whether the input is valid as a primary weapon.
///
/// \see ValidateWeapon()
///
bool Player::ValidatePrimaryWeapon(std::string input)
{
	return ValidateWeapon(input);
}

///
/// \brief Validates secondary weapon
/// \details <b>Details</b>
///
/// A redundant method that servces no purpose at the moment. This method is made just so it'll be less 
/// of a hassle if we decide to add per-weapon validations in the future.
///
/// \param input - <b>std::string</b> - The string to be validated.
///
/// \return <b>bool</b> - Whether the input is valid as a secondary weapon.
///
/// \see ValidateWeapon()
///
bool Player::ValidateSecondaryWeapon(std::string input)
{
	return ValidateWeapon(input);
}

///
/// \brief Validates melee weapon
/// \details <b>Details</b>
///
/// A redundant method that servces no purpose at the moment. This method is made just so it'll be less 
/// of a hassle if we decide to add per-weapon validations in the future.
///
/// \param input - <b>std::string</b> - The string to be validated.
///
/// \return <b>bool</b> - Whether the input is valid as a melee weapon.
///
/// \see ValidateWeapon()
///
bool Player::ValidateMeleeWeapon(std::string input)
{
	return ValidateWeapon(input);
}

///
/// \brief Validates number of hats
/// \details <b>Details</b>
///
/// Checks whether the input is an appropriate number for the amount of hats worn by a player. Unfortunately 
/// wearing fractions of a hat or negative amount of hat is currently not supported.
///
/// \param input - <b>int</b> - The int to be validated.
///
/// \return <b>bool</b> - Whether the input is valid as a number of hats.
///
bool Player::ValidateNumberOfHats(int input)
{
	bool isValid = false;

	if (input >= 0)
	{
		isValid = false;
	}

	return isValid;
}

///
/// \brief Validates a string
/// \details <b>Details</b>
///
/// This validation ensures a string only contains characters that can properly display within console 
/// window without affecting the format. It also takes an int input to determine the maximum length allowed 
/// for that particular string.
///
/// \param input - <b>std::string</b> - The string to be validated.
/// \param maxLength - <b>int</b> - The maximum length allowed for this piece of string
///
/// \return <b>bool</b> - Whether the string is valid.
///
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

///
/// \brief Validates weapon
/// \details <b>Details</b>
///
/// General-purpose validator for all weapons. 64 characters max length.
///
/// \param input - <b>std::string</b> - The string to be validated.
///
/// \return <b>bool</b> - Whether the input is valid as a weapon.
///
/// \see ValidateString()
///
bool Player::ValidateWeapon(std::string input)
{
	return ValidateString(input, 64);
}

///
/// \brief Turns every characers within a string to lowercase.
/// \details <b>Details</b>
///
/// Use tolower() on every character within the input string, then return the result.
///
/// \param input - <b>std::string</b> - The string to be tolower()'ed.
///
/// \return <b>std::string</b> - The tolower()'ed string
///
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

///
/// \brief Validates Scout class
/// \details <b>Details</b>
///
/// A Scout must have "shotgun" within the name of its primary weapon. Non-case sensitive.
///
/// \return <b>bool</b> - Whether the player is valid as a Scout.
///
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

///
/// \brief Validates Soldier class
/// \details <b>Details</b>
///
/// A Soldier must have "shotgun" within the name of its secondary weapon. Non-case sensitive.
///
/// \return <b>bool</b> - Whether the player is valid as a Soldier.
///
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

///
/// \brief Validates Pyro class
/// \details <b>Details</b>
///
/// A Pyro must have "rainbow" within the name of any of its weapon. Non-case sensitive.
///
/// \return <b>bool</b> - Whether the player is valid as a Pyro.
///
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

///
/// \brief Checks whether the player's only available class is Demoman
/// \details <b>Details</b>
///
/// If a player's name contains "Smith", "Brown", "Wilson", "Robertson", or "Thomson" (case sensitive), 
/// the player's only valid class is Demoman.
///
/// This is different from other class validations; instead of forbidding a player to be one of 
/// the class, this validation is to forbid player to be any other class.
///
/// \return <b>bool</b> - Whether the player has to be a Demoman.
///
bool Player::MustBeDemoman()
{
	bool isDemoman = false;

	if (name.find("Smith") != -1)
	{
		isDemoman = true;
	}
	else if (name.find("Brown") != -1)
	{
		isDemoman = true;
	}
	else if (name.find("Wilson") != -1)
	{
		isDemoman = true;
	}
	else if (name.find("Robertson") != -1)
	{
		isDemoman = true;
	}
	else if (name.find("Thomson") != -1)
	{
		isDemoman = true;
	}

	return isDemoman;
}

///
/// \brief Validates Heavy class
/// \details <b>Details</b>
///
/// A Heavy cannot have "smart" within any of its field (non-case sensitive).
/// A Heavy's melee weapon can only be "fist", "fists", or "sandvich" (non-case sensitive).
///
/// \return <b>bool</b> - Whether the player is valid as a Heavy.
///
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
			isValid = true;
		}
	}

	return isValid;
}

///
/// \brief Validates Engineer class
/// \details <b>Details</b>
///
/// At least one of Engineer's weapon must contain "Stool", "Chair", or "Sittable" to be valid (case sensitive).
///
/// \return <b>bool</b> - Whether the player is valid as a Engineer.
///
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

///
/// \brief Validates Medic class
/// \details <b>Details</b>
///
/// A Medic must have at least three "heal" repeated across all its weapons (non-case sensitive).
///
/// \return <b>bool</b> - Whether the player is valid as a Medic.
///
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

///
/// \brief Validates Sniper class
/// \details <b>Details</b>
///
/// A Sniper must have at least 5 hats.
///
/// \return <b>bool</b> - Whether the player is valid as a Sniper.
///
bool Player::ValidateSniper()
{
	bool isValid = true;
	if (numberOfHats < 5)
	{
		isValid = false;
	}
	return isValid;
}

///
/// \brief Validates Spy class
/// \details <b>Details</b>
///
/// A Spy must have either "Sneaky", "Silent" or "Discreet" in weapon name (case sensitive). 
/// This applies to all three weapons.
///
/// \return <b>bool</b> - Whether the player is valid as a Scout.
///
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

///
/// \brief Default constructor
/// \details <b>Details</b>
///
/// Constructor for Player class. This one will instantiate a Player class with all its field empty, 
/// and 0 hat.
///
/// \return Nothing
///
Player::Player()
{
	name = "";
	playerClass = "";
	primaryWeapon = "";
	secondaryWeapon = "";
	meleeWeapon = "";
	numberOfHats = 0;
}

///
/// \brief Accessor for name
/// \details <b>Details</b>
///
/// Accessor for name
///
/// \return <b>std::string</b> - name
///
std::string Player::GetName()
{
	return name;
}

///
/// \brief Accessor for playerClass
/// \details <b>Details</b>
///
/// Accessor for playerClass
///
/// \return <b>std::string</b> - playerClass
///
std::string Player::GetPlayerClass()
{
	return playerClass;
}

///
/// \brief Accessor for primaryWeapon
/// \details <b>Details</b>
///
/// Accessor for primaryWeapon
///
/// \return <b>std::string</b> - primaryWeapon
///
std::string Player::GetPrimaryWeapon()
{
	return primaryWeapon;
}

///
/// \brief Accessor for secondaryWeapon
/// \details <b>Details</b>
///
/// Accessor for secondaryWeapon
///
/// \return <b>std::string</b> - secondaryWeapon
///
std::string Player::GetSecondaryWeapon()
{
	return secondaryWeapon;
}

///
/// \brief Accessor for meleeWeapon
/// \details <b>Details</b>
///
/// Accessor for meleeWeapon
///
/// \return <b>std::string</b> - meleeWeapon
///
std::string Player::GetMeleeWeapon()
{
	return meleeWeapon;
}

///
/// \brief Accessor for numberofHats
/// \details <b>Details</b>
///
/// Accessor for numberOfHats
///
/// \return <b>int</b> - numberOfHats
///
int Player::GetNumberOfHats()
{
	return numberOfHats;
}

///
/// \brief Mutator for name
/// \details <b>Details</b>
///
/// Mutate name if the input is valid
///
/// \param input - <b>std::string</b> - The string to be set as new name.
///
/// \return <b>bool</b> - whether the mutation was a success
///
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

///
/// \brief Mutator for playerClass
/// \details <b>Details</b>
///
/// Mutate playerClass if the input is valid
///
/// \param input - <b>std::string</b> - The string to be set as new playerClass.
///
/// \return <b>bool</b> - whether the mutation was a success
///
bool Player::SetPlayerClass(std::string input)
{
	bool isValid = false;
	std::string formattedPlayerClass = "";

	if (ValidatePlayerClass(input) == true)
	{
		// make entire input lowercase
		formattedPlayerClass = tolowerString(input);
		// make first character uppercase
		formattedPlayerClass[0] = toupper(formattedPlayerClass[0]);
		playerClass = formattedPlayerClass;
		isValid = true;
	}

	return isValid;
}

///
/// \brief Mutator for primaryWeapon
/// \details <b>Details</b>
///
/// Mutate primaryWeapon if the input is valid
///
/// \param input - <b>std::string</b> - The string to be set as new primaryWeapon.
///
/// \return <b>bool</b> - whether the mutation was a success
///
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

///
/// \brief Mutator for secondaryWeapon
/// \details <b>Details</b>
///
/// Mutate secondaryWeapon if the input is valid
///
/// \param input - <b>std::string</b> - The string to be set as new secondaryWeapon.
///
/// \return <b>bool</b> - whether the mutation was a success
///
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

///
/// \brief Mutator for meleeWeapon
/// \details <b>Details</b>
///
/// Mutate meleeWeapon if the input is valid
///
/// \param input - <b>std::string</b> - The string to be set as new meleeWeapon.
///
/// \return <b>bool</b> - whether the mutation was a success
///
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

///
/// \brief Mutator for numberOfHats
/// \details <b>Details</b>
///
/// Mutate numberOfHats if the input is valid
///
/// \param input - <b>int</b> - The int to be set as new numberOfhats.
///
/// \return <b>bool</b> - whether the mutation was a success
///
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
