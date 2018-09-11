/*****************************************************************************************************
-----ファイル概要-----
プレイヤーの投影
プレイヤーと逆側の迷路に配置される
左右は一致
映ったり映らなかったりする
******************************************************************************************************/

#pragma once

#include "../Base/BaseCharacter.h"

class C_Player;

class C_Mirror : public C_BaseCharacter{

public:
	C_Mirror(C_Player *player);
	virtual ~C_Mirror();
	virtual void Update() override;
	virtual void Draw() override;
	void Move();
	void Direction();
	void Fhashing();

private:
	C_Player *player;
	int flashTime;
	bool flashFlag;

};