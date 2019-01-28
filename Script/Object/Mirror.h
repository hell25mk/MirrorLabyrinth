/*****************************************************************************************************
-----ファイル概要-----
プレイヤーの投影
プレイヤーと逆側の迷路に配置される
左右は一致
映ったり映らなかったりする
******************************************************************************************************/

#pragma once

#include "../Base/BaseCharacter.h"

class Player;

class Mirror : public BaseCharacter{

public:
	Mirror(Player *player);
	virtual ~Mirror();
	virtual void Update() override;
	virtual void Draw() override;
	void Move();
	void Direction();
	void Fhashing();

private:
	Player *player;
	int flashTime;
	bool flashFlag;

};