#pragma once
#include "Ghost.hpp"
class Blinky : public Ghost
{
private:
	Animator anim;
public:
	Blinky();
	void Render()override;
	void SetTargetTile(Vector2 tile)override;
};