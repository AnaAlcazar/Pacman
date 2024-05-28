#include "Debugger.hpp"

void Debugger::Switch(int i)
{
	switches[i] = !switches[i];
}

bool Debugger::GetSwitch(int i)
{
	return switches[i];
}

void Debugger::Input()
{
	if (IsKeyDown(KEY_F1))Switch(0);
	if (IsKeyDown(KEY_F2))Switch(1);
	if (IsKeyDown(KEY_F3))Switch(2);
	if (IsKeyDown(KEY_F4))Switch(3);
	if (IsKeyDown(KEY_F5))
	{
		Switch(4);
		switches[5] = false;
		switches[6] = false;
		switches[7] = false;
		switches[8] = false;
	}
	if (IsKeyDown(KEY_F6))
	{
		Switch(5);
		switches[4] = false;
		switches[6] = false;
		switches[7] = false;
		switches[8] = false;
	}
	if (IsKeyDown(KEY_F7))
	{
		{
			Switch(6);
			switches[4] = false;
			switches[5] = false;
			switches[7] = false;
			switches[8] = false;
		}
	}
	if (IsKeyDown(KEY_F8))
	{
		{
			Switch(7);
			switches[4] = false;
			switches[5] = false;
			switches[6] = false;
			switches[8] = false;
		}
	}
	if (IsKeyDown(KEY_F9))
	{
		{
			Switch(8);
			switches[4] = false;
			switches[5] = false;
			switches[6] = false;
			switches[7] = false;
		}
	}
}

