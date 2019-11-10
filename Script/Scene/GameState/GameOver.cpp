#include "GameOver.h"
#include "DxLib.h"
#include "../../System/SoundPlayer.h"

/// <summary>
/// メンバを初期化する
/// </summary>
/// <param name="argSceneChanger">SceneChangerのポインタ</param>
GameOver::GameOver(GameScene* argGameScene):GameState(argGameScene){

	gameOverImage = LoadGraph("Image/Game/GameOver.png");

}

/// <summary>
/// メモリを確保していた場合は解放する
/// </summary>
GameOver::~GameOver(){
}

/// <summary>
/// 1ループ内で必要な更新処理を行う
/// </summary>
void GameOver::Update(){

	SoundPlayer::GetInstance().StopBGM();

	if(KeyboardManager::GetInstance().Input(KEY_INPUT_SPACE) == 1){
		gameScene->NextScene(Scene_Result);
	}

}

/// <summary>
/// 1ループ内で必要な更新処理を行う
/// </summary>
void GameOver::Draw(){

	DrawGraph(0, 0, gameOverImage, TRUE);

}