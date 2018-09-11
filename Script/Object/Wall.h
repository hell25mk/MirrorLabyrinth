/*****************************************************************************************************
-----ファイル概要-----
壁オブジェクト
通れない
******************************************************************************************************/

#pragma once

#include "../Base/BaseBlock.h"

class C_Wall : public C_BaseBlock{

public:
	C_Wall(C_Position<int> argPos);
	virtual ~C_Wall();
	virtual void Update() override;
	virtual void Draw() override;
	virtual bool HitAction() override;

};

