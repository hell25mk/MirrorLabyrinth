/*****************************************************************************************************
-----ファイル概要-----
GameStateを継承
ゲームプレイ中の状態
******************************************************************************************************/

#pragma once

#include "GameState.h"

class C_Laby;
class C_Player;
class C_Mirror;
class C_Timer;
class C_GameText;

class C_GamePlay : public C_GameState{

public:
	C_GamePlay(C_GameScene *argGameScene);
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

