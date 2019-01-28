/*****************************************************************************************************
-----�t�@�C���T�v-----
GameState���p��
�Q�[���̏�Ԃ̊��N���X
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

