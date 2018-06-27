#pragma once

#include "GameState.h"

class C_ModeSelect : public C_GameState{

public:
	C_ModeSelect(C_GameScene *argGameScene);
	virtual ~C_ModeSelect();
	virtual void Update() override;
	virtual void Draw() override;

private:
	typedef enum{
		Mode_NormalPlay,
		Mode_SelectStage,
		Mode_Exit,

		Mode_Num,
	}e_ModeSelect;

private:
	int nowSelectMode;
	int nowStageNum;
	int numberImage[10];
	int backGroundImage;
	int	normalPlayImage;
	int	selectStageImage;
	int	backImage;

};

