#include "Timer.h"
#include "DxLib.h"
#include "../System/GameInfo.h"

const int Color_White = GetColor(255, 255, 255);
const int Color_Red = GetColor(255, 0, 0);
const int C_Timer::BasisTime = 60;

C_Timer::C_Timer(){

	startTime = 0;
	nowGameTime = BasisTime  / (C_GameInfo::GetInstance().GetGameLevel() + 1);

}

C_Timer::~C_Timer(){
}

void C_Timer::Update(){

	if(startTime == 0){
		startTime = GetNowCount();
	}

	bool oneSecondFlag = GetNowCount() - startTime >= 1000;
	if(oneSecondFlag){
		nowGameTime = nowGameTime - 1;
		startTime = GetNowCount();
	}

	minute = nowGameTime / 60;
	second = nowGameTime % 60;

}

void C_Timer::Draw(){

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

int C_Timer::GetGameTimer(){

	return nowGameTime;
}