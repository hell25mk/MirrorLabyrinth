#include "GameManager.h"
#include "SceneManager.h"
#include "KeyboardManager.h"
#include "FPSManager.h"
#include "../System/SoundPlayer.h"
#include "../System/GameInfo.h"

void C_GameManager::Create(){

	C_KeyboardManager::GetInstance().Create();
	C_SoundPlayer::GetInstance().Create();
	C_GameInfo::GetInstance().Create();
	C_FPSManager::GetInstance().Create();
	sceneManager = new C_SceneManager();

}

void C_GameManager::Destroy(){

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
	C_FPSManager::GetInstance().Draw();
	C_FPSManager::GetInstance().Wait();

}