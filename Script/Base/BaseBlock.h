/*****************************************************************************************************
-----ファイル概要-----
BaseObjectを継承
各ブロックの基底クラス
******************************************************************************************************/

#pragma once

#include "BaseObject.h"

namespace{
	typedef enum{
		Laby_Road,
		Laby_Wall,
		Laby_Stairs,
		Laby_Nore1,
		Laby_Nore2,
		Laby_CloseDoor,
		Laby_OpenDoor,
		Laby_RubyKey,
		Laby_DiaKey,
		Laby_Nore3,
		Laby_Block1,
		Laby_Block2,
		Laby_Block3,
		Laby_Block4,
		Laby_Nore4,
	}e_BlockImageKind;
}

class BaseBlock : public BaseObject{

public:
	BaseBlock();
	BaseBlock(Position<int> argPos);
	virtual ~BaseBlock();
	virtual void Update() = 0;
	virtual void Draw() = 0;
	virtual bool HitAction() = 0;

protected:
	static const int Image_Width;
	static const int Image_Height;

protected:
	bool passFlag;					//通れるかどうか
	static int* image;				//画像ポインタ
	int imageKind;					//画像の種類

};

