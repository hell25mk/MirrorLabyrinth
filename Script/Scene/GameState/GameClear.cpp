#include "GameClear.h"
#include "DxLib.h"
#include "../../System/SoundPlayer.h"

/// <summary>
/// �R���X�g���N�^
/// </summary>
/// <param name="argSceneChanger">SceneChanger�̃|�C���^</param>
GameClear::GameClear(GameScene* argGameScene):GameState(argGameScene){

	gameClearImage = LoadGraph("Image/Game/GameClear.png");

}

/// <summary>
/// �f�X�g���N�^
/// </summary>
GameClear::~GameClear(){
}

/// <summary>
/// �X�V�������s��
/// </summary>
void GameClear::Update(){

	SoundPlayer::GetInstance().StopBGM();

	if(KeyboardManager::GetInstance().Input(KEY_INPUT_SPACE) == 1){
		gameScene->NextScene(Scene_Result);
	}

}

/// <summary>
/// �`�揈�����s��
/// </summary>
void GameClear::Draw(){

	DrawGraph(0, 0, gameClearImage, TRUE);

}