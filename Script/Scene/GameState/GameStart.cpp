#include "GameStart.h"
#include "DxLib.h"
#include "../../System/SoundPlayer.h"

C_GameStart::C_GameStart(C_GameScene *argGameScene):C_GameState(argGameScene){

	nowStageNum = gameScene->GetStageNum();
	C_SoundPlayer::GetInstance().StopBGM();
	C_SoundPlayer::GetInstance().PlayBGM("Stage");

}


C_GameStart::~C_GameStart(){
}

void C_GameStart::Update(){

	if(C_KeyboardManager::GetInstance().Input(KEY_INPUT_SPACE) == 1){
		gameScene->SetGameState(gameScene->State_GamePlay);
	}

}

void C_GameStart::Draw(){

	/*bool drawStageNumFlag = nowStageNum < 10;
	if(drawStageNumFlag){
		DrawRotaGraph(400, 150, 1.2, 0.0, numberImage[nowStageNum], TRUE);
	} else{
		DrawRotaGraph(340, 150, 1.2, 0.0, numberImage[nowStageNum / 10], TRUE);		//2Œ…–Ú
		DrawRotaGraph(420, 150, 1.2, 0.0, numberImage[nowStageNum % 10], TRUE);		//1Œ…–Ú
	}

	DrawGraph(0, 0, floorImage, TRUE);*/

}