#pragma once
#include "EntityManager.hpp"
#include "Renderer.hpp"
class Pacman : public Entity
{
private:
	float pelletEffect;
	int pelletMultiplier;
	float scoreTimer;
	Animator anim;
public:
	Pacman();
	float GetPelletEffect();
	int GetPelletMultiplier();
	void ResetPelletEffect();
	void Input()override;
	void Logic()override;
	void Render()override;
	void Kill()override;
	void Revive();
	bool IsAlive();
	void Die()override;
	void EatPellet();
	void SetTargetTile(Vector2 tile)override;
};