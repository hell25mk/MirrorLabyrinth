/*****************************************************************************************************
-----ファイル概要-----
ドアオブジェクト
鍵を全て取得しないと通ることができない
******************************************************************************************************/

#pragma once

#include "../Base/BaseBlock.h"

class C_Door : public C_BaseBlock{

public:
	C_Door(C_Position<int> argPos, const int *maxKeyNum, int *getKeyNum);
	virtual ~C_Door();
	virtual void Update() override;
	virtual void Draw() override;
	virtual bool HitAction() override;

private:
	const int *maxKeyNum;
	int *getKeyNum;

};

