#include "BehaviorTree.h"
#include <lib\libconfig.h++>
#include <fstream>
#include <iostream>
#include <algorithm>

using namespace libconfig;

#define DEBUG false

BehaviorTree::BehaviorTree()
{
}


BehaviorTree::~BehaviorTree()
{
}

bool BehaviorTree::checkDelims(std::string str)
{
	int delim = 0;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == '=')
			delim++;
	}

	if (DEBUG)
	{
		if (str.empty())
			std::cout << "NEWLINE - " << str << std::endl;
		else if (str[0] == '!')
			std::cout << "COMMENT - " << str << std::endl;
		else if (delim == 1)
			std::cout << "NORMAL  - " << str << std::endl;
		else
			std::cout << "ERROR   - " << str << std::endl;
	}
	if (!str.empty() && str[0] != '!' && delim == 1)
		return true;
	else
		return false;
}

void BehaviorTree::loadFromFile(std::string file)
{
	std::ifstream cfg;
	cfg.open(file);

	std::string line, name, type;
	std::vector<std::string> dataContainer;
	std::vector<std::vector<std::string>> data;
	std::string delim = "=";

	if (cfg.fail())
		std::cerr << "Config file not found: " << file << std::endl;

	else while (!cfg.eof())
	{
		getline(cfg, line);
		line.erase(std::remove_if(line.begin(), line.end(), isspace), line.end());
		
		if (checkDelims(line))
		{
			int lineDelim = line.find(delim);

			name = line.substr(0, lineDelim);
			type = line.substr(lineDelim + 1, line.size());

			std::cout << name << "\t" << type << std::endl;
			if (name == "name" || dataContainer.size() > 0)
			{
				dataContainer.push_back(type);
			}
			if (dataContainer.size() > 3)
			{
				data.push_back(dataContainer);
				dataContainer.clear();
			}
		}
	}
	std::cout << std::endl << "DATA" << std::endl;
	for (int i = 0; i < data.size(); i++)
	{
		std::cout << "Data " << i << std::endl;
		for (int j = 0; j < data[i].size(); j++)
		{
			std::cout << "\t" << data[i][j] << std::endl;
		}
	}

}