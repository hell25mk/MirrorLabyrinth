/*****************************************************************************************************
-----ファイル概要-----
時間を管理するクラス
正直もっといいのにできるはず
******************************************************************************************************/

#pragma once

#include "../Define/Enum.h"

class Timer{

public:
	Timer();
	~Timer();
	void Update();
	void Draw();
	int GetGameTimer();

private:
	static const int BasisTime;
	int nowGameTime;
	int startTime;
	int second;
	int minute;

};

