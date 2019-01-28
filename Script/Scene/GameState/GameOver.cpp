#include "GameOver.h"
#include "DxLib.h"
#include "../../System/SoundPlayer.h"

GameOver::GameOver(GameScene *argGameScene):GameState(argGameScene){

	gameOverImage = LoadGraph("Image/Game/GameOver.png");

}


GameOver::~GameOver(){
}

void GameOver::Update(){

	SoundPlayer::GetInstance().StopBGM();

	if(KeyboardManager::GetInstance().Input(KEY_INPUT_SPACE) == 1){
		gameScene->NextScene(Scene_Result);
	}

}

void GameOver::Draw(){

	DrawGraph(0, 0, gameOverImage, TRUE);

}