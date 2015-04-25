#include "LoadFile.h"
#include <lib\libconfig.h++>
#include <iostream>
#include <iomanip>
#include <cstdlib>

LoadFile::LoadFile()
{
}


LoadFile::~LoadFile()
{
}

void LoadFile::loadFile(std::string filename)
{
	libconfig::Config cfg;
	cfg.readFile(filename.c_str());
}
void LoadFile::parse(std::string line)
{
	/*
	std::stringstream ss(line);
	std::string object;
	std::string valueString;
	int         valueInt[3] = { 0 };
	double      valueDouble = 0.0;
	float		valueFloat = 0.0;

	bool accepted;
	object = "";

	valueInt[0] = 0;
	valueInt[1] = 0;
	valueInt[2] = 0;
	valueDouble = 0.0;
	valueString = "";

	ss >> object;
	if (object == "FILE")
	{
		ss >> valueString;
		if (!loadedFiles.count(valueString))
			loadFile(valueString);
	}
	else
	{
		ss >> valueString;
		if (object == "STRING")
		{
			ss >> valueString;
		}
		else if (object == "FLOAT")
		{
			ss >> valueFloat;
		}
		else if (object == "INT")
		{
			ss >> valueInt[0];
		}
		else if (object == "INT_PAIR")
		{
			ss >> valueInt[0];
			ss >> valueInt[1];
		}
		else if (object == "INT_TRIPLE")
		{
			ss >> valueInt[0];
			ss >> valueInt[1];
			ss >> valueInt[2];
		}
		else if (object == "COLOR")
		{
			ss >> valueInt[0];
			ss >> valueInt[1];
			ss >> valueInt[2];
		}
	}
	*/
}

void LoadFile::store(std::string object, std::string data)
{

}
