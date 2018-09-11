/*****************************************************************************************************
-----ファイル概要-----
ブロックオブジェクト
基本は通ることができない
ある条件を満たすと通ることができる
******************************************************************************************************/

#pragma once

#include "../Base/BaseBlock.h"

class C_Block : public C_BaseBlock{

public:
	C_Block(C_Position<int> argPos);
	virtual ~C_Block();
	virtual void Update() override;
	virtual void Draw() override;
	virtual bool HitAction() override;

private:
	int damage;

};

