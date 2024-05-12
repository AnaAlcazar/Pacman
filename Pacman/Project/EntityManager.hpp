#pragma once
#include "raylib.h"
#include <vector>

using namespace std;

class Entity
{
protected:
	enum Type
	{
		Player,
		Enemy
	};
	Type type;
	Vector2 position;
	Vector2 direction, nextDirection;
	bool alive;
	float speed;
	Vector2 StartTile;
	void Move();
	
public:
#pragma region Constructor & Destructor
	Entity(const Type t, const Vector2 pos, const Vector2 dir, const float sp);
	void TrySetDirection(Vector2 dir);
	virtual ~Entity();
#pragma endregion

#pragma region Getters
	Vector2 GetPosition();
	Vector2 GetDirection();
	Vector2 GetTileOfEntity();
	bool EntityIsCenteredInTile(Vector2 tile);
	bool IsAlive();
#pragma endregion

#pragma region Functions
	virtual void Input() = 0;
	virtual void Logic() = 0;
	virtual void Render() = 0;
	virtual void SetTargetTile(Vector2 tile) = 0;
#pragma endregion
};

class EntityManager
{
private:
	vector <Entity*> entityList;
	EntityManager();
	~EntityManager();
public:
	static EntityManager& Instance()
	{
		static EntityManager instance;
		return instance;
	}
	int entityListLength();
	Entity* GetEntityAt(int index);
	void Input();
	void Logic();
	void Render();
	void SetTargetTile(Entity* entity, Vector2 tile);
};