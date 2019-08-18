#include "GameOver.h"
#include "DxLib.h"
#include "../../System/SoundPlayer.h"

/// <summary>
/// �R���X�g���N�^
/// </summary>
/// <param name="argSceneChanger">SceneChanger�̃|�C���^</param>
GameOver::GameOver(GameScene* argGameScene):GameState(argGameScene){

	gameOverImage = LoadGraph("Image/Game/GameOver.png");

}

/// <summary>
/// �f�X�g���N�^
/// </summary>
GameOver::~GameOver(){
}

/// <summary>
/// �X�V�������s��
/// </summary>
void GameOver::Update(){

	SoundPlayer::GetInstance().StopBGM();

	if(KeyboardManager::GetInstance().Input(KEY_INPUT_SPACE) == 1){
		gameScene->NextScene(Scene_Result);
	}

}

/// <summary>
/// �X�V�������s��
/// </summary>
void GameOver::Draw(){

	DrawGraph(0, 0, gameOverImage, TRUE);

}