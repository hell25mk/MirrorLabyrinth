#pragma once

#include "../Base/BaseBlock.h"

class C_Door : public C_BaseBlock{

public:
	C_Door(C_Position argPos);
	virtual ~C_Door();
	virtual void Update() override;
	virtual void Draw() override;
	void SetMaxKeyNum(int argMaxKeyNum);
	void CheckDoorOpenFlag(int argNowKeyNum);
	bool GetDoorOpenFlag();

private:
	typedef enum{
		Door_Close = 5,
		Door_Open,
	}e_DoorKind;

	int blockSize;
	int *blockMaterialImage;

	int maxKeyNum;

	bool doorOpenFlag;

};

