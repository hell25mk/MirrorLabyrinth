#pragma once

#include "../Base/BaseObject.h"

class C_BreakWall : public C_BaseObject{

public:
	C_BreakWall(C_Position argPos);
	virtual ~C_BreakWall();
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

