#pragma once
#include "raylib.h"

class Entity
{
private:
	enum Type
	{
		Player,
		Ghost
	};
	Type type;
	Vector2 position;
	Vector2 direction, nextDirection;
	float speed;
public:
#pragma region Constructor & Destructor
	Entity(const Type t, const Vector2 pos, const Vector2 dir, const float sp);
	virtual ~Entity();
#pragma endregion

#pragma region Getters
	Vector2 GetPosition();
	Vector2 GetDirection();
	Vector2 GetTileOfEntity();
	bool EntityIsCenteredInTile();
	bool IsAlive();
#pragma endregion

#pragma region Functions
	virtual void Input() = 0;
	virtual void Logic() = 0;
	virtual void Render() = 0;
#pragma endregion

};

class Pacman : public Entity
{
private:
	int lives;
	int points;
	float pelletEffect;
	int pelletMultiplier;
public:
	void Input()override;
	void Logic()override;
	void Render()override;
};

class Ghost : public Entity
{
private:
	enum Mode
	{
		Scatter,
		Chase,
		Frightened,
	};
	float ghostModeTimer;
	int modeRound;
	Vector2 targetTile;
public:
	void Logic()override;
	void Render()override;
};

class EntityManager
{
};