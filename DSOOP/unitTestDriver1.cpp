// File name:			unitTestDriver1.cpp
// Project:				DSOOP_TF2_Player_Tracker
// Created by:			Ping Chang Ueng
//						Lauchlin Morrison
// Date created:		April 15, 2015
// Description:			This test harness will test the string portion of the validations within 
//						Player class. SetPlayerClass will not be tested since it is well constrained 
//						by the UI (select existing phrase from menu instead of user entry).

#include <stdio.h>
#include "Player.h"

int main()
{
	Player playerObject;
	
	// Normal Test
	// Input:			John123
	// Expected output:	John123
	if (playerObject.SetName("John123") == true)
	{
		printf("%s\n", playerObject.GetName().c_str());
	}
	else
	{
		printf("Invalid\n");
	}
	
	// Normal Test
	// Input:			Happy Final!
	// Expected output:	Happy Final!
	if (playerObject.SetName("Happy Final!") == true)
	{
		printf("%s\n", playerObject.GetName().c_str());
	}
	else
	{
		printf("Invalid\n");
	}
	
	// Normal Test
	// Input:			No it's not happy.
	// Expected output:	No it's not happy.
	if (playerObject.SetName("No it's not happy.") == true)
	{
		printf("%s\n", playerObject.GetName().c_str());
	}
	else
	{
		printf("Invalid\n");
	}

	// Exception Test
	// Input:			John123\n
	// Expected output:	Invalid
	if (playerObject.SetName("John123\n") == true)
	{
		printf("%s\n", playerObject.GetName().c_str());
	}
	else
	{
		printf("Invalid\n");
	}
	
	// Exception Test
	// Input:			Happy\t Final!
	// Expected output:	Invalid
	if (playerObject.SetName("Happy\t Final!") == true)
	{
		printf("%s\n", playerObject.GetName().c_str());
	}
	else
	{
		printf("Invalid\n");
	}
	
	// Exception Test
	// Input:			\rNo it's not happy
	// Expected output:	Invalid
	if (playerObject.SetName("\rNo it's not happy.") == true)
	{
		printf("%s\n", playerObject.GetName().c_str());
	}
	else
	{
		printf("Invalid\n");
	}
	return 0;
}