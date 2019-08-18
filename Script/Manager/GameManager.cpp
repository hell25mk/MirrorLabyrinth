#include "GameManager.h"
#include "SceneManager.h"
#include "KeyboardManager.h"
#include "FPSManager.h"
#include "../System/SoundPlayer.h"
#include "../System/GameInfo.h"

/// <summary>
/// 初期化処理を行う
/// </summary>
void GameManager::Create(){

	//ゲームのシステム部分の生成
	KeyboardManager::GetInstance().Create();
	SoundPlayer::GetInstance().Create();
	GameInfo::GetInstance().Create();
	FPSManager::GetInstance().Create();
	sceneManager = new SceneManager();

}

/// <summary>
/// 終了処理を行う
/// </summary>
void GameManager::Destroy(){

	//メモリの解放
	delete sceneManager;
	FPSManager::GetInstance().Destroy();
	GameInfo::GetInstance().Destroy();
	SoundPlayer::GetInstance().Destroy();
	KeyboardManager::GetInstance().Destroy();

}

/// <summary>
/// 更新処理を行う
/// </summary>
/// <returns>シーンの移動先がScene_End以外だった場合trueを返す</returns>
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
/// 描画処理を行う
/// </summary>
void GameManager::Draw(){

	sceneManager->Draw();

	//Debug時のみFPSを表示する
#ifdef _DEBUG
	FPSManager::GetInstance().Draw();
#endif

	FPSManager::GetInstance().Wait();

}