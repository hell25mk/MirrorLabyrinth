#pragma once

#include "GameState.h"

class C_GameClear : public C_GameState{

public:
	C_GameClear(C_GameScene *argGameScene);
	virtual ~C_GameClear();
	virtual void Update() override;
	virtual void Draw() override;

};

