// File name:			UI.h
// Project:				DSOOP_TF2_Player_Tracker
// Created by:			Ping Chang Ueng
//						Lauchlin Morrison
// Date created:		April 5, 2015
// Description:			Header file for the UI class.
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
	void DisplayManyPlayersUI(std::string allTheNames);
	void SearchByNameUI();
	void SearchByClassUI();
	void SearchByNumberOfHatsUI();
	void DisplayDatabaseUI();
	void DeleteDatabaseUI();
	void GenerateRandomPlayersUI();
	

public:
	UI(Container*);

	void UIDriver();
};