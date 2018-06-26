#pragma once

#include "StageState.h"

class C_Laby;
class C_Player;
class C_Mirror;
class C_Timer;
class C_GameText;

class C_GamePlay : public C_StageState{

public:
	C_GamePlay(C_StageManager *argStageManager);
	virtual ~C_GamePlay();
	virtual void Update() override;
	virtual void Draw() override;
	void StageCreate();

private:
	C_Laby *laby;
	C_Player *player;
	C_Mirror *mirror;
	C_Timer *timer;
	C_GameText *gameText;

};

