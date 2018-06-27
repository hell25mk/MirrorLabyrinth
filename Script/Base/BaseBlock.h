#pragma once

#include "BaseObject.h"

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

class C_BaseBlock : public C_BaseObject{

public:
	C_BaseBlock();
	C_BaseBlock(C_Position<int> argPos);
	virtual ~C_BaseBlock();
	virtual void Update() = 0;
	virtual void Draw() = 0;
	virtual bool HitAction() = 0;

protected:
	static const int Image_Width;
	static const int Image_Height;

protected:
	bool passFlag;
	static int *image;
	int imageKind;

};

