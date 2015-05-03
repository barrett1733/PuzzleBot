#include "LoadFile.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>

bool LoadFile::checkDelims(std::string str)
{
	int delim = 0;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == delimiter)
			delim++;
	}

	if (DEBUG)
	{
		if (!str.empty() && str[0] != comment && delim == 1)
			std::cout << "O ";
		else
			std::cout << "X ";
		if (str.empty())
			std::cout << "NEWLINE - " << str << std::endl;
		else if (str[0] == comment)
			std::cout << "COMMENT - " << str << std::endl;
		else if (delim == 1)
			std::cout << "NORMAL  - " << str << std::endl;
		else
			std::cout << "ERROR   - " << str << std::endl;
	}

	if (!str.empty() && str[0] != comment && delim == 1)
		return true;
	else
		return false;
}

void LoadFile::addFileToQueue(std::string filename)
{
	if (!loadedFiles.count(filename))
	{
		loadedFiles.insert(filename);
		fileQueue.push(filename);
	}
}

void LoadFile::loadFile(std::string filename)
{
	addFileToQueue(filename);
	while (!fileQueue.empty())
	{
		file.open(fileQueue.front());

		std::string line;

		if (file.fail())
		{
			std::cerr << "File not found: " << fileQueue.front() << std::endl;
		}
		else
		{
			while (!file.eof())
			{
				getline(file, line);
				parse(line);
			}
		}
		fileQueue.pop();
		file.close();
	}
	postLoad();
}

void LoadFile::parse(std::string line)
{
	std::string name, type;
	line.erase(std::remove_if(line.begin(), line.end(), isspace), line.end());
	if (checkDelims(line))
	{
		int lineDelim = line.find(delimiter);

		name = line.substr(0, lineDelim);
		type = line.substr(lineDelim + 1, line.size());

		//if (DEBUG)
		//	std::cout << name << "\t" << type << std::endl;
		if (name == "file")
		{
			addFileToQueue(type);
		}
		else if (name == "print")
		{
			std::cout << type << std::endl;
		}
		else
		{
			store(name, type);
		}
	}

}

