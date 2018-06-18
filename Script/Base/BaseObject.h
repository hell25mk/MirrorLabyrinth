#pragma once

#include "DxLib.h"
#include "../System/Position.h"

class C_BaseObject{

public:
	C_BaseObject();
	C_BaseObject(C_Position argPos);
	virtual ~C_BaseObject();
	virtual void Draw() = 0;

protected:
	static const int Block_Size;
	static const int BlockImage_X_Num;
	static const int BlockImage_Y_Num;

	int *image;
	C_Position pos;

};

