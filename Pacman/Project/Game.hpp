#pragma once
#include "ScreenManager.hpp"
#include "EntityManager.hpp"
class Game
{
private:
	int lives;
	int score;
    int mode;
	int pointsLayout[36][28] = {
           {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
           {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
           {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
           {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
           {-1, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, -1, -1, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, -1},
           {-1, 19, -1, -1, -1, -1, 19, -1, -1, -1, -1, -1, 19, -1, -1, 19, -1, -1, -1, -1, -1, 19, -1, -1, -1, -1, 19, -1},
           {-1, 20, -1, -1, -1, -1, 19, -1, -1, -1, -1, -1, 19, -1, -1, 19, -1, -1, -1, -1, -1, 19, -1, -1, -1, -1, 20, -1},
           {-1, 19, -1, -1, -1, -1, 19, -1, -1, -1, -1, -1, 19, -1, -1, 19, -1, -1, -1, -1, -1, 19, -1, -1, -1, -1, 19, -1},
           {-1, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, -1},
           {-1, 19, -1, -1, -1, -1, 19, -1, -1, 19, -1, -1, -1, -1, -1, -1, -1, -1, 19, -1, -1, 19, -1, -1, -1, -1, 19, -1},
           {-1, 19, -1, -1, -1, -1, 19, -1, -1, 19, -1, -1, -1, -1, -1, -1, -1, -1, 19, -1, -1, 19, -1, -1, -1, -1, 19, -1},
           {-1, 19, 19, 19, 19, 19, 19, -1, -1, 19, 19, 19, 19, -1, -1, 19, 19, 19, 19, -1, -1, 19, 19, 19, 19, 19, 19, -1},
           {-1, -1, -1, -1, -1, -1, 19, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 19, -1, -1, -1, -1, -1, -1},
           {-1, -1, -1, -1, -1, -1, 19, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 19, -1, -1, -1, -1, -1, -1},
           {-1, -1, -1, -1, -1, -1, 19, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 19, -1, -1, -1, -1, -1, -1},
           {-1, -1, -1, -1, -1, -1, 19, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 19, -1, -1, -1, -1, -1, -1},
           {-1, -1, -1, -1, -1, -1, 19, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 19, -1, -1, -1, -1, -1, -1},
           {-1, -1, -1, -1, -1, -1, 19, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 19, -1, -1, -1, -1, -1, -1},
           {-1, -1, -1, -1, -1, -1, 19, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 19, -1, -1, -1, -1, -1, -1},
           {-1, -1, -1, -1, -1, -1, 19, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 19, -1, -1, -1, -1, -1, -1},
           {-1, -1, -1, -1, -1, -1, 19, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 19, -1, -1, -1, -1, -1, -1},
           {-1, -1, -1, -1, -1, -1, 19, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 19, -1, -1, -1, -1, -1, -1},
           {-1, -1, -1, -1, -1, -1, 19, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 19, -1, -1, -1, -1, -1, -1},
           {-1, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, -1, -1, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, -1},
           {-1, 19, -1, -1, -1, -1, 19, -1, -1, -1, -1, -1, 19, -1, -1, 19, -1, -1, -1, -1, -1, 19, -1, -1, -1, -1, 19, -1},
           {-1, 19, -1, -1, -1, -1, 19, -1, -1, -1, -1, -1, 19, -1, -1, 19, -1, -1, -1, -1, -1, 19, -1, -1, -1, -1, 19, -1},
           {-1, 20, 19, 19, -1, -1, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, -1, -1, 19, 19, 20, -1},
           {-1, -1, -1, 19, -1, -1, 19, -1, -1, 19, -1, -1, -1, -1, -1, -1, -1, -1, 19, -1, -1, 19, -1, -1, 19, -1, -1, -1},
           {-1, -1, -1, 19, -1, -1, 19, -1, -1, 19, -1, -1, -1, -1, -1, -1, -1, -1, 19, -1, -1, 19, -1, -1, 19, -1, -1, -1},
           {-1, 19, 19, 19, 19, 19, 19, -1, -1, 19, 19, 19, 19, -1, -1, 19, 19, 19, 19, -1, -1, 19, 19, 19, 19, 19, 19, -1},
           {-1, 19, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 19, -1, -1, 19, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 19, -1},
           {-1, 19, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 19, -1, -1, 19, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 19, -1},
           {-1, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, 19, -1},
           {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
           {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
           {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}
	};
public:
    Game();
	void Input();
	void Logic();
	void Render();
    void ResetLayout();
    void RenderPoints();
    void EatDot();
    ~Game();
};