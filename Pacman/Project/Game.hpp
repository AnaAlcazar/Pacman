#pragma once
#include "ScreenManager.hpp"
#include "EntityManager.hpp"
#include "Levels.hpp"
#include <vector>

class Game
{
private:
    float timer;
    int stage;
    int level;
	int lives;
	int score;
    int highscore;
    int eatenDots;
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
    void Start(bool rs);
    void ResetTimer();
	void Input();
	void Logic();
	void Render();
    void ResetLayout();
    void RenderPoints();
    void EatDot();
    void End();
    void AddScore(int s);
    int GetStage();
    void SetStage(int s);
    ~Game();
};