//Project		: DS-OOP Project
//File Name		: unitTestDriver3.cpp
//Programmer	: Lauchlin
//Date			: 2015/04/15
//Description	: This is a unit test for the 

#include "Container.h"

int main(void)
{
	Container testContainer;

	//Normal Tests:
	//Normal Test 1:
	//Testing adding a new player to the container.
	//Expected it be successfully added and that the same information dispalys.
	printf(">>>:Normal Test 1:<<<\n\n");
	printf("Adding a new player to the container.");
	printf("\nExpected Results : CreateNewPlayer() return true\nName : Normal Test 1.\nClass : Scout\nPrimary : Shotgun\nSecondary : Pistol\nMelee : Bat\nHats : 4\n");
	if (testContainer.CreateNewPlayer("Normal Test 1.", "Scout", "Shotgun", "Pistol", "Bat", 4) == true)
	{
		printf("\nActual Results:CreateNewPlayer() Returned true");
	}
	else
	{
		printf("\nActual Results: CreateNewPlayer() Returned false");
	}
	printf("\nDisplaying Container:\n");
	testContainer.DisplayContainer();
	printf(":End of Normal Test 1:\n");

	//Normal Test 2:
	//Testing adding another player to the container.
	//Expected
	printf("\n>>>:Normal Test 2:<<<\n\n");
	printf("Adding a new player to the existing container.");

	printf("\nExpected Results : Previous Results & CreateNewPlayer() return true\nName : Normal Test 2.\nClass : Soldier\nPrimary : Rocket\nSecondary : Shotgun\nMelee : Shovel\nHats : 200\n");

	if (testContainer.CreateNewPlayer("Normal Test 2.", "Soldier", "Rocket", "Shotgun", "Shovel", 200) == true)
	{
		printf("\nActual Results:CreateNewPlayer() Returned true");
	}
	else
	{
		printf("\nActual Results: CreateNewPlayer() Returned false");
	}
	printf("\nDisplaying Container:\n");
	testContainer.DisplayContainer();
	printf(":End of Normal Test 2:\n");

	//Normal Test 3:
	//Testing adding a 
	//Expected
	printf("\n>>>:Normal Test 3:<<<\n\n");
	printf("Adding a new player to the existing container.");

	printf("\nExpected Results : Previous Results & CreateNewPlayer() return true\nName : Normal Test 3.\nClass : Pyro\nPrimary : Rainbow\nSecondary : Shotgun\nMelee : Axe\nHats : 0\n");

	if (testContainer.CreateNewPlayer("Normal Test 3.", "Pyro", "Rainbow", "Shotgun", "Axe", 0) == true)
	{
		printf("\nActual Results:CreateNewPlayer() Returned true");
	}
	else
	{
		printf("\nActual Results: CreateNewPlayer() Returned false");
	}
	printf("\nDisplaying Container:\n");
	testContainer.DisplayContainer();
	printf(":End of Normal Test 3:\n");



	//Exception Tests:
	//Exception test 1
	//Testing if adding the same name is allowed.
	printf(">>>:Exception Test 1:<<<\n\n");
	printf("Adding a new player to the container.");
	printf("\nExpected Results : CreateNewPlayer() return false \nand Database Display Results should mirror Normal Test 3\n");
	printf("Additionaly an error should be thrown and caught.\n");
	try
	{
		if (testContainer.CreateNewPlayer("Normal Test 1.", "Sniper", "Changed?", "Differnt?", "Rawr!", 7) == true)
		{
			printf("\nActual Results:CreateNewPlayer() Returned true");
		}
		else
		{
			printf("\nActual Results: CreateNewPlayer() Returned false");
		}

		printf("\nDisplaying Container:\n");

		testContainer.DisplayContainer();
	}
	catch (char* e)
	{
		printf("Error Caught: %s\n", e);
	}
	printf(":End of Exception Test 1:\n");



	//Exception test 2
	//Testing if invalide cross field validation is allowed.
	printf(">>>:Exception Test 2:<<<\n\n");
	printf("Adding a new player to the container.");
	printf("\nExpected Results : CreateNewPlayer() return false \nand Database Display Results should mirror Normal Test 3\n");
	try
	{
	if (testContainer.CreateNewPlayer("Exception Test 2.", "Spy", "Changed?", "Differnt?", "Rawr!", 7) == true)
	{
		printf("\nActual Results:CreateNewPlayer() Returned true");
	}
	else
	{
		printf("\nActual Results: CreateNewPlayer() Returned false");
	}
	printf("\nDisplaying Container:\n");
	testContainer.DisplayContainer();
	}
	catch (char* e)
	{
		printf("Error Caught: %s\n", e);
	}
	printf(":End of Exception Test 2:\n");



	//Exception test 3
	//Testing if invalide cross field validation is allowed.
	printf(">>>:Exception Test 3:<<<\n\n");
	printf("Adding a new player to the container.");
	printf("\nExpected Results : CreateNewPlayer() return false \nand and exception for the number of hats should be caught.\n");
	try
	{
		if (testContainer.CreateNewPlayer("Exception Test 3.", "Scout", "NotAShotg*n", "Pistol", "Bat", -1) == true)
		{
			printf("\nActual Results:CreateNewPlayer() Returned true");
		}
		else
		{
			printf("\nActual Results: CreateNewPlayer() Returned false");
		}
		printf("\nDisplaying Container:\n");
		testContainer.DisplayContainer();
	}
	catch (char* e)
	{
		printf("Error Caught: %s\n", e);
	}
	printf(":End of Exception Test 3:\n");

	return 0;
}