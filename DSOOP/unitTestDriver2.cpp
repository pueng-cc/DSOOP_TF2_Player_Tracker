// File name:			unitTestDriver2.cpp
// Project:				DSOOP_TF2_Player_Tracker
// Created by:			Ping Chang Ueng
//						Lauchlin Morrison
// Date created:		April 15, 2015
// Description:			This test harness will test the crossfield validation of Player class of Medic. 
//						A medic requires at least three "heal" across its three weapons, and that will be 
//						what we are testing here.

#include <stdio.h>
#include "Player.h"

int main()
{
	Player playerObject;

	playerObject.SetName("Sir Doctor");
	playerObject.SetPlayerClass("Doctor");
	playerObject.SetNumberOfHats(555);

	// Normal Test
	// Input:			HEAL HEAL HEAL Gun
	//					Deadly Pistol
	//					Chainsaw
	// Expected output:	Valid
	playerObject.SetPrimaryWeapon("HEAL HEAL HEAL Gun");
	playerObject.SetSecondaryWeapon("Deadly Pistol");
	playerObject.SetMeleeWeapon("Chainsaw");
	if (playerObject.ValidateMedic() == true)
	{
		printf("Valid\n");
	}
	else
	{
		printf("Invalid\n");
	}

	// Normal Test
	// Input:			Heal Heal Gun
	//					Deadly Pistol
	//					Heal Chainsaw
	// Expected output:	Valid
	playerObject.SetPrimaryWeapon("Heal Heal Gun");
	playerObject.SetSecondaryWeapon("Deadly Pistol");
	playerObject.SetMeleeWeapon("Heal Chainsaw");
	if (playerObject.ValidateMedic() == true)
	{
		printf("Valid\n");
	}
	else
	{
		printf("Invalid\n");
	}

	// Normal Test
	// Input:			Heal Gun
	//					Deadly heal Pistol
	//					Heal Chainsaw
	// Expected output:	Valid
	playerObject.SetPrimaryWeapon("Heal Gun");
	playerObject.SetSecondaryWeapon("Deadly Heal Pistol");
	playerObject.SetMeleeWeapon("Heal Chainsaw");
	if (playerObject.ValidateMedic() == true)
	{
		printf("Valid\n");
	}
	else
	{
		printf("Invalid\n");
	}

	// Exception Test
	// Input:			Gun of Death
	//					Deadly Pistol
	//					Chainsaw
	// Expected output:	Invalid
	playerObject.SetPrimaryWeapon("Gun of Death");
	playerObject.SetSecondaryWeapon("Deadly Pistol");
	playerObject.SetMeleeWeapon("Chainsaw");
	if (playerObject.ValidateMedic() == true)
	{
		printf("Valid\n");
	}
	else
	{
		printf("Invalid\n");
	}

	// Exception Test
	// Input:			Heal Heal Gun
	//					Deadly Pistol
	//					Chainsaw
	// Expected output:	Invalid
	playerObject.SetPrimaryWeapon("Heal Heal Gun");
	playerObject.SetSecondaryWeapon("Deadly Pistol");
	playerObject.SetMeleeWeapon("Chainsaw");
	if (playerObject.ValidateMedic() == true)
	{
		printf("Valid\n");
	}
	else
	{
		printf("Invalid\n");
	}

	// Exception Test
	// Input:			HEEEEEEEEEEAL
	//					HEALLLLLLLLLLLLLLL
	//					HEEEEEEEEEEEAAAAALLLLLLLLL
	// Expected output:	Valid
	playerObject.SetPrimaryWeapon("HEEEEEEEEEEAL");
	playerObject.SetSecondaryWeapon("HEALLLLLLLLLLLLLLL");
	playerObject.SetMeleeWeapon("HEEEEEEEEEEEAAAAALLLLLLLLL");
	if (playerObject.ValidateMedic() == true)
	{
		printf("Valid\n");
	}
	else
	{
		printf("Invalid\n");
	}
	return 0;
}