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
	static const int Laby_Height;
	static const int Laby_Width;
	typedef enum{
		Laby_Road,
		Laby_Wall,
		Laby_Stairs,
		Laby_Door,
		Laby_Key,
		Laby_Block,

		Laby_Nore,
	}e_BlockKind;

private:
	e_GameState gameState;
	C_Position<int> pos;
	std::vector<int> labyVector;
	std::vector<std::shared_ptr<C_BaseBlock>> blockVector;
	int maxKeyNum;
	int getKeyNum;
	
};

