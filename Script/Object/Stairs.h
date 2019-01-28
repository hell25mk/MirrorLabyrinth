/*****************************************************************************************************
-----ファイル概要-----
階段オブジェクト
辿り着くと次のフロアへ移動できる
次フロアへの移動はLabyで管理
******************************************************************************************************/

#pragma once

#include "../Base/BaseBlock.h"

class Stairs : public BaseBlock{

public:
	Stairs(Position<int> argPos);
	virtual ~Stairs();
	virtual void Update() override;
	virtual void Draw() override;
	virtual bool HitAction() override;

};

