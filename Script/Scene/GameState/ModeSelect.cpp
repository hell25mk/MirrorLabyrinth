#include "ModeSelect.h"
#include "DxLib.h"

C_ModeSelect::C_ModeSelect(C_GameScene *argGameScene):C_GameState(argGameScene){

	nowStageNum = 1;
	LoadDivGraph("Image/Share/Number.png", 10, 10, 1, 96, 96, numberImage);
	backGroundImage = LoadGraph("Image/Share/BackGround.png");

	menuImage = new int[Mode_Num];
	menuImage[Mode_Play] = LoadGraph("Image/Game/ModeSelectNormalPlay.png");
	menuImage[Mode_Select] = LoadGraph("Image/Game/ModeSelectSelectStage.png");
	menuImage[Mode_Exit] = LoadGraph("Image/Game/ModeSelecBack.png");

}

C_ModeSelect::~C_ModeSelect(){
}

void C_ModeSelect::Update(){

	if(C_KeyboardManager::GetInstance().Input(KEY_INPUT_DOWN) == 1){
		nowSelectMode = (nowSelectMode + 1) % Mode_Num;
	}

	if(C_KeyboardManager::GetInstance().Input(KEY_INPUT_UP) == 1){
		nowSelectMode = (nowSelectMode + (Mode_Num - 1)) % Mode_Num;
	}

	if(nowSelectMode == Mode_Select){
		if(C_KeyboardManager::GetInstance().Input(KEY_INPUT_LEFT) == 1){
			nowStageNum--;
		}
		if(C_KeyboardManager::GetInstance().Input(KEY_INPUT_RIGHT) == 1){
			nowStageNum++;
		}
	}

	if(nowStageNum < 1){
		nowStageNum = gameScene->Max_Stage_Num;
	}
	if(nowStageNum > gameScene->Max_Stage_Num){
		nowStageNum = 1;
	}

	if(C_KeyboardManager::GetInstance().Input(KEY_INPUT_SPACE) == 1){
		switch(nowSelectMode){
			case Mode_Play:
				gameScene->SetStageNum(1);
				gameScene->SetGameState(gameScene->State_GameStart);
				break;
			case Mode_Select:
				gameScene->SetStageNum(nowStageNum);
				gameScene->SetGameState(gameScene->State_GameStart);
				break;
			case Mode_Exit:
				gameScene->NextScene(Scene_Title);
				break;
		}
	}

}

void C_ModeSelect::Draw(){

	int drawAlpha[Mode_Num] = { 128,128,128 };

	DrawGraph(0, 0, backGroundImage, TRUE);

	drawAlpha[nowSelectMode] = 255;

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, drawAlpha[Mode_Play]);
	DrawGraph(0, 0, menuImage[Mode_Play], TRUE);
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, drawAlpha[Mode_Select]);
	DrawGraph(0, 0, menuImage[Mode_Select], TRUE);
	
	//�t���A���\��
	if(nowStageNum < 10){
		DrawRotaGraph(450, 230, 0.7, 0.0, numberImage[nowStageNum], TRUE);
	} else{
		DrawRotaGraph(400, 230, 0.7, 0.0, numberImage[nowStageNum / 10], TRUE);		//2����
		DrawRotaGraph(460, 230, 0.7, 0.0, numberImage[nowStageNum % 10], TRUE);		//1����
	}

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, drawAlpha[Mode_Exit]);
	DrawGraph(0, 0, menuImage[Mode_Exit], TRUE);


	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

}