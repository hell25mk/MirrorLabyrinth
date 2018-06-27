#pragma once

#include "../Base/BaseScene.h"

class C_GameState;

class C_GameScene : public C_BaseScene{

public:
	C_GameScene(C_SceneChanger *argSceneChanger);
	virtual ~C_GameScene();
	void Update() override;
	void Draw() override;
	void SetGameState(int argGameState);
	void NextScene(int argNextScene);
	void SetStageNum(int argStageNum);
	int GetStageNum();

public:
	static const int Max_Stage_Num;
	static const int Laby_Height;
	static const int Laby_Width;
	typedef enum{
		State_ModeSelect,
		State_GameStart,
		State_GamePlay,
		State_StageClear,
		State_GameClear,
		State_GameOver,
		State_Result,

		State_Nore,
	}e_GameState;

private:
	C_GameState *gameState;
	int nowStageNum;

};

