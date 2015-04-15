#pragma warning(disable: 4996)

#include <string>
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include "Container.h"
#include "RandomPlayerGenerator.h"

class UI
{
private:
	Container *theContainer;

	
	
	void MainMenuUI();
	void AddPlayerUI();
	void DeletePlayerUI();
	void SearchPlayerUI();
	void DisplayOnePlayerUI(std::string playerInfo);
//	void SearchByName();
//	void SearchByClass();
//	void SearchByNumberOfHats();
	void DisplayDatabaseUI();
	void DeleteDatabaseUI();
	void GenerateRandomPlayersUI();
	

public:
	UI(Container*);

	void UIDriver();
};