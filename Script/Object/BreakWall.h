#pragma once

#include "../Base/BaseBlock.h"

class C_BreakWall : public C_BaseBlock{

public:
	C_BreakWall(C_Position argPos);
	virtual ~C_BreakWall();
	virtual void Update() override;
	virtual void Draw() override;
	bool BWallPosCheck(C_Position argPos);
	void SetWallDamage();
	bool GetBreakFlag();

private:
	const int BreakWall_Image = 10;

	int blockSize;
	int *blockMaterialImage;
	int mirrorPosy;
	int nowWallDamage;
	bool breakFlag;

};

