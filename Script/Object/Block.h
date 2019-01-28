/*****************************************************************************************************
-----ファイル概要-----
ブロックオブジェクト
基本は通ることができない
ある条件を満たすと通ることができる
******************************************************************************************************/

#pragma once

#include "../Base/BaseBlock.h"

class Block : public BaseBlock{

public:
	Block(Position<int> argPos);
	virtual ~Block();
	virtual void Update() override;
	virtual void Draw() override;
	virtual bool HitAction() override;

private:
	int damage;

};

