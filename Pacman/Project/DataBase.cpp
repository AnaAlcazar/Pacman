#include "DataBase.hpp"

DataBase::DataBase()
{
#pragma region LevelDeclarations
	Level* l1 = new Level(0.8f, 0.9f, 0.71f, 0.79f, 0.75f, 0.5f, 0.4f, 20, 0.8f, 10, 0.85f, 6, 5);
	Level* l2 = new Level(0.9f, 0.95f, 0.79f, 0.83f, 0.85f, 0.55f, 0.45f, 30, 0.9f, 15, 0.95f, 5, 5);
	Level* l3 = new Level(0.9f, 0.95f, 0.79f, 0.83f, 0.85f, 0.55f, 0.45f, 40, 0.9f, 20, 0.95f, 4, 5);
	Level* l4 = new Level(0.9f, 0.95f, 0.79f, 0.83f, 0.85f, 0.55f, 0.45f, 40, 0.9f, 20, 0.95f, 3, 5);
	Level* l5 = new Level(1, 1, 0.87f, 0.87f, 0.95f, 0.6f, 0.5f, 40, 1, 20, 1, 2, 5);
	Level* l6 = new Level(1, 1, 0.87f, 0.87f, 0.95f, 0.6f, 0.5f, 50, 1, 25, 1, 5, 5);
	Level* l7 = new Level(1, 1, 0.87f, 0.87f, 0.95f, 0.6f, 0.5f, 50, 1, 25, 1, 2, 5);
	Level* l8 = new Level(1, 1, 0.87f, 0.87f, 0.95f, 0.6f, 0.5f, 50, 1, 25, 1, 2, 5);
	Level* l9 = new Level(1, 1, 0.87f, 0.87f, 0.95f, 0.6f, 0.5f, 60, 1, 30, 1, 1, 3);
	Level* l10 = new Level(1, 1, 0.87f, 0.87f, 0.95f, 0.6f, 0.5f, 60, 1, 30, 1, 5, 5);
	Level* l11 = new Level(1, 1, 0.87f, 0.87f, 0.95f, 0.6f, 0.5f, 60, 1, 30, 1, 2, 5);
	Level* l12 = new Level(1, 1, 0.87f, 0.87f, 0.95f, 0.6f, 0.5f, 80, 1, 40, 1, 1, 3);
	Level* l13 = new Level(1, 1, 0.87f, 0.87f, 0.95f, 0.6f, 0.5f, 80, 1, 40, 1, 1, 3);
	Level* l14 = new Level(1, 1, 0.87f, 0.87f, 0.95f, 0.6f, 0.5f, 80, 1, 40, 1, 3, 5);
	Level* l15 = new Level(1, 1, 0.87f, 0.87f, 0.95f, 0.6f, 0.5f, 100, 1, 50, 1, 1, 3);
	Level* l16 = new Level(1, 1, 0.87f, 0.87f, 0.95f, 0.6f, 0.5f, 100, 1, 50, 1, 1, 3);
	Level* l17 = new Level(1, 1, 0.87f, 0.87f, 0.95f, 0.6f, 0.5f, 100, 1, 50, 1, 0.1f, 1);
	Level* l18 = new Level(1, 1, 0.87f, 0.87f, 0.95f, 0.6f, 0.5f, 100, 1, 50, 1, 1, 3);
	Level* l19 = new Level(1, 1, 0.87f, 0.87f, 0.95f, 0.6f, 0.5f, 120, 1, 60, 1, 0.1f, 1);
	Level* l20 = new Level(1, 1, 0.87f, 0.87f, 0.95f, 0.6f, 0.5f, 120, 1, 60, 1, 0.1f, 1);
	Level* l21 = new Level(0.9f, 1, 0.79f, 0.87f, 0.95f, 0.6f, 0.5f, 120, 1, 60, 1, 0.1f, 1);
#pragma endregion
#pragma region GhostBehaviourDeclarations
#pragma region Level1
	l1->GenerateGhostBehaviour(Ghost::Scatter, 7);
	l1->GenerateGhostBehaviour(Ghost::Chase, 20);
	l1->GenerateGhostBehaviour(Ghost::Scatter, 7);
	l1->GenerateGhostBehaviour(Ghost::Chase, 20);
	l1->GenerateGhostBehaviour(Ghost::Scatter, 5);
	l1->GenerateGhostBehaviour(Ghost::Chase, 20);
	l1->GenerateGhostBehaviour(Ghost::Scatter, 5);
	l1->GenerateGhostBehaviour(Ghost::Chase, 20);
#pragma endregion
#pragma region Level2-4
	l2->GenerateGhostBehaviour(Ghost::Scatter, 7);
	l2->GenerateGhostBehaviour(Ghost::Chase, 20);
	l2->GenerateGhostBehaviour(Ghost::Scatter, 7);
	l2->GenerateGhostBehaviour(Ghost::Chase, 20);
	l2->GenerateGhostBehaviour(Ghost::Scatter, 5);
	l2->GenerateGhostBehaviour(Ghost::Chase, 1033);
	l2->GenerateGhostBehaviour(Ghost::Scatter, 1/60);
	l2->GenerateGhostBehaviour(Ghost::Chase, 1);

	l3->GenerateGhostBehaviour(Ghost::Scatter, 7);
	l3->GenerateGhostBehaviour(Ghost::Chase, 20);
	l3->GenerateGhostBehaviour(Ghost::Scatter, 7);
	l3->GenerateGhostBehaviour(Ghost::Chase, 20);
	l3->GenerateGhostBehaviour(Ghost::Scatter, 5);
	l3->GenerateGhostBehaviour(Ghost::Chase, 1033);
	l3->GenerateGhostBehaviour(Ghost::Scatter, 1 / 60);
	l3->GenerateGhostBehaviour(Ghost::Chase, 1);

	l4->GenerateGhostBehaviour(Ghost::Scatter, 7);
	l4->GenerateGhostBehaviour(Ghost::Chase, 20);
	l4->GenerateGhostBehaviour(Ghost::Scatter, 7);
	l4->GenerateGhostBehaviour(Ghost::Chase, 20);
	l4->GenerateGhostBehaviour(Ghost::Scatter, 5);
	l4->GenerateGhostBehaviour(Ghost::Chase, 1033);
	l4->GenerateGhostBehaviour(Ghost::Scatter, 1 / 60);
	l4->GenerateGhostBehaviour(Ghost::Chase, 1);
#pragma endregion
#pragma region Level 5-21
	l5->GenerateGhostBehaviour(Ghost::Scatter, 5);
	l5->GenerateGhostBehaviour(Ghost::Chase, 20);
	l5->GenerateGhostBehaviour(Ghost::Scatter, 5);
	l5->GenerateGhostBehaviour(Ghost::Chase, 20);
	l5->GenerateGhostBehaviour(Ghost::Scatter, 5);
	l5->GenerateGhostBehaviour(Ghost::Chase, 1037);
	l5->GenerateGhostBehaviour(Ghost::Scatter, 1 / 60);
	l5->GenerateGhostBehaviour(Ghost::Chase, 1);

	l6->GenerateGhostBehaviour(Ghost::Scatter, 5);
	l6->GenerateGhostBehaviour(Ghost::Chase, 20);
	l6->GenerateGhostBehaviour(Ghost::Scatter, 5);
	l6->GenerateGhostBehaviour(Ghost::Chase, 20);
	l6->GenerateGhostBehaviour(Ghost::Scatter, 5);
	l6->GenerateGhostBehaviour(Ghost::Chase, 1037);
	l6->GenerateGhostBehaviour(Ghost::Scatter, 1 / 60);
	l6->GenerateGhostBehaviour(Ghost::Chase, 1);

	l7->GenerateGhostBehaviour(Ghost::Scatter, 5);
	l7->GenerateGhostBehaviour(Ghost::Chase, 20);
	l7->GenerateGhostBehaviour(Ghost::Scatter, 5);
	l7->GenerateGhostBehaviour(Ghost::Chase, 20);
	l7->GenerateGhostBehaviour(Ghost::Scatter, 5);
	l7->GenerateGhostBehaviour(Ghost::Chase, 1037);
	l7->GenerateGhostBehaviour(Ghost::Scatter, 1 / 60);
	l7->GenerateGhostBehaviour(Ghost::Chase, 1);

	l8->GenerateGhostBehaviour(Ghost::Scatter, 5);
	l8->GenerateGhostBehaviour(Ghost::Chase, 20);
	l8->GenerateGhostBehaviour(Ghost::Scatter, 5);
	l8->GenerateGhostBehaviour(Ghost::Chase, 20);
	l8->GenerateGhostBehaviour(Ghost::Scatter, 5);
	l8->GenerateGhostBehaviour(Ghost::Chase, 1037);
	l8->GenerateGhostBehaviour(Ghost::Scatter, 1 / 60);
	l8->GenerateGhostBehaviour(Ghost::Chase, 1);

	l9->GenerateGhostBehaviour(Ghost::Scatter, 5);
	l9->GenerateGhostBehaviour(Ghost::Chase, 20);
	l9->GenerateGhostBehaviour(Ghost::Scatter, 5);
	l9->GenerateGhostBehaviour(Ghost::Chase, 20);
	l9->GenerateGhostBehaviour(Ghost::Scatter, 5);
	l9->GenerateGhostBehaviour(Ghost::Chase, 1037);
	l9->GenerateGhostBehaviour(Ghost::Scatter, 1 / 60);
	l9->GenerateGhostBehaviour(Ghost::Chase, 1);

	l10->GenerateGhostBehaviour(Ghost::Scatter, 5);
	l10->GenerateGhostBehaviour(Ghost::Chase, 20);
	l10->GenerateGhostBehaviour(Ghost::Scatter, 5);
	l10->GenerateGhostBehaviour(Ghost::Chase, 20);
	l10->GenerateGhostBehaviour(Ghost::Scatter, 5);
	l10->GenerateGhostBehaviour(Ghost::Chase, 1037);
	l10->GenerateGhostBehaviour(Ghost::Scatter, 1 / 60);
	l10->GenerateGhostBehaviour(Ghost::Chase, 1);

	l11->GenerateGhostBehaviour(Ghost::Scatter, 5);
	l11->GenerateGhostBehaviour(Ghost::Chase, 20);
	l11->GenerateGhostBehaviour(Ghost::Scatter, 5);
	l11->GenerateGhostBehaviour(Ghost::Chase, 20);
	l11->GenerateGhostBehaviour(Ghost::Scatter, 5);
	l11->GenerateGhostBehaviour(Ghost::Chase, 1037);
	l11->GenerateGhostBehaviour(Ghost::Scatter, 1 / 60);
	l11->GenerateGhostBehaviour(Ghost::Chase, 1);

	l12->GenerateGhostBehaviour(Ghost::Scatter, 5);
	l12->GenerateGhostBehaviour(Ghost::Chase, 20);
	l12->GenerateGhostBehaviour(Ghost::Scatter, 5);
	l12->GenerateGhostBehaviour(Ghost::Chase, 20);
	l12->GenerateGhostBehaviour(Ghost::Scatter, 5);
	l12->GenerateGhostBehaviour(Ghost::Chase, 1037);
	l12->GenerateGhostBehaviour(Ghost::Scatter, 1 / 60);
	l12->GenerateGhostBehaviour(Ghost::Chase, 1);

	l13->GenerateGhostBehaviour(Ghost::Scatter, 5);
	l13->GenerateGhostBehaviour(Ghost::Chase, 20);
	l13->GenerateGhostBehaviour(Ghost::Scatter, 5);
	l13->GenerateGhostBehaviour(Ghost::Chase, 20);
	l13->GenerateGhostBehaviour(Ghost::Scatter, 5);
	l13->GenerateGhostBehaviour(Ghost::Chase, 1037);
	l13->GenerateGhostBehaviour(Ghost::Scatter, 1 / 60);
	l13->GenerateGhostBehaviour(Ghost::Chase, 1);

	l14->GenerateGhostBehaviour(Ghost::Scatter, 5);
	l14->GenerateGhostBehaviour(Ghost::Chase, 20);
	l14->GenerateGhostBehaviour(Ghost::Scatter, 5);
	l14->GenerateGhostBehaviour(Ghost::Chase, 20);
	l14->GenerateGhostBehaviour(Ghost::Scatter, 5);
	l14->GenerateGhostBehaviour(Ghost::Chase, 1037);
	l14->GenerateGhostBehaviour(Ghost::Scatter, 1 / 60);
	l14->GenerateGhostBehaviour(Ghost::Chase, 1);

	l15->GenerateGhostBehaviour(Ghost::Scatter, 5);
	l15->GenerateGhostBehaviour(Ghost::Chase, 20);
	l15->GenerateGhostBehaviour(Ghost::Scatter, 5);
	l15->GenerateGhostBehaviour(Ghost::Chase, 20);
	l15->GenerateGhostBehaviour(Ghost::Scatter, 5);
	l15->GenerateGhostBehaviour(Ghost::Chase, 1037);
	l15->GenerateGhostBehaviour(Ghost::Scatter, 1 / 60);
	l15->GenerateGhostBehaviour(Ghost::Chase, 1);

	l16->GenerateGhostBehaviour(Ghost::Scatter, 5);
	l16->GenerateGhostBehaviour(Ghost::Chase, 20);
	l16->GenerateGhostBehaviour(Ghost::Scatter, 5);
	l16->GenerateGhostBehaviour(Ghost::Chase, 20);
	l16->GenerateGhostBehaviour(Ghost::Scatter, 5);
	l16->GenerateGhostBehaviour(Ghost::Chase, 1037);
	l16->GenerateGhostBehaviour(Ghost::Scatter, 1 / 60);
	l16->GenerateGhostBehaviour(Ghost::Chase, 1);

	l17->GenerateGhostBehaviour(Ghost::Scatter, 5);
	l17->GenerateGhostBehaviour(Ghost::Chase, 20);
	l17->GenerateGhostBehaviour(Ghost::Scatter, 5);
	l17->GenerateGhostBehaviour(Ghost::Chase, 20);
	l17->GenerateGhostBehaviour(Ghost::Scatter, 5);
	l17->GenerateGhostBehaviour(Ghost::Chase, 1037);
	l17->GenerateGhostBehaviour(Ghost::Scatter, 1 / 60);
	l17->GenerateGhostBehaviour(Ghost::Chase, 1);

	l18->GenerateGhostBehaviour(Ghost::Scatter, 5);
	l18->GenerateGhostBehaviour(Ghost::Chase, 20);
	l18->GenerateGhostBehaviour(Ghost::Scatter, 5);
	l18->GenerateGhostBehaviour(Ghost::Chase, 20);
	l18->GenerateGhostBehaviour(Ghost::Scatter, 5);
	l18->GenerateGhostBehaviour(Ghost::Chase, 1037);
	l18->GenerateGhostBehaviour(Ghost::Scatter, 1 / 60);
	l18->GenerateGhostBehaviour(Ghost::Chase, 1);

	l19->GenerateGhostBehaviour(Ghost::Scatter, 5);
	l19->GenerateGhostBehaviour(Ghost::Chase, 20);
	l19->GenerateGhostBehaviour(Ghost::Scatter, 5);
	l19->GenerateGhostBehaviour(Ghost::Chase, 20);
	l19->GenerateGhostBehaviour(Ghost::Scatter, 5);
	l19->GenerateGhostBehaviour(Ghost::Chase, 1037);
	l19->GenerateGhostBehaviour(Ghost::Scatter, 1 / 60);
	l19->GenerateGhostBehaviour(Ghost::Chase, 1);

	l20->GenerateGhostBehaviour(Ghost::Scatter, 5);
	l20->GenerateGhostBehaviour(Ghost::Chase, 20);
	l20->GenerateGhostBehaviour(Ghost::Scatter, 5);
	l20->GenerateGhostBehaviour(Ghost::Chase, 20);
	l20->GenerateGhostBehaviour(Ghost::Scatter, 5);
	l20->GenerateGhostBehaviour(Ghost::Chase, 1037);
	l20->GenerateGhostBehaviour(Ghost::Scatter, 1 / 60);
	l20->GenerateGhostBehaviour(Ghost::Chase, 1);

	l21->GenerateGhostBehaviour(Ghost::Scatter, 5);
	l21->GenerateGhostBehaviour(Ghost::Chase, 20);
	l21->GenerateGhostBehaviour(Ghost::Scatter, 5);
	l21->GenerateGhostBehaviour(Ghost::Chase, 20);
	l21->GenerateGhostBehaviour(Ghost::Scatter, 5);
	l21->GenerateGhostBehaviour(Ghost::Chase, 1037);
	l21->GenerateGhostBehaviour(Ghost::Scatter, 1 / 60);
	l21->GenerateGhostBehaviour(Ghost::Chase, 1);
#pragma endregion
#pragma region Push
	OriginalLevels.push_back(l1);
	OriginalLevels.push_back(l2);
	OriginalLevels.push_back(l3);
	OriginalLevels.push_back(l4);
	OriginalLevels.push_back(l5);
	OriginalLevels.push_back(l6);
	OriginalLevels.push_back(l7);
	OriginalLevels.push_back(l8);
	OriginalLevels.push_back(l9);
	OriginalLevels.push_back(l10);
	OriginalLevels.push_back(l11);
	OriginalLevels.push_back(l12);
	OriginalLevels.push_back(l13);
	OriginalLevels.push_back(l14);
	OriginalLevels.push_back(l15);
	OriginalLevels.push_back(l16);
	OriginalLevels.push_back(l17);
	OriginalLevels.push_back(l18);
	OriginalLevels.push_back(l19);
	OriginalLevels.push_back(l20);
	OriginalLevels.push_back(l21);
#pragma endregion
#pragma region Audio
	AudioManager::Instance().CreateMusic("assets/sounds/music/game_start.ogg", "Start_Game");
	AudioManager::Instance().SetMusicLoopStatus("Start_Game", false);
	AudioManager::Instance().CreateMusic("assets/sounds/effects/Sirens/siren_1.ogg", "Siren");
	AudioManager::Instance().SetMusicLoopStatus("Siren", true);

	AudioManager::Instance().CreateSound("assets/sounds/effects/death.ogg", "Death");
	AudioManager::Instance().CreateSound("assets/sounds/effects/eat_fruit.ogg", "Eat_Fruit");
	AudioManager::Instance().CreateSound("assets/sounds/effects/eat_ghost.ogg", "Eat_Ghost");
	AudioManager::Instance().CreateSound("assets/sounds/effects/power_pellet.ogg", "Power_Pellet");
	AudioManager::Instance().CreateSound("assets/sounds/effects/retreating.ogg", "Retreating");
	AudioManager::Instance().CreateSound("assets/sounds/effects/Munch/munch_1.ogg", "Munch");
#pragma endregion

}

DataBase::~DataBase()
{
	FreeMemory();
}

void DataBase::FreeMemory()
{
	for (int i = 0; i < OriginalLevels.size(); i++)
	{
		delete OriginalLevels[i];
	}
	OriginalLevels.clear();
}

vector<Level*> DataBase::GetOriginalLevels()
{
	return OriginalLevels;
}
