#include "StageManager.h"
#include "DxLib.h"
#include "KeyboardManager.h"
#include "../Object/Laby.h"
#include "../Object/Player.h"
#include "../Object/Mirror.h"
#include "../UI/Timer.h"
#include "../UI/GameText.h"
#include "../System/Position.h"
#include "../System/SoundPlayer.h"
#include "../Manager/FileManager.h"
#include "StageState/StageState.h"
#include "StageState/StageStateList.h"

const int C_StageManager::Max_Stage_Num = 20;
const int C_StageManager::Laby_Height = 15;
const int C_StageManager::Laby_Width = 20;

C_StageManager::C_StageManager(){

	nowStageNum = 1;

	backGroundImage = LoadGraph("Image/Share/BackGround.png");
	LoadDivGraph("Image/Share/Number.png", 10, 10, 1, 96, 96, numberImage);
	floorImage = LoadGraph("Image/Game/Floor.png");
	stageClearImage = LoadGraph("Image/Game/StageClear.png");
	gameClearImage = LoadGraph("Image/Game/GameClear.png");
	gameOverImage = LoadGraph("Image/Game/GameOver.png");
	normalPlayImage = LoadGraph("Image/Game/ModeSelectNormalPlay.png");
	selectStageImage = LoadGraph("Image/Game/ModeSelectSelectStage.png");
	extraStageImage = LoadGraph("ImageGame//ModeSelectExtraStage.png");
	backImage = LoadGraph("Image/Game/ModeSelecBack.png");
	
#ifdef _DEBUG
	nowStageNum = Max_Stage_Num;
#endif //ステージ確認

	nowGameState = State_ModeSelect;
	nowSelectMode = Mode_NormalPlay;

	nowState = new C_ModeSelect(this);

}


C_StageManager::~C_StageManager(){

	delete nowState;

}

void C_StageManager::Update(){

	nowState->Update();

}

void C_StageManager::Draw(){

	nowState->Draw();

}

void C_StageManager::SetStageNum(){

	

}

int C_StageManager::GetStageNum(){

	return nowStageNum;
}

void C_StageManager::SetStageState(){



}

void C_StageManager::SetGameState(e_GameState argGameState){

	nowGameState = argGameState;

	switch(nowGameState){
		case State_ModeSelect:
			nowState = new C_ModeSelect(this);
			break;
		case State_GameStart:
			nowState = new C_GameStart(this);
			break;
		case State_GamePlay:
			nowState = new C_GamePlay(this);
			break;
		case State_GameClear:
			nowState = new C_GameClear(this);
			break;
		case State_GameOver:
			nowState = new C_GameOver(this);
			break;
	}

}

e_GameState C_StageManager::GetGameState(){

	return nowGameState;
}