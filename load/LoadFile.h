#pragma once
#include <string>
#include <fstream>
#include <set>
#include <queue>

class LoadFile
{
	const bool DEBUG = true;
	const char delimiter = '=';
	const char comment = '#';

	int groupCounter = 0;
	std::vector<std::pair<std::string, std::string>> groupStrings;

	std::ifstream file;
	typedef std::set<std::string> FileSet;
	typedef std::queue<std::string> FileQueue;

	FileSet loadedFiles;
	FileQueue fileQueue;
	void parse(std::string line);
	bool checkDelims(std::string);
	void addFileToQueue(std::string);
public:
	void loadFile(std::string filename);
	virtual void postLoad() {};
	virtual void store(std::string object, std::string data) = 0;
};

