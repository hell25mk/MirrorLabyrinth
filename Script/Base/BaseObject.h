/*****************************************************************************************************
-----ファイル概要-----
オブジェクトの基底クラス
******************************************************************************************************/

#pragma once

#include "DxLib.h"
#include "../System/Position.h"

class BaseObject{

public:
	BaseObject();
	BaseObject(Position<int> argPos);
	virtual ~BaseObject();
	virtual void Update() = 0;
	virtual void Draw() = 0;

protected:
	static const int Block_Size;		//1マスのサイズ

protected:
	Position<int> pos;				//オブジェクトの座標

};

