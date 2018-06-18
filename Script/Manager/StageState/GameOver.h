#pragma once

#include "StageState.h"

class C_GameOver : public C_StageState{

public:
	C_GameOver(C_StageManager *argStageManager);
	virtual ~C_GameOver();
	virtual void Update() override;
	virtual void Draw() override;

};

