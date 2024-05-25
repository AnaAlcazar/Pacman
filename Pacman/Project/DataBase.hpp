#pragma once
#include "Levels.hpp"
class DataBase
{
private:
	vector <Level*> OriginalLevels;
	DataBase();
	~DataBase();
public:
	static DataBase& Instance()
	{
		static DataBase instance;
		return instance;
	}
	void FreeMemory();
	vector <Level*> GetOriginalLevels();
};