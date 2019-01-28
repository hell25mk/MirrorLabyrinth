/*****************************************************************************************************
-----�t�@�C���T�v-----
GameState���p��
�X�e�[�W�I���̏��
******************************************************************************************************/

#pragma once

#include "GameState.h"

class ModeSelect : public GameState{

public:
	ModeSelect(GameScene* argGameScene);
	virtual ~ModeSelect();
	virtual void Update() override;
	virtual void Draw() override;

private:
	typedef enum{
		Mode_Play,
		Mode_Select,
		Mode_Exit,

		Mode_Num,
	}e_ModeSelect;

private:
	int nowSelectMode;
	int nowStageNum;
	int numberImage[10];
	int backGroundImage;
	int* menuImage;

};

