/*****************************************************************************************************
-----ファイル概要-----
道オブジェクト
通れる
******************************************************************************************************/

#pragma once

#include "../Base/BaseBlock.h"

class Road : public BaseBlock{

public:
	Road(Position<int> argPos);
	~Road();
	virtual void Update() override;
	virtual void Draw() override;
	virtual bool HitAction() override;

};

