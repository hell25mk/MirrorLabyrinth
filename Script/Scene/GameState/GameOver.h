#pragma once

#include "GameState.h"

class C_GameOver : public C_GameState{

public:
	C_GameOver(C_GameScene *argGameScene);
	virtual ~C_GameOver();
	virtual void Update() override;
	virtual void Draw() override;

};

