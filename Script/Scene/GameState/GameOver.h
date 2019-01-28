/*****************************************************************************************************
-----ファイル概要-----
GameStateを継承
ゲームオーバーの状態
******************************************************************************************************/

#pragma once

#include "GameState.h"

class GameOver : public GameState{

public:
	GameOver(GameScene *argGameScene);
	virtual ~GameOver();
	virtual void Update() override;
	virtual void Draw() override;

private:
	int gameOverImage;

};

