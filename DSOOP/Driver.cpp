// File name:			Driver.cpp
// Project:				DSOOP_TF2_Player_Tracker
// Created by:			Ping Chang Ueng
//						Lauchlin Morrison
// Date created:		April 5, 2015
// Description:			This file holds main(). main() holds Container and UI.

#include <stdio.h>
#include <stdlib.h>
#include "UI.h"
#include "Container.h"

int main()
{
	Container *playerContainer = new Container;
	UI theUI(playerContainer);
	theUI.UIDriver();
	return 0;
}