/*****************************************************************************************************
-----�t�@�C���T�v-----
GameState���p��
�Q�[���v���C���̏��
******************************************************************************************************/

#pragma once

#include "GameState.h"

class Laby;
class Player;
class Mirror;
class Timer;
class GameText;

class GamePlay : public GameState{

public:
	GamePlay(GameScene* argGameScene);
	virtual ~GamePlay();
	virtual void Update() override;
	virtual void Draw() override;
	void StageCreate();

private:
	Laby* laby;
	Player* player;
	Mirror* mirror;
	Timer* timer;
	GameText* gameText;

};

