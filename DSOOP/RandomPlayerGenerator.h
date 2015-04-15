#pragma once
#include <string>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "Player.h"

static class RandomPlayerGenerator
{
private:
	std::string RandomString(int length);
public:
	std::string RandomName(string playerClass);
	std::string RandomPlayerClass();
	std::string RandomPrimaryWeapon(string playerClass);
	std::string RandomSecondaryWeapon(string playerClass);
	std::string RandomMeleeWeapon(string playerClass);
	std::string RandomNumberOfHats(string playerClass);

	Player RandomPlayer();

};