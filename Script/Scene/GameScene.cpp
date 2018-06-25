#include "GameScene.h"

C_GameScene::C_GameScene(C_SceneChanger *argSceneChanger) : C_BaseScene(argSceneChanger){

	stageManager = new C_StageManager();
	gameState = stageManager->GetGameState();

}


C_GameScene::~C_GameScene(){

	delete stageManager;

}

void C_GameScene::Update(){

	if(C_KeyboardManager::GetInstance().Input(KEY_INPUT_ESCAPE) == 1){
		sceneChanger->SceneChange(Scene_Title);
	}

	switch(gameState){
		case State_ModeSelect:
			stageManager->ModeSelectUpdate();
			break;
		case State_GameStart:
			stageManager->GameStartUpdate();
			break;
		case State_GamePlay:
			stageManager->GamePlayUpdate();
			break;
		case State_StageClear:
			stageManager->StageClearUpdate();
			break;
		case State_GameClear:
			stageManager->GameClearUpdate();
			break;
		case State_GameOver:
			stageManager->GameOverUpdate();
			break;
		case State_Result:
			sceneChanger->SceneChange(Scene_Result);
			break;
		case State_Nore:
			sceneChanger->SceneChange(Scene_Title);
			break;
	}

	gameState = stageManager->GetGameState();

}

void C_GameScene::Draw(){

	switch(gameState){
		case State_ModeSelect:
			stageManager->ModeSelectDraw();
			break;
		case State_GameStart:
			stageManager->GameStartDraw();
			break;
		case State_GamePlay:
			stageManager->GamePlayDraw();
			break;
		case State_StageClear:
			stageManager->StageClearDraw();
			break;
		case State_GameClear:
			stageManager->GameClearDraw();
			break;
		case State_GameOver:
			stageManager->GameOverDraw();
			break;
		case State_Nore:
			break;
	}

}