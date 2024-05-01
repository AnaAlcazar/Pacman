#pragma once
#include "EntityManager.hpp"

class Pacman : public Entity
{
private:
	float pelletEffect;
	int pelletMultiplier;
public:
	Pacman();
	void Input()override;
	void Logic()override;
	void Render()override;
	void SetTargetTile(Vector2 tile)override;
};

