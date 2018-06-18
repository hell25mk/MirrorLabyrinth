#pragma once

#include "StageState.h"

class C_GamePlay : public C_StageState{

public:
	C_GamePlay(C_StageManager *argStageManager);
	virtual ~C_GamePlay();
	virtual void Update() override;
	virtual void Draw() override;

};

