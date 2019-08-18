#include "GameManager.h"
#include "SceneManager.h"
#include "KeyboardManager.h"
#include "FPSManager.h"
#include "../System/SoundPlayer.h"
#include "../System/GameInfo.h"

/// <summary>
/// �������������s��
/// </summary>
void GameManager::Create(){

	//�Q�[���̃V�X�e�������̐���
	KeyboardManager::GetInstance().Create();
	SoundPlayer::GetInstance().Create();
	GameInfo::GetInstance().Create();
	FPSManager::GetInstance().Create();
	sceneManager = new SceneManager();

}

/// <summary>
/// �I���������s��
/// </summary>
void GameManager::Destroy(){

	//�������̉��
	delete sceneManager;
	FPSManager::GetInstance().Destroy();
	GameInfo::GetInstance().Destroy();
	SoundPlayer::GetInstance().Destroy();
	KeyboardManager::GetInstance().Destroy();

}

/// <summary>
/// �X�V�������s��
/// </summary>
/// <returns>�V�[���̈ړ��悪Scene_End�ȊO�������ꍇtrue��Ԃ�</returns>
bool GameManager::Update(){

	FPSManager::GetInstance().Update();
	KeyboardManager::GetInstance().Update();
	sceneManager->Update();

	if(sceneManager->GetNextScene() == Scene_End){
		return false;
	}

	return true;
}

/// <summary>
/// �`�揈�����s��
/// </summary>
void GameManager::Draw(){

	sceneManager->Draw();

	//Debug���̂�FPS��\������
#ifdef _DEBUG
	FPSManager::GetInstance().Draw();
#endif

	FPSManager::GetInstance().Wait();

}