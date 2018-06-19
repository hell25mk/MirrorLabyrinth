#pragma once

#include "BaseObject.h"

class C_BaseBlock : public C_BaseObject{

public:
	C_BaseBlock(C_Position argPos);
	virtual ~C_BaseBlock();
	virtual void Update() = 0;
	virtual void Draw() = 0;

protected:
	static const int Image_X_Num;
	static const int Image_Y_Num;

	static int *image;

};

