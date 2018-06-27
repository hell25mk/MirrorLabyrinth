#include "StageClear.h"
#include "DxLib.h"

C_StageClear::C_StageClear(C_GameScene *argGameScene):C_GameState(argGameScene){
}

C_StageClear::~C_StageClear(){
}

void C_StageClear::Update(){

	if(C_KeyboardManager::GetInstance().Input(KEY_INPUT_SPACE) != 1){
		return;
	}

	/*nowStageNum++;

	bool stageCheckFlag = nowStageNum > Max_Stage_Num;
	if(stageCheckFlag){
		nowGameState = State_GameClear;
	} else{
		nowGameState = State_GameStart;
	}*/

}

void C_StageClear::Draw(){

	/*bool drawStageNumFlag = nowStageNum < 10;
	if(drawStageNumFlag){
		DrawRotaGraph(400, 150, 1.2, 0.0, numberImage[nowStageNum], TRUE);
	} else{
		DrawRotaGraph(340, 150, 1.2, 0.0, numberImage[nowStageNum / 10], TRUE);		//2Œ…–Ú
		DrawRotaGraph(420, 150, 1.2, 0.0, numberImage[nowStageNum % 10], TRUE);		//1Œ…–Ú
	}

	DrawGraph(0, 0, stageClearImage, TRUE);
	*/
}