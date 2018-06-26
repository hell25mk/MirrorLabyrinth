#pragma once

#include "../Define/Enum.h"
#include <vector>

class C_Laby;
class C_Player;
class C_Mirror;
class C_Timer;
class C_GameText;

class C_StageManager{

public:
	C_StageManager();
	~C_StageManager();

	void StageInit();
	void StageCreate();
	int GetStageNum();

	void ModeSelectUpdate();
	void ModeSelectDraw();

	void GameStartUpdate();
	void GameStartDraw();

	void GamePlayUpdate();
	void GamePlayDraw();

	void StageClearUpdate();
	void StageClearDraw();

	void GameClearUpdate();
	void GameClearDraw();

	void GameOverUpdate();
	void GameOverDraw();

	e_GameState GetGameState();

private:
#pragma region íËêî
	static const int Max_Stage_Num;
	static const int Laby_Height;
	static const int Laby_Width;
	typedef enum{
		Mode_NormalPlay,
		Mode_SelectStage,
		Mode_Exit,

		Mode_Num,
	}e_ModeSelect;
#pragma endregion

private:
	C_Laby *laby;
	C_Player *player;
	C_Mirror *mirror;
	C_Timer *timer;
	C_GameText *gameText;
	e_GameState nowGameState;
	int nowStageNum;
	e_ModeSelect nowSelectMode;

#pragma region Material
	//Image
	int backGroundImage;
	int numberImage[10];
	int floorImage;
	int stageClearImage;
	int gameClearImage;
	int gameOverImage;
	int normalPlayImage;
	int selectStageImage;
	int extraStageImage;
	int backImage;
#pragma endregion

};

