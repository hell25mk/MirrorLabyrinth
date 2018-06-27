#include "GameClear.h"
#include "DxLib.h"
#include "../../System/SoundPlayer.h"

C_GameClear::C_GameClear(C_GameScene *argGameScene):C_GameState(argGameScene){

	gameClearImage = LoadGraph("Image/Game/GameClear.png");

}


C_GameClear::~C_GameClear(){
}

void C_GameClear::Update(){

	C_SoundPlayer::GetInstance().StopBGM();

	if(C_KeyboardManager::GetInstance().Input(KEY_INPUT_SPACE) == 1){
		gameScene->NextScene(Scene_Result);
	}

}

void C_GameClear::Draw(){

	DrawGraph(0, 0, gameClearImage, TRUE);

}