/*****************************************************************************************************
-----ファイル概要-----
ゲーム中のテキスト
******************************************************************************************************/

#pragma once

class GameText{

public:
	/// <summary>
	/// メンバを初期化する
	/// </summary>
	GameText();
	/// <summary>
	/// メモリを確保していた場合は解放する
	/// </summary>
	~GameText();

	/// <summary>
	/// 1ループ内で必要な描画処理を行う
	/// </summary>
	void Draw();

private:
	char strGameLevel[10];

};

