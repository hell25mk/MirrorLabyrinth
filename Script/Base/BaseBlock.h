#pragma once

#include "BaseObject.h"

class C_BaseBlock : public C_BaseObject{

public:
	C_BaseBlock();
	C_BaseBlock(C_Position<int> argPos);
	virtual ~C_BaseBlock();
	virtual void Update() = 0;
	virtual void Draw() = 0;

protected:
	static const int Image_Width;
	static const int Image_Height;

	static int *image;

};

