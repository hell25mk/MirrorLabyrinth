/*****************************************************************************************************
-----�t�@�C���T�v-----
GameState���p��
�X�e�[�W�N���A�̏��
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

