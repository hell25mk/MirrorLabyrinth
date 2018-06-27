#include "GameText.h"
#include "DxLib.h"
#include "../System/GameInfo.h"

const int Color_White = GetColor(255, 255, 255);

C_GameText::C_GameText(){

	const char *levelName[3] = { "Easy","Normal","Hard" };

	strcpy_s(strGameLevel, sizeof(strGameLevel), levelName[C_GameInfo::GetInstance().GetGameLevel()]);

}

C_GameText::~C_GameText(){
}

void C_GameText::Draw(){

	SetFontSize(36);

	DrawString(720, 250, "Level", Color_White);
	DrawString(725, 300, strGameLevel, Color_White);

	SetFontSize(DEFAULT_FONT_SIZE);

}
