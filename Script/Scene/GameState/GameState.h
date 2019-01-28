#pragma once

#include "../../Manager/KeyboardManager.h"
#include "../GameScene.h"

class GameState{

public:
	GameState(GameScene* argGameScene){
	
		gameScene = argGameScene;
	
	}
	virtual ~GameState(){}
	virtual void Update() = 0;
	virtual void Draw() = 0;

protected:
	GameScene* gameScene;

};

