#pragma once

#include "../Base/BaseBlock.h"

class C_Key : public C_BaseBlock{

public:
	C_Key(C_Position argPos);
	virtual ~C_Key();
	virtual void Update() override;
	virtual void Draw() override;
	bool KeyPosCheck(C_Position argPos);

private:
	typedef enum{
		Key_Ruby = 7,
		Key_Diamond,
	}e_KeyKind;

	int keyImageKind;

};

