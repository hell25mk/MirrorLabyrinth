#include "ModeSelect.h"
#include "DxLib.h"

C_ModeSelect::C_ModeSelect(C_GameScene *argGameScene):C_GameState(argGameScene){

	nowStageNum = 1;
	LoadDivGraph("Image/Share/Number.png", 10, 10, 1, 96, 96, numberImage);
	backGroundImage = LoadGraph("Image/Share/BackGround.png");
	normalPlayImage = LoadGraph("Image/Game/ModeSelectNormalPlay.png");
	selectStageImage = LoadGraph("Image/Game/ModeSelectSelectStage.png");
	backImage = LoadGraph("Image/Game/ModeSelecBack.png");

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

	if(nowSelectMode == Mode_SelectStage){
		if(C_KeyboardManager::GetInstance().Input(KEY_INPUT_LEFT) == 1){
			nowStageNum--;
		}
		if(C_KeyboardManager::GetInstance().Input(KEY_INPUT_RIGHT) == 1){
			nowStageNum++;
		}
	}

	if(nowStageNum < 1){
		nowStageNum = 1;
	}
	if(nowStageNum > gameScene->Max_Stage_Num){
		nowStageNum = gameScene->Max_Stage_Num;
	}

	if(C_KeyboardManager::GetInstance().Input(KEY_INPUT_SPACE) == 1){
		switch(nowSelectMode){
			case Mode_NormalPlay:
				gameScene->SetStageNum(1);
				gameScene->SetGameState(gameScene->State_GameStart);
				break;
			case Mode_SelectStage:
				gameScene->SetStageNum(nowStageNum);
				gameScene->SetGameState(gameScene->State_GameStart);
				break;
			case Mode_Exit:
				gameScene->NextScene();
				break;
		}
	}

}

void C_ModeSelect::Draw(){

	int normalPlayAlpha(128);
	int selectStageAlpha(128);
	int exitAlpha(128);

	DrawGraph(0, 0, backGroundImage, TRUE);

	switch(nowSelectMode){
		case Mode_NormalPlay:
			normalPlayAlpha = 255;
			break;
		case Mode_SelectStage:
			selectStageAlpha = 255;
			break;
		case Mode_Exit:
			exitAlpha = 255;
			break;
	}

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, normalPlayAlpha);
	DrawGraph(0, 0, normalPlayImage, TRUE);
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, selectStageAlpha);
	DrawGraph(0, 0, selectStageImage, TRUE);
	
	//ÉtÉçÉAêîï\é¶
	if(nowStageNum < 10){
		DrawRotaGraph(450, 230, 0.7, 0.0, numberImage[nowStageNum], TRUE);
	} else{
		DrawRotaGraph(400, 230, 0.7, 0.0, numberImage[nowStageNum / 10], TRUE);		//2åÖñ⁄
		DrawRotaGraph(460, 230, 0.7, 0.0, numberImage[nowStageNum % 10], TRUE);		//1åÖñ⁄
	}

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, exitAlpha);
	DrawGraph(0, 0, backImage, TRUE);


	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

}