#pragma once

#include "../Base/BaseBlock.h"

class C_Key : public C_BaseBlock{

public:
	C_Key(C_Position<int> argPos,int *getKeyNum);
	virtual ~C_Key();
	virtual void Update() override;
	virtual void Draw() override;
	virtual bool HitAction() override;

private:
	bool getFlag;
	int *getKeyNum;

};

