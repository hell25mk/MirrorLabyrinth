#include "GameScene.h"
#include "GameState/GameState.h"
#include "GameState/GameStateList.h"
#include "../System/SoundPlayer.h"

const int GameScene::Max_Stage_Num = 25;
const int GameScene::Laby_Height = 15;
const int GameScene::Laby_Width = 20;

/// <summary>
/// コンストラクタ
/// </summary>
/// <param name="argSceneChanger">SceneChangerのポインタ</param>
GameScene::GameScene(SceneChanger* argSceneChanger):BaseScene(argSceneChanger){

	gameState = new ModeSelect(this);
	nowStageNum = 1;

}

/// <summary>
/// デストラクタ
/// </summary>
GameScene::~GameScene(){

	delete gameState;

}

/// <summary>
/// 更新処理を行う
/// </summary>
void GameScene::Update(){

	if(KeyboardManager::GetInstance().Input(KEY_INPUT_ESCAPE) == 1){
		SoundPlayer::GetInstance().StopBGM();
		sceneChanger->SetNextScene(Scene_Title);
	}

	gameState->Update();

}

/// <summary>
/// 描画処理を行う
/// </summary>
void GameScene::Draw(){

	gameState->Draw();

}

/// <summary>
/// ゲームの状態に合わせたクラスを生成する
/// </summary>
/// <param name="argGameState"></param>
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

/// <summary>
/// 次に移動するシーンを更新する
/// </summary>
/// <param name="nextScene">移動先のシーン番号</param>
void GameScene::NextScene(int argNextScene){

	switch(argNextScene){
		case Scene_Title:
			sceneChanger->SetNextScene(Scene_Title);
		break;
		case Scene_Result:
			sceneChanger->SetNextScene(Scene_Result);
			break;
	}

}

/// <summary>
/// 現在のステージ数を更新する
/// </summary>
/// <param name="argStageNum">到達したステージ数</param>
void GameScene::SetStageNum(int argStageNum){

	nowStageNum = argStageNum;

}

/// <summary>
/// 現在のステージ数を取得する
/// </summary>
/// <returns>現在のステージ数</returns>
int GameScene::GetStageNum(){

	return nowStageNum;
}