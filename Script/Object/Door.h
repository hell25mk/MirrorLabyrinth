#pragma once

#include "../Base/BaseObject.h"

class C_Door : public C_BaseObject{

public:
	C_Door(C_Position argPos);
	virtual ~C_Door();
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

