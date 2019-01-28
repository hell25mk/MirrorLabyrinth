/*****************************************************************************************************
-----ファイル概要-----
迷路オブジェクト
正直これのせいで分かりにくくなっている部分があったりなかったりする
******************************************************************************************************/

#pragma once

#include "../System/Position.h"
#include <memory>
#include <vector>

class BaseBlock;
class Player;
class Mirror;

class Laby{

public:
	Laby();
	~Laby();
	void Update();
	void Draw();
	void PushBlockObject(int argBlockKind, Position<int> argPos);
	bool MoveCheck(int argDire, Position<int> argPos);
	bool ClearCheck(Position<int> argPos);

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
	Position<int> pos;
	std::vector<int> labyVector;
	std::vector<std::shared_ptr<BaseBlock>> blockVector;
	/*Player *player;
	Mirror *mirror;*/
	int maxKeyNum;
	int getKeyNum;
	
};

