/*****************************************************************************************************
-----ファイル概要-----
ドアオブジェクト
鍵を全て取得しないと通ることができない
******************************************************************************************************/

#pragma once

#include "../Base/BaseBlock.h"

class Door : public BaseBlock{

public:
	Door(Position<int> argPos, const int* maxKeyNum, int* getKeyNum);
	virtual ~Door();
	virtual void Update() override;
	virtual void Draw() override;
	virtual bool HitAction() override;

private:
	const int *maxKeyNum;
	int* getKeyNum;

};

