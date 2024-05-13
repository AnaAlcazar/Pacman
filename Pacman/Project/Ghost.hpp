#pragma once
#include "EntityManager.hpp"
#include "ScreenManager.hpp"
class Ghost : public Entity
{
private:
	
	float ghostModeTimer;
	int modeRound;
	Vector2 targetTile;
	
	Vector2 IntToDirection(int index);
	bool ContraryDirections();
	bool intersectionDecided;
	int AvaiableDirections();
	void DecideDirection(bool canTurnBack);
public:
	Ghost();
	void Input()override;
	void Logic()override;
	virtual void Brain() {}
	virtual void Render()override;
	void SetTargetTile(Vector2 tile) override;
	void Kill()override;
	void Die()override;
	~Ghost();

protected:
	enum Mode
	{
		Scatter,
		Chase,
		Frightened,
	};
	Mode ghostMode;
};

