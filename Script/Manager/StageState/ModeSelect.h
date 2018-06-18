#pragma once

#include "StageState.h"

class C_ModeSelect : public C_StageState{

public:
	C_ModeSelect(C_StageManager *argStageManager);
	virtual ~C_ModeSelect();
	virtual void Update() override;
	virtual void Draw() override;

};

