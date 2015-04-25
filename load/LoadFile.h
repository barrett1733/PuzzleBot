#pragma once
#include <string>
#include <iostream>
#include <set>
#include "../config/Config.h"

class LoadFile
{
	std::set<std::string> loadedFiles;
	void parse(std::string line);
	void store(std::string object, std::string data);
public:
	LoadFile();
	~LoadFile();
	void loadFile(std::string filename);
};

