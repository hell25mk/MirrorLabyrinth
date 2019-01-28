#include "StageClear.h"
#include "DxLib.h"

StageClear::StageClear(GameScene *argGameScene):GameState(argGameScene){

	nowStageNum = gameScene->GetStageNum();
	LoadDivGraph("Image/Share/Number.png", 10, 10, 1, 96, 96, numberImage);
	stageClearImage = LoadGraph("Image/Game/StageClear.png");

}

StageClear::~StageClear(){
}

void StageClear::Update(){

	if(KeyboardManager::GetInstance().Input(KEY_INPUT_SPACE) == 1){
		int nextStageNum = nowStageNum + 1;
		bool stageCheckFlag = nextStageNum > gameScene->Max_Stage_Num;

		if(!stageCheckFlag){
			gameScene->SetStageNum(nextStageNum);
			gameScene->SetGameState(gameScene->State_GameStart);
			return;
		}

		gameScene->SetGameState(gameScene->State_GameClear);
	}

}

void StageClear::Draw(){

	bool drawStageNumFlag = nowStageNum < 10;
	if(drawStageNumFlag){
		DrawRotaGraph(400, 150, 1.2, 0.0, numberImage[nowStageNum], TRUE);
	} else{
		DrawRotaGraph(340, 150, 1.2, 0.0, numberImage[nowStageNum / 10], TRUE);		//2Œ…–Ú
		DrawRotaGraph(420, 150, 1.2, 0.0, numberImage[nowStageNum % 10], TRUE);		//1Œ…–Ú
	}

	DrawGraph(0, 0, stageClearImage, TRUE);
	
}