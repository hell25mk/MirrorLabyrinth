/*****************************************************************************************************
-----ファイル概要-----
時間を管理するクラス
******************************************************************************************************/

#pragma once

#include "../Define/Enum.h"

class Timer{

public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	Timer();
	/// <summary>
	/// デストラクタ
	/// </summary>
	~Timer();

	/// <summary>
	/// 更新処理を行う
	/// </summary>
	void Update();
	/// <summary>
	/// 描画処理を行う
	/// </summary>
	void Draw();

	/// <summary>
	/// 現在の進行時間を取得
	/// </summary>
	/// <returns>進行後の時間</returns>
	int GetGameTimer();

private:
	static const int BasisTime;
	int nowGameTime;
	int startTime;
	int second;
	int minute;

};

