#pragma once

#include "../Define/Enum.h"
#include "../System/Position.h"
#include <memory>
#include <vector>
#include <list>

class C_BaseBlock;
class C_Wall;
class C_Door;
class C_Key;
class C_Block;

class C_Laby{

public:
	C_Laby(int argNowStageNum);
	~C_Laby();
	void Update();
	void Draw();
	bool MoveCheck(int argDire, C_Position<int> argPos);
	e_GameState GetGameState(C_Position<int> argPos);
	void StageCreate(int argNowStageNum);

private:
#pragma region íËêî
	static const int Laby_Height;
	static const int Laby_Width;
#pragma endregion

	C_Position<int> pos;
	std::vector<int> labyVector;
	std::vector<std::shared_ptr<C_BaseBlock>> blockVector;

	std::vector<C_Wall> wall;
	C_Door *door;
	std::list<C_Key*> keyList;
	int getKeyNum;
	std::list<C_Block*> breakWallList;

	e_GameState gameState;
	int *blockMaterialImage;

};

