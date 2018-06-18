#pragma once

#include "../Base/BaseObject.h"

class C_Key : public C_BaseObject{

public:
	C_Key(C_Position argPos);
	virtual ~C_Key();
	virtual void Draw() override;
	bool KeyPosCheck(C_Position argPos);

private:
	typedef enum{
		Key_Ruby = 7,
		Key_Diamond,
	}e_KeyKind;

	int blockSize;
	int *blockMaterialImage;
	int keyImageKind;

};

