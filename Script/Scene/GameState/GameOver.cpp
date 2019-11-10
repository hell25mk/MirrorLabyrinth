#include "GameOver.h"
#include "DxLib.h"
#include "../../System/SoundPlayer.h"

/// <summary>
/// �����o������������
/// </summary>
/// <param name="argSceneChanger">SceneChanger�̃|�C���^</param>
GameOver::GameOver(GameScene* argGameScene):GameState(argGameScene){

	gameOverImage = LoadGraph("Image/Game/GameOver.png");

}

/// <summary>
/// ���������m�ۂ��Ă����ꍇ�͉������
/// </summary>
GameOver::~GameOver(){
}

/// <summary>
/// 1���[�v���ŕK�v�ȍX�V�������s��
/// </summary>
void GameOver::Update(){

	SoundPlayer::GetInstance().StopBGM();

	if(KeyboardManager::GetInstance().Input(KEY_INPUT_SPACE) == 1){
		gameScene->NextScene(Scene_Result);
	}

}

/// <summary>
/// 1���[�v���ŕK�v�ȍX�V�������s��
/// </summary>
void GameOver::Draw(){

	DrawGraph(0, 0, gameOverImage, TRUE);

}