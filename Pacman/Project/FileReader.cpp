#include "FileReader.hpp"
#include <iostream>
#include <fstream>
using namespace std;
FileReader::FileReader()
{
}

FileReader::~FileReader()
{
}

int FileReader::ReadHighScore()
{
	int score = 0;
	fstream highScore;
	highScore.open("assets/files/HighScore.txt", ios::in);
	if (highScore.is_open())
	{
		cout << "File opened for reading" << endl;
		highScore >> score;
		highScore.close();
	}
	return score;
}

void FileReader::NewHighScore(int score)
{
	fstream highScore;
	highScore.open("assets/files/HighScore.txt", ios::out);
	if (highScore.is_open())
	{
		cout << "File opened for writting" << endl;
		highScore << score;
		highScore.close();
	}
}
