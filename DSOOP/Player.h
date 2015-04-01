#include <string>
#include <iostream>
using namespace std;

class Player
{
private:

	// Attributes
	std::string name;
	std::string playerClass;
	std::string primaryWeapon;
	std::string secondaryWeapon;
	std::string meleeWeapon;
	int numberOfHats;

	// Single field validations
	bool ValidateName(std::string); // Max length 32. ASCII 32 ~ 126. Cannot be repeated.
	bool ValidatePlayerClass(std::string); // Can only be Scout, Soldier, Pyro, Demoman, Heavy, Engineer, Medic, Sniper, or Spy. Non-case sensitive but will always be stored with capitalized first character followed by lower cases.
	bool ValidatePrimaryWeapon(std::string); // Max length 64. ASCII 32 ~ 126
	bool ValidateSecondaryWeapon(std::string); // Max length 64. ASCII 32 ~ 126
	bool ValidateMeleeWeapon(std::string); // Max length 64. ASCII 32 ~ 126
	bool ValidateNumberOfHats(int); // 0 or more

	// Validate generic string, given the string to be validated and max length.
	bool ValidateString(std::string, int);

	// Since all 3 weaopns follow the same rules at the moment, here's a generic validator:
	bool ValidateWeapon(std::string);

	std::string tolowerString(std::string);

	// Cross field validations
	bool ValidateScout(); // Scout’s primary weapon must contain “shotgun” (non-case sensitive)
	bool ValidateSoldier(); // Soldier’s secondary weapon must contain “shotgun” (non-case sensitive)
	bool ValidatePyro(); // At least one of Pyro’s weapon must contain “rainbow” (non-case sensitive)
	bool MustBeDemoman(); // If player’s name includes “Smith”, “Brown”, “Wilson”, “Robertson”, or “Thomson”, the only valid class is Demoman (case sensitive)
	bool ValidateHeavy(); // Heavy’s melee weapon can only be [blank], “fist”, “fists”, or “sandvich” (non-case sensitive)
	bool ValidateEngineer(); // One of Engineer’s weapon must be “Stool” or “Chair” (case sensitive)
	bool ValidateMedic(); // The word “heal” must appear at least two times across the three weapons of a Medic (non-case sensitive)
	bool ValidateSniper(); // Sniper has to have at least 5 hats to be valid
	bool ValidateSpy(); // All of Spy’s weapons must include the any of the following words: “Sneaky”, “Silent”, “Discreet” (case insensitive)

public:
	// Constructor
	Player();

	// Accessors
	std::string GetName();
	std::string GetPlayerClass();
	std::string GetPrimaryWeapon();
	std::string GetSecondaryWeapon();
	std::string GetMeleeWeapon();
	int GetNumberOfHats();

	// Mutators
	bool SetName(std::string);
	bool SetPlayerClass(std::string);
	bool SetPrimaryWeapon(std::string);
	bool SetSecondaryWeapon(std::string);
	bool SetMeleeWeapon(std::string);
	bool SetNumberOfHats(int);
};