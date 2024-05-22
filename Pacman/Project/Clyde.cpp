#include "Clyde.hpp"
#include "GameStateMachine.hpp"
Clyde::Clyde() : Ghost({ 15,17 }, 8)
{
	Animation u{ 0,2 };
	u.sprites.push_back(74);
	u.sprites.push_back(75);

	Animation l{ 0,2 };
	l.sprites.push_back(72);
	l.sprites.push_back(73);

	Animation d{ 0,2 };
	d.sprites.push_back(76);
	d.sprites.push_back(77);

	Animation r{ 0,2 };
	r.sprites.push_back(70);
	r.sprites.push_back(71);

	Animation f{ 0,2 };
	f.sprites.push_back(36);
	f.sprites.push_back(37);

	Animation fe{ 0,4 };
	fe.sprites.push_back(36);
	fe.sprites.push_back(37);
	fe.sprites.push_back(50);
	fe.sprites.push_back(51);

	anim.animations.push_back(u);
	anim.animations.push_back(l);
	anim.animations.push_back(d);
	anim.animations.push_back(r);
	anim.animations.push_back(f);
	anim.animations.push_back(fe);
	SetTargetTile(StartTile);
}

void Clyde::Render()
{
	if (GameStateMachine::Instance().game->GetStage() == 0)
	{
		Renderer::Instance().DrawSprite(0, { 4,5 }, position, WHITE);
	}
	if (GameStateMachine::Instance().game->GetStage() == 1)
	{
		if (alive)
		{
			if (ghostMode == Ghost::Frightened)
			{
				if (PelletEffectEnding())
					anim.Animate(position, 5, 0.1f, true);
				else
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
		DrawRectangleLinesEx({ GetTargetTile().x * 8 * SCALE_FACTOR,GetTargetTile().y * 8 * SCALE_FACTOR, 8 * SCALE_FACTOR, 8 * SCALE_FACTOR }, 2, WHITE);
	}
	//DrawRectangleLinesEx({ GetTargetTile().x * 8 * SCALE_FACTOR, GetTargetTile().y * 8 * SCALE_FACTOR, 8 * SCALE_FACTOR,8 * SCALE_FACTOR }, 2, ORANGE);
}

void Clyde::Brain()
{
	Vector2 tileGo = { 0,0 };
	if (alive)
	{
		switch (ghostMode)
		{
		case Ghost::Scatter:
			tileGo = { 0,35 };
			break;
		case Ghost::Chase:
			tileGo = { (float)((int)(rand() % 28)), (float)((int)(rand() % 31 + 3)) };
			break;
		case Ghost::Frightened:
			tileGo = { (float)((int)(rand() % 28)), (float)((int)(rand() % 31 + 3)) };
			break;
		default:
			break;
		}
	}
	else if (!alive)
	{
		tileGo = { 14,14 };
		if (GetTileOfEntity().x == tileGo.x && GetTileOfEntity().y == tileGo.y)
		{
			ghostMode = (Mode)LevelManager::Instance().RequestCurrentMode(true);
			Ghost::DecideDirection(true);
			alive = true;
		}
	}
	SetTargetTile(tileGo);
}
