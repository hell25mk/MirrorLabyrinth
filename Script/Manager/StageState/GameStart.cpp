#include "GameStart.h"
#include "DxLib.h"


C_GameStart::C_GameStart(C_StageManager *argStageManager):C_StageState(argStageManager){
}


C_GameStart::~C_GameStart(){
}

void C_GameStart::Update(){

	if(C_KeyboardManager::GetInstance().Input(KEY_INPUT_SPACE) == 1){
		nowGameState = State_GamePlay;
		StageInit();
	}

}

void C_GameStart::Draw(){

	bool drawStageNumFlag = nowStageNum < 10;
	if(drawStageNumFlag){
		DrawRotaGraph(400, 150, 1.2, 0.0, numberImage[nowStageNum], TRUE);
	} else{
		DrawRotaGraph(340, 150, 1.2, 0.0, numberImage[nowStageNum / 10], TRUE);		//2Œ…–Ú
		DrawRotaGraph(420, 150, 1.2, 0.0, numberImage[nowStageNum % 10], TRUE);		//1Œ…–Ú
	}

	DrawGraph(0, 0, floorImage, TRUE);

}