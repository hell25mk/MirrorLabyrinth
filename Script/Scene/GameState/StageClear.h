/*****************************************************************************************************
-----ファイル概要-----
GameStateを継承
ステージクリアの状態
******************************************************************************************************/

#pragma once

#include "GameState.h"

class StageClear : public GameState{

public:
	StageClear(GameScene* argGameScene);
	virtual ~StageClear();
	virtual void Update() override;
	virtual void Draw() override;

private:
	int nowStageNum;
	int numberImage[10];
	int stageClearImage;

};

