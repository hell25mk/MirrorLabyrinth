#pragma once

#include "../Base/BaseBlock.h"

class C_Stairs : public C_BaseBlock{

public:
	C_Stairs(C_Position<int> argPos);
	virtual ~C_Stairs();
	virtual void Update() override;
	virtual void Draw() override;
	virtual bool HitAction() override;

};

