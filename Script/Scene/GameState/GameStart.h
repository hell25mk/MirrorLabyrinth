#pragma once

#include "GameState.h"

class C_GameStart : public C_GameState{

public:
	C_GameStart(C_GameScene *argGameScene);
	virtual ~C_GameStart();
	virtual void Update() override;
	virtual void Draw() override;

private:
	int nowStageNum;
	int numberImage[10];
	int floorImage;

};

