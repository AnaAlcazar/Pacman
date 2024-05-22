#pragma once
#include "EntityManager.hpp"
#include "ScreenManager.hpp"
#include "Pacman.hpp"
#include "Globals.hpp"
#include "Levels.hpp"
class Ghost : public Entity
{
	friend class Game;
	friend class LevelManager;
private:
	Vector2 targetTile;
	Vector2 IntToDirection(int index);
	bool ContraryDirections();
	bool intersectionDecided;
	int AvaiableDirections();
public:
	enum Mode
	{
		Scatter,
		Chase,
		Frightened
	};
	int stage;
	float timerToStart;
	Ghost(Vector2 st, float t);
	void Input()override;
	void Logic()override;
	virtual void Brain();
	virtual void Render()override;
	void SetTargetTile(Vector2 tile) override;
	void ChangeMode(Mode m);
	void Kill()override;
	void Die()override;
	~Ghost();
protected:
	Vector2 GetTargetTile();
	void DecideDirection(bool canTurnBack);
	bool PelletEffectEnding();
	Mode ghostMode;
	Mode RequestActualMode(bool force);
};

