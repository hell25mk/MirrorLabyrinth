#pragma once

#include "../Base/BaseBlock.h"

class C_Door : public C_BaseBlock{

public:
	C_Door(C_Position<int> argPos);
	virtual ~C_Door();
	virtual void Update() override;
	virtual void Draw() override;
	virtual void HitAction() override;
	void SetMaxKeyNum(int argMaxKeyNum);
	void CheckDoorOpenFlag(int argNowKeyNum);
	bool GetDoorOpenFlag();

private:
	int maxKeyNum;
	bool doorOpenFlag;

};

