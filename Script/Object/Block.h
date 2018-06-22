#pragma once

#include "../Base/BaseBlock.h"

class C_Block : public C_BaseBlock{

public:
	C_Block(C_Position<int> argPos);
	virtual ~C_Block();
	virtual void Update() override;
	virtual void Draw() override;
	bool BlockPosCheck(C_Position<int> argPos);
	void SetWallDamage();
	bool GetBreakFlag();

private:
	const int Block_Image = 10;
	int mirrorPosy;
	int nowWallDamage;
	bool breakFlag;

};

