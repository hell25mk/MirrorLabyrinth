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

	stageManager->Update();
	gameState = stageManager->GetGameState();

}

void C_GameScene::Draw(){

	stageManager->Draw();

}