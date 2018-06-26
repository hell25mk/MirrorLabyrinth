#include "GameClear.h"
#include "DxLib.h"


C_GameClear::C_GameClear(C_StageManager *argStageManager):C_StageState(argStageManager){
}


C_GameClear::~C_GameClear(){
}

void C_GameClear::Update(){

	C_SoundPlayer::GetInstance().StopBGM();

	if(C_KeyboardManager::GetInstance().Input(KEY_INPUT_SPACE) == 1){
		nowGameState = State_Result;
	}

}

void C_GameClear::Draw(){

	DrawGraph(0, 0, gameClearImage, TRUE);

}