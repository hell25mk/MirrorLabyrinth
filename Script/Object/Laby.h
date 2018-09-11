/*****************************************************************************************************
-----ファイル概要-----
迷路オブジェクト
正直これのせいで分かりにくくなっている部分があったりなかったりする
******************************************************************************************************/

#pragma once

#include "../System/Position.h"
#include <memory>
#include <vector>

class C_BaseBlock;
class C_Player;
class C_Mirror;

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
		Laby_Player,
		Laby_Wall,
		Laby_Road,
		Laby_Stairs,
		Laby_Door,
		Laby_Key,
		Laby_Block,

		Laby_Nore,
	}e_ObjectKind;

private:
	C_Position<int> pos;
	std::vector<int> labyVector;
	std::vector<std::shared_ptr<C_BaseBlock>> blockVector;
	/*C_Player *player;
	C_Mirror *mirror;*/
	int maxKeyNum;
	int getKeyNum;
	
};

