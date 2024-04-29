#pragma once
#include "EntityManager.hpp"

class Pacman : public Entity
{
private:
	int points;
	float pelletEffect;
	int pelletMultiplier;
	void TrySetDirection(Vector2 dir);
public:
	Pacman();
	void Input()override;
	void Logic()override;
	void Render()override;
};

