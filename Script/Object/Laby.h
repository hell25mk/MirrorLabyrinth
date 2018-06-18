#pragma once

#include "../Define/Enum.h"
#include "../System/Position.h"
#include <vector>
#include <list>

class C_Wall;
class C_Door;
class C_Key;
class C_BreakWall;

class C_Laby{

public:
	C_Laby(int argNowStageNum);
	~C_Laby();
	void Update();
	void Draw();
	bool MoveCheck(int argDire, C_Position argPos);
	e_GameState GetGameState(C_Position argPos);
	void StageCreate(int argNowStageNum);

private:
#pragma region íËêî
	static const int Laby_Height;
	static const int Laby_Width;
#pragma endregion

	C_Position pos;
	std::vector<int> labyVector;

	std::vector<C_Wall> wall;
	C_Door *door;
	std::list<C_Key> keyList;
	int getKeyNum;
	std::list<C_BreakWall> breakWallList;

	e_GameState gameState;
	int *blockMaterialImage;

};

