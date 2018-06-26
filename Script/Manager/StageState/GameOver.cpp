#include "GameOver.h"
#include "DxLib.h"


C_GameOver::C_GameOver(C_StageManager *argStageManager):C_StageState(argStageManager){
}


C_GameOver::~C_GameOver(){
}

void C_GameOver::Update(){

	C_SoundPlayer::GetInstance().StopBGM();

	if(C_KeyboardManager::GetInstance().Input(KEY_INPUT_SPACE) == 1){
		nowGameState = State_Result;
	}

}

void C_GameOver::Draw(){

	DrawGraph(0, 0, gameOverImage, TRUE);

}