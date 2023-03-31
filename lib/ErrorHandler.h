#pragma once

#include <iostream>
#include <string>
#include <fstream>

#include "Colors.h"

void PrintError(std::string message)
{
	std::cout << OutputColor.bold_red << "ERROR: " << OutputColor.reset << message << endl;
	exit(1);
}

void PrintWarning(std::string message)
{
	std::cout << OutputColor.bold_magenta << "WARNING: " << OutputColor.reset << message << endl;
}

void CheckInputFile(std::string name)
{
	std::ifstream file(name.c_str());
	if(!file.is_open()) PrintError("File " + name + " not found");
}

void CheckOutputFile(std::string name)
{
	std::ofstream file(name.c_str());
	if(!file.is_open()) PrintError("File " + name + " cannot be created");
}
