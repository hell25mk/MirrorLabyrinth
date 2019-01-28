/*****************************************************************************************************
-----ファイル概要-----
GameStateを継承
ゲームの状態の基底クラス
******************************************************************************************************/

#pragma once

#include "GameState.h"

class GameStart : public GameState{

public:
	GameStart(GameScene* argGameScene);
	virtual ~GameStart();
	virtual void Update() override;
	virtual void Draw() override;

private:
	int nowStageNum;
	int numberImage[10];
	int floorImage;

};

