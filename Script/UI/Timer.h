/*****************************************************************************************************
-----�t�@�C���T�v-----
���Ԃ��Ǘ�����N���X
���������Ƃ����̂ɂł���͂�
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

