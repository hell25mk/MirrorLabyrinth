/*****************************************************************************************************
-----ファイル概要-----
時間を管理するクラス
******************************************************************************************************/

#pragma once

#include "../Define/Enum.h"

class Timer{

public:
	/// <summary>
	/// メンバを初期化する
	/// </summary>
	Timer();
	/// <summary>
	/// メモリを確保していた場合は解放する
	/// </summary>
	~Timer();

	/// <summary>
	/// 1ループ内で必要な更新処理を行う
	/// </summary>
	void Update();
	/// <summary>
	/// 1ループ内で必要な描画処理を行う
	/// </summary>
	void Draw();

	/// <summary>
	/// 現在の進行時間を取得
	/// </summary>
	/// <returns>進行後の時間</returns>
	int GetGameTimer();

private:
	static const int Basis_Time;
	int nowGameTime;
	int startTime;
	int second;
	int minute;

};

