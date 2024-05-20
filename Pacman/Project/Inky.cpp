#include "Inky.hpp"
#include "GameStateMachine.hpp"
Inky::Inky() : Ghost({ 12, 17 }, 4)
{
	Animation u{ 0,2 };
	u.sprites.push_back(60);
	u.sprites.push_back(61);

	Animation l{ 0,2 };
	l.sprites.push_back(58);
	l.sprites.push_back(59);

	Animation d{ 0,2 };
	d.sprites.push_back(62);
	d.sprites.push_back(63);

	Animation r{ 0,2 };
	r.sprites.push_back(56);
	r.sprites.push_back(57);

	Animation f{ 0,2 };
	f.sprites.push_back(36);
	f.sprites.push_back(37);

	anim.animations.push_back(u);
	anim.animations.push_back(l);
	anim.animations.push_back(d);
	anim.animations.push_back(r);
	anim.animations.push_back(f);
	SetTargetTile(StartTile);
}

void Inky::Render()
{
	if (GameStateMachine::Instance().game->GetStage() == 1)
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
	DrawRectangleLinesEx({ GetTargetTile().x * 8 * SCALE_FACTOR, GetTargetTile().y * 8 * SCALE_FACTOR, 8 * SCALE_FACTOR,8 * SCALE_FACTOR }, 2, SKYBLUE);
}

void Inky::Brain()
{
	float distance;
	Vector2 tileGo = { 0,0 };
	if (alive)
	{
		switch (ghostMode)
		{
		case Ghost::Scatter:
			tileGo = { 27,35 };
			break;
		case Ghost::Chase:
			distance = hypot(EntityManager::Instance().GetEntityAt(1)->GetPosition().x - position.x, EntityManager::Instance().GetEntityAt(1)->GetPosition().y - position.y);
			if (distance < 24)
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
	}
	else
	{
		tileGo = { 14,14 };
		if (GetTileOfEntity().x == tileGo.x && GetTileOfEntity().y == tileGo.y)
		{
			alive = true;
			ghostMode = Scatter;
			Ghost::DecideDirection(true);
		}
	}
	SetTargetTile(tileGo);
}