void Debugger::Render()
{
	if (GetSwitch(0))Renderer::Instance().DrawText("GOD MODE ON", 11, { -104, 8 }, WHITE);
	if (GetSwitch(1))
	{
		Renderer::Instance().DrawText("LEVEL", 5, { -104, 32 }, WHITE);
		Renderer::Instance().DrawNumber(GameStateMachine::Instance().game->GetLevel() + 1, Renderer::Instance().AnchorNumberOnRight(GameStateMachine::Instance().game->GetLevel() + 1, { -16, 32 }), WHITE);
		Renderer::Instance().DrawText("DOTS    /244", 12, { -104, 40 }, WHITE);
		Renderer::Instance().DrawNumber(GameStateMachine::Instance().game->GetEatenDots(), Renderer::Instance().AnchorNumberOnRight(GameStateMachine::Instance().game->GetEatenDots(), { -48, 40 }), WHITE);
		Renderer::Instance().DrawText("FRUITS    /2", 12, { -104, 48 }, WHITE);
		Renderer::Instance().DrawNumber(FruitManager::Instance().GetAppearedFruits(), Renderer::Instance().AnchorNumberOnRight(FruitManager::Instance().GetAppearedFruits(), {-32, 48}), WHITE);
	}
	if (GetSwitch(2))
	{
		for (int y = 0; y < 36; y++)
		{
			for (int x = 0; x < 28; x++)
			{
				if (ScreenManager::Instance().IsTangible({(float)x,(float)y}) || ScreenManager::Instance().Empty({ (float)x,(float)y }))continue;
				DrawRectangleLinesEx({ (float)x * 8 * SCALE_FACTOR,(float)y * 8 * SCALE_FACTOR, 8 * SCALE_FACTOR, 8 * SCALE_FACTOR }, 1, GREEN);
			}
		}
		Renderer::Instance().DrawText("COLLIDERS ON", 12, { -104, 16 }, WHITE);
	}
	if (GetSwitch(3))
	{
		switches[3] = false;
		GameStateMachine::Instance().game->FinishLevel();
	}
	if (GetSwitch(4))
	{
		Renderer::Instance().DrawSprite(0, {3,1}, { -64, 96 }, WHITE);
		Renderer::Instance().DrawText("POSITION I  .  I", 16, { -144, 64 }, WHITE);
		DrawRectangle(-72*SCALE_FACTOR, 65*SCALE_FACTOR, 4*SCALE_FACTOR, 8*SCALE_FACTOR, BLACK);
		DrawRectangle(-20 * SCALE_FACTOR, 65 * SCALE_FACTOR, 4 * SCALE_FACTOR, 8 * SCALE_FACTOR, BLACK);
		Renderer::Instance().DrawText("DIRECTION I  .  I", 17, { -152, 72 }, WHITE);
		DrawRectangle(-72 * SCALE_FACTOR, 73 * SCALE_FACTOR, 4 * SCALE_FACTOR, 8 * SCALE_FACTOR, BLACK);
		DrawRectangle(-20 * SCALE_FACTOR, 73 * SCALE_FACTOR, 4 * SCALE_FACTOR, 8 * SCALE_FACTOR, BLACK);
		Renderer::Instance().DrawNumber(EntityManager::Instance().GetEntityAt(0)->GetTileOfEntity().x, Renderer::Instance().AnchorNumberOnRight(EntityManager::Instance().GetEntityAt(0)->GetTileOfEntity().x,{ -56,64 }), WHITE);
		Renderer::Instance().DrawNumber(EntityManager::Instance().GetEntityAt(0)->GetTileOfEntity().y, Renderer::Instance().AnchorNumberOnRight(EntityManager::Instance().GetEntityAt(0)->GetTileOfEntity().y, { -32,64 }), WHITE);
		Renderer::Instance().DrawNumber(EntityManager::Instance().GetEntityAt(0)->GetDirection().x, Renderer::Instance().AnchorNumberOnRight(EntityManager::Instance().GetEntityAt(0)->GetDirection().x, { -64,72 }), WHITE);
		Renderer::Instance().DrawNumber(EntityManager::Instance().GetEntityAt(0)->GetDirection().y, Renderer::Instance().AnchorNumberOnRight(EntityManager::Instance().GetEntityAt(0)->GetDirection().y, { -40,72 }), WHITE);
		Renderer::Instance().DrawText("SPEED", 5, { -88, 80 }, WHITE);
		Renderer::Instance().DrawNumber(EntityManager::Instance().GetEntityAt(0)->GetSpeed()*100, Renderer::Instance().AnchorNumberOnRight(EntityManager::Instance().GetEntityAt(0)->GetSpeed()*100, { -24, 80}), WHITE);
		DrawRectangleLinesEx({ EntityManager::Instance().GetEntityAt(0)->GetTileOfEntity().x *8*SCALE_FACTOR,EntityManager::Instance().GetEntityAt(0)->GetTileOfEntity().y*8*SCALE_FACTOR, 8*SCALE_FACTOR, 8*SCALE_FACTOR}, 2, WHITE);
		DrawLine(((EntityManager::Instance().GetEntityAt(0)->GetTileOfEntity().x * 8) + 4) * SCALE_FACTOR, ((EntityManager::Instance().GetEntityAt(0)->GetTileOfEntity().y * 8) + 4) * SCALE_FACTOR, (((EntityManager::Instance().GetEntityAt(0)->GetTileOfEntity().x + EntityManager::Instance().GetEntityAt(0)->GetDirection().x) * 8) + 4) * SCALE_FACTOR, (((EntityManager::Instance().GetEntityAt(0)->GetTileOfEntity().y + EntityManager::Instance().GetEntityAt(0)->GetDirection().y) * 8) + 4) * SCALE_FACTOR, WHITE);
	}
	if (GetSwitch(5))
	{
		Renderer::Instance().DrawSprite(0, { 3,2 }, { -64, 104 }, WHITE);
		Renderer::Instance().DrawText("POSITION I  .  I", 16, { -144, 64 }, RED);
		DrawRectangle(-72 * SCALE_FACTOR, 65 * SCALE_FACTOR, 4 * SCALE_FACTOR, 8 * SCALE_FACTOR, BLACK);
		DrawRectangle(-20 * SCALE_FACTOR, 65 * SCALE_FACTOR, 4 * SCALE_FACTOR, 8 * SCALE_FACTOR, BLACK);
		Renderer::Instance().DrawText("DIRECTION I  .  I", 17, { -152, 72 }, RED);
		DrawRectangle(-72 * SCALE_FACTOR, 73 * SCALE_FACTOR, 4 * SCALE_FACTOR, 8 * SCALE_FACTOR, BLACK);
		DrawRectangle(-20 * SCALE_FACTOR, 73 * SCALE_FACTOR, 4 * SCALE_FACTOR, 8 * SCALE_FACTOR, BLACK);
		Renderer::Instance().DrawText("TARGET I  .  I", 14, { -128, 88 }, RED);
		DrawRectangle(-72 * SCALE_FACTOR, 89 * SCALE_FACTOR, 4 * SCALE_FACTOR, 8 * SCALE_FACTOR, BLACK);
		DrawRectangle(-20 * SCALE_FACTOR, 89 * SCALE_FACTOR, 4 * SCALE_FACTOR, 8 * SCALE_FACTOR, BLACK);
		Renderer::Instance().DrawNumber(EntityManager::Instance().GetEntityAt(1)->GetTileOfEntity().x, Renderer::Instance().AnchorNumberOnRight(EntityManager::Instance().GetEntityAt(1)->GetTileOfEntity().x, { -56,64 }), RED);
		Renderer::Instance().DrawNumber(EntityManager::Instance().GetEntityAt(1)->GetTileOfEntity().y, Renderer::Instance().AnchorNumberOnRight(EntityManager::Instance().GetEntityAt(1)->GetTileOfEntity().y, { -32,64 }), RED);
		Renderer::Instance().DrawNumber(EntityManager::Instance().GetEntityAt(1)->GetDirection().x, Renderer::Instance().AnchorNumberOnRight(EntityManager::Instance().GetEntityAt(1)->GetDirection().x, { -64,72 }), RED);
		Renderer::Instance().DrawNumber(EntityManager::Instance().GetEntityAt(1)->GetDirection().y, Renderer::Instance().AnchorNumberOnRight(EntityManager::Instance().GetEntityAt(1)->GetDirection().y, { -40,72 }), RED);
		Renderer::Instance().DrawText("SPEED", 5, { -88, 80 }, RED);
		Renderer::Instance().DrawNumber(EntityManager::Instance().GetEntityAt(1)->GetSpeed() * 100, Renderer::Instance().AnchorNumberOnRight(EntityManager::Instance().GetEntityAt(1)->GetSpeed() * 100, { -24, 80 }), RED);
		DrawRectangleLinesEx({ EntityManager::Instance().GetEntityAt(1)->GetTileOfEntity().x * 8 * SCALE_FACTOR,EntityManager::Instance().GetEntityAt(1)->GetTileOfEntity().y * 8 * SCALE_FACTOR, 8 * SCALE_FACTOR, 8 * SCALE_FACTOR }, 2, RED);
		DrawLine(((EntityManager::Instance().GetEntityAt(1)->GetTileOfEntity().x * 8) + 4) * SCALE_FACTOR, ((EntityManager::Instance().GetEntityAt(1)->GetTileOfEntity().y * 8) + 4) * SCALE_FACTOR, (((EntityManager::Instance().GetEntityAt(1)->GetTileOfEntity().x + EntityManager::Instance().GetEntityAt(1)->GetDirection().x) * 8) + 4) * SCALE_FACTOR, (((EntityManager::Instance().GetEntityAt(1)->GetTileOfEntity().y + EntityManager::Instance().GetEntityAt(1)->GetDirection().y) * 8) + 4) * SCALE_FACTOR, RED);
		Renderer::Instance().DrawNumber(dynamic_cast <Ghost*>(EntityManager::Instance().GetEntityAt(1))->GetTargetTile().x, Renderer::Instance().AnchorNumberOnRight(dynamic_cast <Ghost*>(EntityManager::Instance().GetEntityAt(1))->GetTargetTile().x, { -56, 88 }), RED);
		Renderer::Instance().DrawNumber(dynamic_cast <Ghost*>(EntityManager::Instance().GetEntityAt(1))->GetTargetTile().y, Renderer::Instance().AnchorNumberOnRight(dynamic_cast <Ghost*>(EntityManager::Instance().GetEntityAt(1))->GetTargetTile().y, { -32, 88 }), RED);
		DrawRectangleLinesEx({ dynamic_cast <Ghost*>(EntityManager::Instance().GetEntityAt(1))->GetTargetTile().x * 8 * SCALE_FACTOR,dynamic_cast <Ghost*>(EntityManager::Instance().GetEntityAt(1))->GetTargetTile().y * 8 * SCALE_FACTOR, 8 * SCALE_FACTOR, 8 * SCALE_FACTOR }, 2, RED);
	}
	if (GetSwitch(6))
	{
		Renderer::Instance().DrawSprite(0, { 3,3 }, { -64, 104 }, WHITE);
		Renderer::Instance().DrawText("POSITION I  .  I", 16, { -144, 64 }, 2);
		DrawRectangle(-72 * SCALE_FACTOR, 65 * SCALE_FACTOR, 4 * SCALE_FACTOR, 8 * SCALE_FACTOR, BLACK);
		DrawRectangle(-20 * SCALE_FACTOR, 65 * SCALE_FACTOR, 4 * SCALE_FACTOR, 8 * SCALE_FACTOR, BLACK);
		Renderer::Instance().DrawText("DIRECTION I  .  I", 17, { -152, 72 }, 2);
		DrawRectangle(-72 * SCALE_FACTOR, 73 * SCALE_FACTOR, 4 * SCALE_FACTOR, 8 * SCALE_FACTOR, BLACK);
		DrawRectangle(-20 * SCALE_FACTOR, 73 * SCALE_FACTOR, 4 * SCALE_FACTOR, 8 * SCALE_FACTOR, BLACK);
		Renderer::Instance().DrawText("TARGET I  .  I", 14, { -128, 88 }, 2);
		DrawRectangle(-72 * SCALE_FACTOR, 89 * SCALE_FACTOR, 4 * SCALE_FACTOR, 8 * SCALE_FACTOR, BLACK);
		DrawRectangle(-20 * SCALE_FACTOR, 89 * SCALE_FACTOR, 4 * SCALE_FACTOR, 8 * SCALE_FACTOR, BLACK);
		Renderer::Instance().DrawNumber(EntityManager::Instance().GetEntityAt(2)->GetTileOfEntity().x, Renderer::Instance().AnchorNumberOnRight(EntityManager::Instance().GetEntityAt(2)->GetTileOfEntity().x, { -56,64 }), 2);
		Renderer::Instance().DrawNumber(EntityManager::Instance().GetEntityAt(2)->GetTileOfEntity().y, Renderer::Instance().AnchorNumberOnRight(EntityManager::Instance().GetEntityAt(2)->GetTileOfEntity().y, { -32,64 }), 2);
		Renderer::Instance().DrawNumber(EntityManager::Instance().GetEntityAt(2)->GetDirection().x, Renderer::Instance().AnchorNumberOnRight(EntityManager::Instance().GetEntityAt(2)->GetDirection().x, { -64,72 }), 2);
		Renderer::Instance().DrawNumber(EntityManager::Instance().GetEntityAt(2)->GetDirection().y, Renderer::Instance().AnchorNumberOnRight(EntityManager::Instance().GetEntityAt(2)->GetDirection().y, { -40,72 }), 2);
		Renderer::Instance().DrawText("SPEED", 5, { -88, 80 }, 2);
		Renderer::Instance().DrawNumber(EntityManager::Instance().GetEntityAt(2)->GetSpeed() * 100, Renderer::Instance().AnchorNumberOnRight(EntityManager::Instance().GetEntityAt(2)->GetSpeed() * 100, { -24, 80 }), 2);
		DrawRectangleLinesEx({ EntityManager::Instance().GetEntityAt(2)->GetTileOfEntity().x * 8 * SCALE_FACTOR,EntityManager::Instance().GetEntityAt(2)->GetTileOfEntity().y * 8 * SCALE_FACTOR, 8 * SCALE_FACTOR, 8 * SCALE_FACTOR }, 2, Renderer::Instance().GetCustomColor(2));
		DrawLine(((EntityManager::Instance().GetEntityAt(2)->GetTileOfEntity().x * 8) + 4) * SCALE_FACTOR, ((EntityManager::Instance().GetEntityAt(2)->GetTileOfEntity().y * 8) + 4) * SCALE_FACTOR, (((EntityManager::Instance().GetEntityAt(2)->GetTileOfEntity().x + EntityManager::Instance().GetEntityAt(2)->GetDirection().x) * 8) + 4) * SCALE_FACTOR, (((EntityManager::Instance().GetEntityAt(2)->GetTileOfEntity().y + EntityManager::Instance().GetEntityAt(2)->GetDirection().y) * 8) + 4) * SCALE_FACTOR, Renderer::Instance().GetCustomColor(2));
		Renderer::Instance().DrawNumber(dynamic_cast <Ghost*>(EntityManager::Instance().GetEntityAt(2))->GetTargetTile().x, Renderer::Instance().AnchorNumberOnRight(dynamic_cast <Ghost*>(EntityManager::Instance().GetEntityAt(2))->GetTargetTile().x, { -56, 88 }), 2);
		Renderer::Instance().DrawNumber(dynamic_cast <Ghost*>(EntityManager::Instance().GetEntityAt(2))->GetTargetTile().y, Renderer::Instance().AnchorNumberOnRight(dynamic_cast <Ghost*>(EntityManager::Instance().GetEntityAt(2))->GetTargetTile().y, { -32, 88 }), 2);
		DrawRectangleLinesEx({ dynamic_cast <Ghost*>(EntityManager::Instance().GetEntityAt(2))->GetTargetTile().x * 8 * SCALE_FACTOR,dynamic_cast <Ghost*>(EntityManager::Instance().GetEntityAt(2))->GetTargetTile().y * 8 * SCALE_FACTOR, 8 * SCALE_FACTOR, 8 * SCALE_FACTOR }, 2, Renderer::Instance().GetCustomColor(2));
	}
	if (GetSwitch(7))
	{
		Renderer::Instance().DrawSprite(0, { 3,4 }, { -64, 104 }, WHITE);
		Renderer::Instance().DrawText("POSITION I  .  I", 16, { -144, 64 }, 1);
		DrawRectangle(-72 * SCALE_FACTOR, 65 * SCALE_FACTOR, 4 * SCALE_FACTOR, 8 * SCALE_FACTOR, BLACK);
		DrawRectangle(-20 * SCALE_FACTOR, 65 * SCALE_FACTOR, 4 * SCALE_FACTOR, 8 * SCALE_FACTOR, BLACK);
		Renderer::Instance().DrawText("DIRECTION I  .  I", 17, { -152, 72 }, 1);
		DrawRectangle(-72 * SCALE_FACTOR, 73 * SCALE_FACTOR, 4 * SCALE_FACTOR, 8 * SCALE_FACTOR, BLACK);
		DrawRectangle(-20 * SCALE_FACTOR, 73 * SCALE_FACTOR, 4 * SCALE_FACTOR, 8 * SCALE_FACTOR, BLACK);
		Renderer::Instance().DrawText("TARGET I  .  I", 14, { -128, 88 }, 1);
		DrawRectangle(-72 * SCALE_FACTOR, 89 * SCALE_FACTOR, 4 * SCALE_FACTOR, 8 * SCALE_FACTOR, BLACK);
		DrawRectangle(-20 * SCALE_FACTOR, 89 * SCALE_FACTOR, 4 * SCALE_FACTOR, 8 * SCALE_FACTOR, BLACK);
		Renderer::Instance().DrawNumber(EntityManager::Instance().GetEntityAt(3)->GetTileOfEntity().x, Renderer::Instance().AnchorNumberOnRight(EntityManager::Instance().GetEntityAt(3)->GetTileOfEntity().x, { -56,64 }), 1);
		Renderer::Instance().DrawNumber(EntityManager::Instance().GetEntityAt(3)->GetTileOfEntity().y, Renderer::Instance().AnchorNumberOnRight(EntityManager::Instance().GetEntityAt(3)->GetTileOfEntity().y, { -32,64 }), 1);
		Renderer::Instance().DrawNumber(EntityManager::Instance().GetEntityAt(3)->GetDirection().x, Renderer::Instance().AnchorNumberOnRight(EntityManager::Instance().GetEntityAt(3)->GetDirection().x, { -64,72 }), 1);
		Renderer::Instance().DrawNumber(EntityManager::Instance().GetEntityAt(3)->GetDirection().y, Renderer::Instance().AnchorNumberOnRight(EntityManager::Instance().GetEntityAt(3)->GetDirection().y, { -40,72 }), 1);
		Renderer::Instance().DrawText("SPEED", 5, { -88, 80 }, 1);
		Renderer::Instance().DrawNumber(EntityManager::Instance().GetEntityAt(3)->GetSpeed() * 100, Renderer::Instance().AnchorNumberOnRight(EntityManager::Instance().GetEntityAt(3)->GetSpeed() * 100, { -24, 80 }), 1);
		DrawRectangleLinesEx({ EntityManager::Instance().GetEntityAt(3)->GetTileOfEntity().x * 8 * SCALE_FACTOR,EntityManager::Instance().GetEntityAt(3)->GetTileOfEntity().y * 8 * SCALE_FACTOR, 8 * SCALE_FACTOR, 8 * SCALE_FACTOR }, 2, Renderer::Instance().GetCustomColor(1));
		DrawLine(((EntityManager::Instance().GetEntityAt(3)->GetTileOfEntity().x * 8) + 4) * SCALE_FACTOR, ((EntityManager::Instance().GetEntityAt(3)->GetTileOfEntity().y * 8) + 4) * SCALE_FACTOR, (((EntityManager::Instance().GetEntityAt(3)->GetTileOfEntity().x + EntityManager::Instance().GetEntityAt(3)->GetDirection().x) * 8) + 4) * SCALE_FACTOR, (((EntityManager::Instance().GetEntityAt(3)->GetTileOfEntity().y + EntityManager::Instance().GetEntityAt(3)->GetDirection().y) * 8) + 4) * SCALE_FACTOR, Renderer::Instance().GetCustomColor(1));
		Renderer::Instance().DrawNumber(dynamic_cast <Ghost*>(EntityManager::Instance().GetEntityAt(3))->GetTargetTile().x, Renderer::Instance().AnchorNumberOnRight(dynamic_cast <Ghost*>(EntityManager::Instance().GetEntityAt(3))->GetTargetTile().x, { -56, 88 }), 1);
		Renderer::Instance().DrawNumber(dynamic_cast <Ghost*>(EntityManager::Instance().GetEntityAt(3))->GetTargetTile().y, Renderer::Instance().AnchorNumberOnRight(dynamic_cast <Ghost*>(EntityManager::Instance().GetEntityAt(3))->GetTargetTile().y, { -32, 88 }), 1);
		DrawRectangleLinesEx({ dynamic_cast <Ghost*>(EntityManager::Instance().GetEntityAt(3))->GetTargetTile().x * 8 * SCALE_FACTOR,dynamic_cast <Ghost*>(EntityManager::Instance().GetEntityAt(3))->GetTargetTile().y * 8 * SCALE_FACTOR, 8 * SCALE_FACTOR, 8 * SCALE_FACTOR }, 2, Renderer::Instance().GetCustomColor(1));
	}
	if (GetSwitch(8))
	{
		Renderer::Instance().DrawSprite(0, { 3,5 }, { -64, 104 }, WHITE);
		Renderer::Instance().DrawText("POSITION I  .  I", 16, { -144, 64 }, 3);
		DrawRectangle(-72 * SCALE_FACTOR, 65 * SCALE_FACTOR, 4 * SCALE_FACTOR, 8 * SCALE_FACTOR, BLACK);
		DrawRectangle(-20 * SCALE_FACTOR, 65 * SCALE_FACTOR, 4 * SCALE_FACTOR, 8 * SCALE_FACTOR, BLACK);
		Renderer::Instance().DrawText("DIRECTION I  .  I", 17, { -152, 72 }, 3);
		DrawRectangle(-72 * SCALE_FACTOR, 73 * SCALE_FACTOR, 4 * SCALE_FACTOR, 8 * SCALE_FACTOR, BLACK);
		DrawRectangle(-20 * SCALE_FACTOR, 73 * SCALE_FACTOR, 4 * SCALE_FACTOR, 8 * SCALE_FACTOR, BLACK);
		Renderer::Instance().DrawText("TARGET I  .  I", 14, { -128, 88 }, 3);
		DrawRectangle(-72 * SCALE_FACTOR, 89 * SCALE_FACTOR, 4 * SCALE_FACTOR, 8 * SCALE_FACTOR, BLACK);
		DrawRectangle(-20 * SCALE_FACTOR, 89 * SCALE_FACTOR, 4 * SCALE_FACTOR, 8 * SCALE_FACTOR, BLACK);
		Renderer::Instance().DrawNumber(EntityManager::Instance().GetEntityAt(4)->GetTileOfEntity().x, Renderer::Instance().AnchorNumberOnRight(EntityManager::Instance().GetEntityAt(4)->GetTileOfEntity().x, { -56,64 }), 3);
		Renderer::Instance().DrawNumber(EntityManager::Instance().GetEntityAt(4)->GetTileOfEntity().y, Renderer::Instance().AnchorNumberOnRight(EntityManager::Instance().GetEntityAt(4)->GetTileOfEntity().y, { -32,64 }), 3);
		Renderer::Instance().DrawNumber(EntityManager::Instance().GetEntityAt(4)->GetDirection().x, Renderer::Instance().AnchorNumberOnRight(EntityManager::Instance().GetEntityAt(4)->GetDirection().x, { -64,72 }), 3);
		Renderer::Instance().DrawNumber(EntityManager::Instance().GetEntityAt(4)->GetDirection().y, Renderer::Instance().AnchorNumberOnRight(EntityManager::Instance().GetEntityAt(4)->GetDirection().y, { -40,72 }), 3);
		Renderer::Instance().DrawText("SPEED", 5, { -88, 80 }, 3);
		Renderer::Instance().DrawNumber(EntityManager::Instance().GetEntityAt(4)->GetSpeed() * 100, Renderer::Instance().AnchorNumberOnRight(EntityManager::Instance().GetEntityAt(4)->GetSpeed() * 100, { -24, 80 }), 3);
		DrawRectangleLinesEx({ EntityManager::Instance().GetEntityAt(4)->GetTileOfEntity().x * 8 * SCALE_FACTOR,EntityManager::Instance().GetEntityAt(4)->GetTileOfEntity().y * 8 * SCALE_FACTOR, 8 * SCALE_FACTOR, 8 * SCALE_FACTOR }, 2, Renderer::Instance().GetCustomColor(3));
		DrawLine(((EntityManager::Instance().GetEntityAt(4)->GetTileOfEntity().x * 8) + 4) * SCALE_FACTOR, ((EntityManager::Instance().GetEntityAt(4)->GetTileOfEntity().y * 8) + 4) * SCALE_FACTOR, (((EntityManager::Instance().GetEntityAt(4)->GetTileOfEntity().x + EntityManager::Instance().GetEntityAt(4)->GetDirection().x) * 8) + 4) * SCALE_FACTOR, (((EntityManager::Instance().GetEntityAt(4)->GetTileOfEntity().y + EntityManager::Instance().GetEntityAt(4)->GetDirection().y) * 8) + 4) * SCALE_FACTOR, Renderer::Instance().GetCustomColor(3));
		Renderer::Instance().DrawNumber(dynamic_cast <Ghost*>(EntityManager::Instance().GetEntityAt(4))->GetTargetTile().x, Renderer::Instance().AnchorNumberOnRight(dynamic_cast <Ghost*>(EntityManager::Instance().GetEntityAt(4))->GetTargetTile().x, { -56, 88 }), 3);
		Renderer::Instance().DrawNumber(dynamic_cast <Ghost*>(EntityManager::Instance().GetEntityAt(4))->GetTargetTile().y, Renderer::Instance().AnchorNumberOnRight(dynamic_cast <Ghost*>(EntityManager::Instance().GetEntityAt(4))->GetTargetTile().y, { -32, 88 }), 3);
		DrawRectangleLinesEx({ dynamic_cast <Ghost*>(EntityManager::Instance().GetEntityAt(4))->GetTargetTile().x * 8 * SCALE_FACTOR,dynamic_cast <Ghost*>(EntityManager::Instance().GetEntityAt(4))->GetTargetTile().y * 8 * SCALE_FACTOR, 8 * SCALE_FACTOR, 8 * SCALE_FACTOR }, 2, Renderer::Instance().GetCustomColor(3));
	}
}
