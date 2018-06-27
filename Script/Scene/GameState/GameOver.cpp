#include "GameOver.h"
#include "DxLib.h"
#include "../../System/SoundPlayer.h"

C_GameOver::C_GameOver(C_GameScene *argGameScene):C_GameState(argGameScene){

	gameOverImage = LoadGraph("Image/Game/GameOver.png");

}


C_GameOver::~C_GameOver(){
}

void C_GameOver::Update(){

	C_SoundPlayer::GetInstance().StopBGM();

	if(C_KeyboardManager::GetInstance().Input(KEY_INPUT_SPACE) == 1){
		gameScene->NextScene(Scene_Result);
	}

}

void C_GameOver::Draw(){

	DrawGraph(0, 0, gameOverImage, TRUE);

}