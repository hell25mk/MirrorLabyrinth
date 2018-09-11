/*****************************************************************************************************
-----ファイル概要-----
GameStateを継承
ステージクリアの状態
******************************************************************************************************/

#pragma once

#include "GameState.h"

class C_StageClear : public C_GameState{

public:
	C_StageClear(C_GameScene *argGameScene);
	virtual ~C_StageClear();
	virtual void Update() override;
	virtual void Draw() override;

private:
	int nowStageNum;
	int numberImage[10];
	int stageClearImage;

};

