#include "Inky.hpp"

Inky::Inky()
{
	Animation u{ 0,2 };
	u.sprites.push_back(60);
	u.sprites.push_back(61);

	Animation l{ 0,2 };
	u.sprites.push_back(58);
	u.sprites.push_back(59);

	Animation d{ 0,2 };
	u.sprites.push_back(62);
	u.sprites.push_back(63);

	Animation r{ 0,2 };
	u.sprites.push_back(56);
	u.sprites.push_back(57);

	Animation f{ 0,2 };
	u.sprites.push_back(36);
	u.sprites.push_back(37);

	anim.animations.push_back(u);
	anim.animations.push_back(l);
	anim.animations.push_back(d);
	anim.animations.push_back(r);
	anim.animations.push_back(f);
}

void Inky::Render()
{
	if (alive)
	{
		if (ghostMode == Ghost::Frightened)
		{
			anim.Animate(position, 4, 0.1f, true);
		}
		else
		{
			if (direction.x == 0 && direction.y == -1)anim.Animate(position, 0, 0.1f, true);
			else if (direction.x == -1 && direction.y == 0)anim.Animate(position, 1, 0.1f, true);
			else if (direction.x == 0 && direction.y == 1)anim.Animate(position, 2, 0.1f, true);
			else if (direction.x == 1 && direction.y == 0)anim.Animate(position, 3, 0.1f, true);
		}
	}
	else
	{
		if (direction.x == 0 && direction.y == -1) Renderer::Instance().DrawSprite(0, { 8,5 }, position, WHITE);
		else if (direction.x == -1 && direction.y == 0) Renderer::Instance().DrawSprite(0, { 9,4 }, position, WHITE);
		else if (direction.x == 0 && direction.y == 1) Renderer::Instance().DrawSprite(0, { 9,5 }, position, WHITE);
		else if (direction.x == 1 && direction.y == 0) Renderer::Instance().DrawSprite(0, { 8,4 }, position, WHITE);
	}
}

void Inky::Brain()
{
	float distance;
	Vector2 tileGo = { 0,0 };
	switch (ghostMode)
	{
	case Ghost::Scatter:
		tileGo = { 26,27 };
		break;
	case Ghost::Chase:
		distance = hypot(EntityManager::Instance().GetEntityAt(1)->GetPosition().x - position.x, EntityManager::Instance().GetEntityAt(1)->GetPosition().y - position.y);
		if(distance < 24)
			tileGo = EntityManager::Instance().GetEntityAt(0)->GetTileOfEntity();
		else
			tileGo = { (float)((int)(rand() % 28)), (float)((int)(rand() % 31 + 3)) };
		break;
	case Ghost::Frightened:
		tileGo = { (float)((int)(rand() % 28)), (float)((int)(rand() % 31 + 3)) };
		break;
	default:
		break;
	}
	SetTargetTile(tileGo);
}
