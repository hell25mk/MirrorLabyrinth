#pragma once

#include "../../Manager/KeyboardManager.h"
#include "../GameScene.h"

class C_GameState{

public:
	C_GameState(C_GameScene *argGameScene){
	
		gameScene = argGameScene;
	
	}
	virtual ~C_GameState(){}
	virtual void Update() = 0;
	virtual void Draw() = 0;

protected:
	C_GameScene *gameScene;

};

