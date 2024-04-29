#pragma once
#include "EntityManager.hpp"
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
public:
	Ghost();
	void Input()override;
	void Logic()override;
	void Render()override;
	~Ghost();
};

