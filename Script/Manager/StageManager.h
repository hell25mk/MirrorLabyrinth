#pragma once

#include "../Define/Enum.h"
#include <vector>

class C_StageState;

class C_StageManager{

public:
	C_StageManager();
	~C_StageManager();
	void Update();
	void Draw();
	void SetStageNum();
	int GetStageNum();
	void SetStageState();
	void SetGameState(e_GameState argGameState);
	e_GameState GetGameState();

public:
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
	C_StageState *nowState;
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

