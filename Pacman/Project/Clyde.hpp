#pragma once
#include "Ghost.hpp"
class Clyde : public Ghost
{
private:
	Animator anim;
public:
	Clyde();
	void Render()override;
	void Brain() override;
};

