/*****************************************************************************************************
-----�t�@�C���T�v-----
GameState���p��
�Q�[���N���A�̏��
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

