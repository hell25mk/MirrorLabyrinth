#include "GameClear.h"
#include "DxLib.h"
#include "../../System/SoundPlayer.h"

/// <summary>
/// �����o������������
/// </summary>
/// <param name="argSceneChanger">SceneChanger�̃|�C���^</param>
GameClear::GameClear(GameScene* argGameScene):GameState(argGameScene){

	gameClearImage = LoadGraph("Image/Game/GameClear.png");

}

/// <summary>
/// ���������m�ۂ��Ă����ꍇ�͉������
/// </summary>
GameClear::~GameClear(){
}

/// <summary>
/// 1���[�v���ŕK�v�ȍX�V�������s��
/// </summary>
void GameClear::Update(){

	SoundPlayer::GetInstance().StopBGM();

	if(KeyboardManager::GetInstance().Input(KEY_INPUT_SPACE) == 1){
		gameScene->NextScene(Scene_Result);
	}

}

/// <summary>
/// 1���[�v���ŕK�v�ȕ`�揈�����s��
/// </summary>
void GameClear::Draw(){

	DrawGraph(0, 0, gameClearImage, TRUE);

}