#pragma once

#include "StageState.h"

class C_GameClear : public C_StageState{

public:
	C_GameClear(C_StageManager *argStageManager);
	virtual ~C_GameClear();
	virtual void Update() override;
	virtual void Draw() override;

};

