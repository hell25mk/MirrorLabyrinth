#include "FPSManager.h"
#include "DxLib.h"

const int Color_White = GetColor(255, 255, 255);
const int C_FPSManager::Average_Sample = 60;
const int C_FPSManager::Basis_FPS = 60;

void C_FPSManager::Create(){

	startTime = 0;
	timeCount = 0;
	fps = 0;

}

void C_FPSManager::Destroy(){
}

bool C_FPSManager::Update(){

	//1�t���[���ڂȂ玞�����L��
	if(timeCount == 0){
		startTime = GetNowCount();
	}

	//60�t���[���ڂȂ畽�ς��v�Z
	if(timeCount == Average_Sample){
		int time = GetNowCount();
		fps = 1000.f / ((time - startTime) / (float)Average_Sample);
		timeCount = 0;
		startTime = time;
	}

	timeCount++;

	return true;
}

void C_FPSManager::Draw(){

	DrawFormatString(800, 455, Color_White, "%4.1ffps", fps);

}

void C_FPSManager::Wait(){

	int tookTime = GetNowCount() - startTime;					//������������
	int waitTime = timeCount * 1000 / Basis_FPS - tookTime;		//�҂ׂ�����

	if(waitTime > 0){
		Sleep(waitTime);		//�ҋ@
	}

}