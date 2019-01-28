#include "GameStart.h"
#include "DxLib.h"
#include "../../System/SoundPlayer.h"

GameStart::GameStart(GameScene *argGameScene):GameState(argGameScene){

	nowStageNum = gameScene->GetStageNum();
	SoundPlayer::GetInstance().PlayBGM("Stage");

	LoadDivGraph("Image/Share/Number.png", 10, 10, 1, 96, 96, numberImage);
	floorImage = LoadGraph("Image/Game/Floor.png");

}

GameStart::~GameStart(){
}

void GameStart::Update(){

	if(KeyboardManager::GetInstance().Input(KEY_INPUT_SPACE) == 1){
		gameScene->SetGameState(gameScene->State_GamePlay);
	}

}

void GameStart::Draw(){

	bool drawStageNumFlag = nowStageNum < 10;
	if(drawStageNumFlag){
		DrawRotaGraph(400, 150, 1.2, 0.0, numberImage[nowStageNum], TRUE);
	} else{
		DrawRotaGraph(340, 150, 1.2, 0.0, numberImage[nowStageNum / 10], TRUE);		//2Œ…–Ú
		DrawRotaGraph(420, 150, 1.2, 0.0, numberImage[nowStageNum % 10], TRUE);		//1Œ…–Ú
	}

	DrawGraph(0, 0, floorImage, TRUE);

}