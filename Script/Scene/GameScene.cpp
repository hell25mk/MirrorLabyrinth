#include "GameScene.h"
#include "GameState/GameState.h"
#include "GameState/GameStateList.h"

const int C_GameScene::Max_Stage_Num = 20;
const int C_GameScene::Laby_Height = 15;
const int C_GameScene::Laby_Width = 20;

C_GameScene::C_GameScene(C_SceneChanger *argSceneChanger) : C_BaseScene(argSceneChanger){

	gameState = new C_ModeSelect(this);
	nowStageNum = 1;
	/*backGroundImage = LoadGraph("Image/Share/BackGround.png");
	LoadDivGraph("Image/Share/Number.png", 10, 10, 1, 96, 96, numberImage);
	floorImage = LoadGraph("Image/Game/Floor.png");
	stageClearImage = LoadGraph("Image/Game/StageClear.png");
	gameClearImage = LoadGraph("Image/Game/GameClear.png");
	gameOverImage = LoadGraph("Image/Game/GameOver.png");
	normalPlayImage = LoadGraph("Image/Game/ModeSelectNormalPlay.png");
	selectStageImage = LoadGraph("Image/Game/ModeSelectSelectStage.png");
	backImage = LoadGraph("Image/Game/ModeSelecBack.png");*/

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

void C_GameScene::NextScene(){

	sceneChanger->SceneChange(Scene_Result);

}

void C_GameScene::SetStageNum(int argStageNum){

	nowStageNum = argStageNum;

}

int C_GameScene::GetStageNum(){

	return nowStageNum;
}