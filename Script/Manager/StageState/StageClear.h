#pragma once

#include "StageState.h"

class C_StageClear : public C_StageState{

public:
	C_StageClear(C_StageManager *argStageManager);
	virtual ~C_StageClear();
	virtual void Update() override;
	virtual void Draw() override;

};

