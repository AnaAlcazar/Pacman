#include "Blinky.hpp"

Blinky::Blinky()
{
	Animation u{ 0,2 };
	u.sprites.push_back(32);
	u.sprites.push_back(33);

	Animation l{ 0,2 };
	u.sprites.push_back(30);
	u.sprites.push_back(31);

	Animation d{ 0,2 };
	u.sprites.push_back(34);
	u.sprites.push_back(35);

	Animation r{ 0,2 };
	u.sprites.push_back(28);
	u.sprites.push_back(29);

	anim.animations.push_back(u);
	anim.animations.push_back(l);
	anim.animations.push_back(d);
	anim.animations.push_back(r);
}

void Blinky::Render()
{
}

void Blinky::SetTargetTile(Vector2 tile)
{
}
