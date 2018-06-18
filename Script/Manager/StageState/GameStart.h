#pragma once

#include "StageState.h"

class C_GameStart : public C_StageState{

public:
	C_GameStart(C_StageManager *argStageManager);
	virtual ~C_GameStart();
	virtual void Update() override;
	virtual void Draw() override;

};

