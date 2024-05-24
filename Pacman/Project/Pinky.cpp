#include "Pinky.hpp"
#include "GameStateMachine.hpp"
Pinky::Pinky() : Ghost({ 13.5f,17 }, 1)
{
	Animation u{ 0,2 };
	u.sprites.push_back(46);
	u.sprites.push_back(47);

	Animation l{ 0,2 };
	l.sprites.push_back(44);
	l.sprites.push_back(45);

	Animation d{ 0,2 };
	d.sprites.push_back(48);
	d.sprites.push_back(49);

	Animation r{ 0,2 };
	r.sprites.push_back(42);
	r.sprites.push_back(43);

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

void Pinky::Render()
{
	if (GameStateMachine::Instance().game->GetStage() == 0)
	{
		Renderer::Instance().DrawSprite(0, { 4,3 }, position, WHITE);
	}
	if (GameStateMachine::Instance().game->GetStage() == 1)
	{
		if (alive)
		{
			if (ghostMode == Ghost::Frightened)
			{
				if(PelletEffectEnding())
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
	}
	//DrawRectangleLinesEx({GetTargetTile().x*8*SCALE_FACTOR, GetTargetTile().y * 8*SCALE_FACTOR, 8*SCALE_FACTOR,8*SCALE_FACTOR}, 2, PINK);
}

void Pinky::Brain()
{
	Vector2 tileGo = { 0,0 };
	if (alive)
	{
		switch (ghostMode)
		{
		case Ghost::Scatter:
			tileGo = { 2,0 };
			break;
		case Ghost::Chase:
			tileGo = EntityManager::Instance().GetEntityAt(0)->GetTileOfEntity();
			tileGo.x += 4 * direction.x;
			tileGo.y += 4 * direction.y;
			if (direction.y == -1)
			{
				tileGo.x -= 4;
			}
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
			Ghost::DecideDirection(true);
			alive = true;
			ghostMode = (Mode)LevelManager::Instance().RequestCurrentMode(true);
			if(stage==4)stage = 5;
		}
	}
	SetTargetTile(tileGo);
}
