#include "GameScene.h"
#include "GameState/GameState.h"
#include "GameState/GameStateList.h"
#include "../System/SoundPlayer.h"

const int GameScene::Max_Stage_Num = 25;
const int GameScene::Laby_Height = 15;
const int GameScene::Laby_Width = 20;

/// <summary>
/// �R���X�g���N�^
/// </summary>
/// <param name="argSceneChanger">SceneChanger�̃|�C���^</param>
GameScene::GameScene(SceneChanger* argSceneChanger):BaseScene(argSceneChanger){

	gameState = new ModeSelect(this);
	nowStageNum = 1;

}

/// <summary>
/// �f�X�g���N�^
/// </summary>
GameScene::~GameScene(){

	delete gameState;

}

/// <summary>
/// �X�V�������s��
/// </summary>
void GameScene::Update(){

	if(KeyboardManager::GetInstance().Input(KEY_INPUT_ESCAPE) == 1){
		SoundPlayer::GetInstance().StopBGM();
		sceneChanger->SetNextScene(Scene_Title);
	}

	gameState->Update();

}

/// <summary>
/// �`�揈�����s��
/// </summary>
void GameScene::Draw(){

	gameState->Draw();

}

/// <summary>
/// �Q�[���̏�Ԃɍ��킹���N���X�𐶐�����
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
/// ���Ɉړ�����V�[�����X�V����
/// </summary>
/// <param name="nextScene">�ړ���̃V�[���ԍ�</param>
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
/// ���݂̃X�e�[�W�����X�V����
/// </summary>
/// <param name="argStageNum">���B�����X�e�[�W��</param>
void GameScene::SetStageNum(int argStageNum){

	nowStageNum = argStageNum;

}

/// <summary>
/// ���݂̃X�e�[�W�����擾����
/// </summary>
/// <returns>���݂̃X�e�[�W��</returns>
int GameScene::GetStageNum(){

	return nowStageNum;
}