#pragma once
#include "Renderer.hpp"
#include <vector>
using namespace std;

class Screen
{
private:
	int layout[36][28];
public:
	Screen(const int layout_[36][28]);
	void RenderLayout(const Color color_);
};

class ScreenManager
{
private:
	vector <Screen> Screens;
public:
	ScreenManager();
	void Render(const int index, const Color color_);
	void Render(const int index, const int color_);
};