#include "GameText.h"
#include "DxLib.h"
#include "../System/GameInfo.h"

const int Color_White = GetColor(255, 255, 255);

GameText::GameText(){

	const char* levelName[3] = { "Easy","Normal","Hard" };

	strcpy_s(strGameLevel, sizeof(strGameLevel), levelName[GameInfo::GetInstance().GetGameLevel()]);

}

GameText::~GameText(){
}

void GameText::Draw(){

	SetFontSize(36);

	DrawString(720, 250, "Level", Color_White);
	DrawString(725, 300, strGameLevel, Color_White);

	SetFontSize(DEFAULT_FONT_SIZE);

}
