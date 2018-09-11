#include "GameManager.h"
#include "SceneManager.h"
#include "KeyboardManager.h"
#include "FPSManager.h"
#include "../System/SoundPlayer.h"
#include "../System/GameInfo.h"

void C_GameManager::Create(){

	//ゲームのシステム部分の生成
	C_KeyboardManager::GetInstance().Create();
	C_SoundPlayer::GetInstance().Create();
	C_GameInfo::GetInstance().Create();
	C_FPSManager::GetInstance().Create();
	sceneManager = new C_SceneManager();

}

void C_GameManager::Destroy(){

	//メモリの解放
	delete sceneManager;
	C_FPSManager::GetInstance().Destroy();
	C_GameInfo::GetInstance().Destroy();
	C_SoundPlayer::GetInstance().Destroy();
	C_KeyboardManager::GetInstance().Destroy();

}

bool C_GameManager::Update(){

	C_FPSManager::GetInstance().Update();
	C_KeyboardManager::GetInstance().Update();
	sceneManager->Update();

	if(sceneManager->GetNextScene() == Scene_End){
		return false;
	}

	return true;
}

void C_GameManager::Draw(){

	sceneManager->Draw();

#ifdef _DEBUG
	C_FPSManager::GetInstance().Draw();
#endif // FPS表示
	C_FPSManager::GetInstance().Wait();

}