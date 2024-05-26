#pragma once
#include "Ghost.hpp"
class Inky : public Ghost
{
private:
	Animator anim;
public:
	Inky();
	void Render()override;
	void Brain() override;
	~Inky(){}
};

