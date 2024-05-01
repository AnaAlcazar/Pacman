#pragma once
#include "EntityManager.hpp"
#include "ScreenManager.hpp"
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
	Mode ghostMode;
	Vector2 IntToDirection(int index);
	bool ContraryDirections();
	bool intersectionDecided;
	int AvaiableDirections();
	void DecideDirection(bool canTurnBack);
public:
	Ghost();
	void Input()override;
	void Logic()override;
	void Render()override;
	void SetTargetTile(Vector2 tile)override;
	~Ghost();
};

