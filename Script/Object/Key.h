/*****************************************************************************************************
-----ファイル概要-----
鍵オブジェクト
全て取得することでドアを開くことができる
******************************************************************************************************/

#pragma once

#include "../Base/BaseBlock.h"

class Key : public BaseBlock{

public:
	Key(Position<int> argPos,int* getKeyNum);
	virtual ~Key();
	virtual void Update() override;
	virtual void Draw() override;
	virtual bool HitAction() override;

private:
	bool getFlag;
	int* getKeyNum;

};

