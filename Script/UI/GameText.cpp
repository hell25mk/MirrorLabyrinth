#include "GameText.h"
#include "DxLib.h"
#include "../System/GameInfo.h"

const int Color_White = GetColor(255, 255, 255);

/// <summary>
/// メンバを初期化する
/// </summary>
GameText::GameText(){

	const char* levelName[3] = { "Easy","Normal","Hard" };

	//現在のゲームレベルに応じて文字列を作成する
	strcpy_s(strGameLevel, sizeof(strGameLevel), levelName[GameInfo::GetInstance().GetGameLevel()]);

}

/// <summary>
/// メモリを確保していた場合は解放する
/// </summary>
GameText::~GameText(){
}

/// <summary>
/// 1ループ内で必要な描画処理を行う
/// </summary>
void GameText::Draw(){

	SetFontSize(36);

	DrawString(720, 250, "Level", Color_White);
	DrawString(725, 300, strGameLevel, Color_White);

	SetFontSize(DEFAULT_FONT_SIZE);

}
