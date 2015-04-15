#pragma once
#include <string>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
using namespace std;

static class RandomPlayerGenerator
{
private:
	static std::string RandomString(int length);
public:
	static std::string RandomName(std::string playerClass);
	static std::string RandomPlayerClass();
	static std::string RandomPrimaryWeapon(std::string playerClass);
	static std::string RandomSecondaryWeapon(std::string playerClass);
	static std::string RandomMeleeWeapon(std::string playerClass);
	static int RandomNumberOfHats(std::string playerClass);
};