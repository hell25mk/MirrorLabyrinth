#include "GameClear.h"
#include "DxLib.h"
#include "../../System/SoundPlayer.h"

GameClear::GameClear(GameScene *argGameScene):GameState(argGameScene){

	gameClearImage = LoadGraph("Image/Game/GameClear.png");

}


GameClear::~GameClear(){
}

void GameClear::Update(){

	SoundPlayer::GetInstance().StopBGM();

	if(KeyboardManager::GetInstance().Input(KEY_INPUT_SPACE) == 1){
		gameScene->NextScene(Scene_Result);
	}

}

void GameClear::Draw(){

	DrawGraph(0, 0, gameClearImage, TRUE);

}