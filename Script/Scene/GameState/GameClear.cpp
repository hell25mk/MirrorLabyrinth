#include "GameClear.h"
#include "DxLib.h"
#include "../../System/SoundPlayer.h"

/// <summary>
/// メンバを初期化する
/// </summary>
/// <param name="argSceneChanger">SceneChangerのポインタ</param>
GameClear::GameClear(GameScene* argGameScene):GameState(argGameScene){

	gameClearImage = LoadGraph("Image/Game/GameClear.png");

}

/// <summary>
/// メモリを確保していた場合は解放する
/// </summary>
GameClear::~GameClear(){
}

/// <summary>
/// 1ループ内で必要な更新処理を行う
/// </summary>
void GameClear::Update(){

	SoundPlayer::GetInstance().StopBGM();

	if(KeyboardManager::GetInstance().Input(KEY_INPUT_SPACE) == 1){
		gameScene->NextScene(Scene_Result);
	}

}

/// <summary>
/// 1ループ内で必要な描画処理を行う
/// </summary>
void GameClear::Draw(){

	DrawGraph(0, 0, gameClearImage, TRUE);

}