#pragma once

#include "../Base/BaseBlock.h"

class C_Key : public C_BaseBlock{

public:
	C_Key(C_Position<int> argPos);
	virtual ~C_Key();
	virtual void Update() override;
	virtual void Draw() override;
	virtual void HitAction() override;
	bool KeyPosCheck(C_Position<int> argPos);

};

