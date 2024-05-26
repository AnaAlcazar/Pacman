#pragma once
#include "Ghost.hpp"
class Pinky : public Ghost
{
private:
	Animator anim;
public:
	Pinky();
	void Render()override;
	void Brain() override;
	~Pinky(){}
};

