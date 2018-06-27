#pragma once

#include "../Define/Enum.h"
#include "../System/Position.h"
#include <memory>
#include <vector>

class C_BaseBlock;

class C_Laby{

public:
	C_Laby();
	~C_Laby();
	void Update();
	void Draw();
	void PushBlockObject(int argBlockKind, C_Position<int> argPos);
	bool MoveCheck(int argDire, C_Position<int> argPos);
	bool ClearCheck(C_Position<int> argPos);

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

