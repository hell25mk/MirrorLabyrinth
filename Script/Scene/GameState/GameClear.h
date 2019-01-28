/*****************************************************************************************************
-----ファイル概要-----
GameStateを継承
ゲームクリアの状態
******************************************************************************************************/

#pragma once

#include "GameState.h"

class GameClear : public GameState{

public:
	GameClear(GameScene* argGameScene);
	virtual ~GameClear();
	virtual void Update() override;
	virtual void Draw() override;

private:
	int gameClearImage;

};

