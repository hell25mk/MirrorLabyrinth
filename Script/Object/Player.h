/*****************************************************************************************************
-----ファイル概要-----
プレイヤーのクラス
******************************************************************************************************/

#pragma once

#include "../Base/BaseCharacter.h"

class Animation;

class Player : public BaseCharacter{

public:
	Player(Position<int> argPos);
	virtual ~Player();
	virtual void Update() override;
	virtual void Draw() override;
	void Move(int argMoveDire);
	void Direction(int argMoveDire);
	Position<int> GetPosition();
	int GetDirection();

private:
	bool moveFlag;
	Animation *animation;

};

