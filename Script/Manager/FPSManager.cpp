#include "FPSManager.h"
#include "DxLib.h"

const int Color_White = GetColor(255, 255, 255);
const int FPSManager::Average_Sample = 60;
const int FPSManager::Basis_FPS = 60;

void FPSManager::Create(){

	startTime = 0;
	timeCount = 0;
	fps = 0;

}

void FPSManager::Destroy(){
}

bool FPSManager::Update(){

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

	return true;
}

void FPSManager::Draw(){

	DrawFormatString(800, 455, Color_White, "%4.1ffps", fps);

}

void FPSManager::Wait(){

	int tookTime = GetNowCount() - startTime;					//かかった時間
	int waitTime = timeCount * 1000 / Basis_FPS - tookTime;		//待つべき時間

	if(waitTime > 0){
		Sleep(waitTime);		//待機
	}

}