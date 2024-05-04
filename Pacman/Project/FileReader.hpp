#pragma once
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;
class FileReader
{
private:
	FileReader();
	~FileReader();
public:
	static FileReader& Instance()
	{
		static FileReader instance;
		return instance;
	}
	int ReadHighScore();
	void NewHighScore(int score);
};