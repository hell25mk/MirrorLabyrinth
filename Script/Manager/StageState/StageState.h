#pragma once

#include "../StageManager.h"
#include "../../Manager/KeyboardManager.h"

class C_StageState{

public:
	C_StageState(C_StageManager *argStageManager){
	
		stageManager = argStageManager;
	
	}
	virtual ~C_StageState(){}
	virtual void Update() = 0;
	virtual void Draw() = 0;

protected:
	C_StageManager *stageManager;

};

