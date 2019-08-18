#include "FPSManager.h"
#include "DxLib.h"

const int Color_White = GetColor(255, 255, 255);
const int FPSManager::Average_Sample = 60;
const int FPSManager::Basis_FPS = 60;

/// <summary>
/// 初期化処理を行う
/// </summary>
void FPSManager::Create(){

	startTime = 0;
	timeCount = 0;
	fps = 0.0f;

}

/// <summary>
/// 終了処理を行う
/// </summary>
void FPSManager::Destroy(){
}

/// <summary>
/// 更新処理を行う
/// </summary>
void FPSManager::Update(){

	//1フレーム目なら時刻を記憶
	if(timeCount == 0){
		startTime = GetNowCount();
	}

	//60フレーム目なら平均を計算
	if(timeCount == Average_Sample){
		int time = GetNowCount();
		fps = 1000.f / ((time - startTime) / (float)Average_Sample);
		timeCount = 0;
		startTime = time;
	}

	timeCount++;

}

/// <summary>
/// 描画処理を行う
/// </summary>
void FPSManager::Draw(){

	DrawFormatString(800, 455, Color_White, "%4.1ffps", fps);

}

/// <summary>
/// FPS調整のため処理を待機させる
/// </summary>
void FPSManager::Wait(){

	int tookTime = GetNowCount() - startTime;					//かかった時間
	int waitTime = timeCount * 1000 / Basis_FPS - tookTime;		//待つべき時間

	if(waitTime > 0){
		Sleep(waitTime);		//待機
	}

}