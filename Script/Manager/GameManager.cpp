#include "GameManager.h"
#include "SceneManager.h"
#include "KeyboardManager.h"
#include "FPSManager.h"
#include "../System/SoundPlayer.h"
#include "../System/GameInfo.h"

void GameManager::Create(){

	//ゲームのシステム部分の生成
	KeyboardManager::GetInstance().Create();
	SoundPlayer::GetInstance().Create();
	GameInfo::GetInstance().Create();
	FPSManager::GetInstance().Create();
	sceneManager = new SceneManager();

}

void GameManager::Destroy(){

	//メモリの解放
	delete sceneManager;
	FPSManager::GetInstance().Destroy();
	GameInfo::GetInstance().Destroy();
	SoundPlayer::GetInstance().Destroy();
	KeyboardManager::GetInstance().Destroy();

}

bool GameManager::Update(){

	FPSManager::GetInstance().Update();
	KeyboardManager::GetInstance().Update();
	sceneManager->Update();

	if(sceneManager->GetNextScene() == Scene_End){
		return false;
	}

	return true;
}

void GameManager::Draw(){

	sceneManager->Draw();

#ifdef _DEBUG
	FPSManager::GetInstance().Draw();
#endif // FPS表示
	FPSManager::GetInstance().Wait();

}