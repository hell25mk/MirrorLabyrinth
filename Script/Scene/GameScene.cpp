#include "GameScene.h"
#include "GameState/GameState.h"
#include "GameState/GameStateList.h"

const int C_GameScene::Max_Stage_Num = 25;
const int C_GameScene::Laby_Height = 15;
const int C_GameScene::Laby_Width = 20;

C_GameScene::C_GameScene(C_SceneChanger *argSceneChanger) : C_BaseScene(argSceneChanger){

	gameState = new C_ModeSelect(this);
	nowStageNum = 1;

}

C_GameScene::~C_GameScene(){

	delete gameState;

}

void C_GameScene::Update(){

	if(C_KeyboardManager::GetInstance().Input(KEY_INPUT_ESCAPE) == 1){
		sceneChanger->SceneChange(Scene_Title);
	}

	gameState->Update();

}

void C_GameScene::Draw(){

	gameState->Draw();

}

void C_GameScene::SetGameState(int argGameState){

	switch(argGameState){
		case State_ModeSelect:
			gameState = new C_ModeSelect(this);
			break;
		case State_GameStart:
			gameState = new C_GameStart(this);
			break;
		case State_GamePlay:
			gameState = new C_GamePlay(this);
			break;
		case State_StageClear:
			gameState = new C_StageClear(this);
			break;
		case State_GameClear:
			gameState = new C_GameClear(this);
			break;
		case State_GameOver:
			gameState = new C_GameOver(this);
			break;
	}

}

void C_GameScene::NextScene(int argNextScene){

	switch(argNextScene){
		case Scene_Title:
			sceneChanger->SceneChange(Scene_Title);
		break;
		case Scene_Result:
			sceneChanger->SceneChange(Scene_Result);
			break;
	}

}

void C_GameScene::SetStageNum(int argStageNum){

	nowStageNum = argStageNum;

}

int C_GameScene::GetStageNum(){

	return nowStageNum;
}