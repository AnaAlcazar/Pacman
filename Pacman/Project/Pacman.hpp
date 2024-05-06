#pragma once
#include "EntityManager.hpp"
#include "Renderer.hpp"
class Pacman : public Entity
{
private:
	float pelletEffect;
	int pelletMultiplier;
	Animator anim;
public:
	Pacman();
	void Input()override;
	void Logic()override;
	void Render()override;
	void SetTargetTile(Vector2 tile)override;
};