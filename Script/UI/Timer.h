#pragma once

#include "../Define/Enum.h"

class C_Timer{

public:
	C_Timer();
	~C_Timer();
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

