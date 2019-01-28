#include "GameScene.h"
#include "GameState/GameState.h"
#include "GameState/GameStateList.h"
#include "../System/SoundPlayer.h"

const int GameScene::Max_Stage_Num = 25;
const int GameScene::Laby_Height = 15;
const int GameScene::Laby_Width = 20;

GameScene::GameScene(SceneChanger *argSceneChanger):BaseScene(argSceneChanger){

	gameState = new ModeSelect(this);
	nowStageNum = 1;

}

GameScene::~GameScene(){

	delete gameState;

}

void GameScene::Update(){

	if(KeyboardManager::GetInstance().Input(KEY_INPUT_ESCAPE) == 1){
		SoundPlayer::GetInstance().StopBGM();
		sceneChanger->SceneChange(Scene_Title);
	}

	gameState->Update();

}

void GameScene::Draw(){

	gameState->Draw();

}

void GameScene::SetGameState(int argGameState){

	switch(argGameState){
		case State_ModeSelect:
			gameState = new ModeSelect(this);
			break;
		case State_GameStart:
			gameState = new GameStart(this);
			break;
		case State_GamePlay:
			gameState = new GamePlay(this);
			break;
		case State_StageClear:
			gameState = new StageClear(this);
			break;
		case State_GameClear:
			gameState = new GameClear(this);
			break;
		case State_GameOver:
			gameState = new GameOver(this);
			break;
	}

}

void GameScene::NextScene(int argNextScene){

	switch(argNextScene){
		case Scene_Title:
			sceneChanger->SceneChange(Scene_Title);
		break;
		case Scene_Result:
			sceneChanger->SceneChange(Scene_Result);
			break;
	}

}

void GameScene::SetStageNum(int argStageNum){

	nowStageNum = argStageNum;

}

int GameScene::GetStageNum(){

	return nowStageNum;
}