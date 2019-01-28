#include "Timer.h"
#include "DxLib.h"
#include "../System/GameInfo.h"

const int Color_White = GetColor(255, 255, 255);
const int Color_Red = GetColor(255, 0, 0);
const int Timer::BasisTime = 60;

Timer::Timer(){

	startTime = 0;
	nowGameTime = BasisTime  / (GameInfo::GetInstance().GetGameLevel() + 1);		//�Q�[����Փx�ɂ���Đ������Ԃ̕ύX

}

Timer::~Timer(){
}

void Timer::Update(){

	if(startTime == 0){
		startTime = GetNowCount();
	}

	//1�b���v��
	bool oneSecondFlag = GetNowCount() - startTime >= 1000;
	if(oneSecondFlag){
		nowGameTime = nowGameTime - 1;
		startTime = GetNowCount();
	}

	//���ƕb�ɕϊ�
	minute = nowGameTime / 60;
	second = nowGameTime % 60;

}

void Timer::Draw(){

	SetFontSize(36);

	DrawFormatString(720, 100, Color_White, "Limit");

	bool drawTimeFlag = nowGameTime < 10;
	if(drawTimeFlag){
		DrawFormatString(700, 150, Color_Red, "%02d : %02d", minute, second);
	} else{
		DrawFormatString(700, 150, Color_White, "%02d : %02d", minute, second);
	}

	SetFontSize(DEFAULT_FONT_SIZE);

}

int Timer::GetGameTimer(){

	return nowGameTime;
}