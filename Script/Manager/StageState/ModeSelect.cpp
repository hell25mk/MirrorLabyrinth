#include "ModeSelect.h"
#include "DxLib.h"


C_ModeSelect::C_ModeSelect(C_StageManager *argStageManager):C_StageState(argStageManager){
}


C_ModeSelect::~C_ModeSelect(){
}

void C_ModeSelect::Update(){

	if(C_KeyboardManager::GetInstance().Input(KEY_INPUT_DOWN) == 1){
		nowSelectMode = (e_ModeSelect)((nowSelectMode + 1) % Mode_Num);
	}

	if(C_KeyboardManager::GetInstance().Input(KEY_INPUT_UP) == 1){
		nowSelectMode = (e_ModeSelect)((nowSelectMode + (Mode_Num - 1)) % Mode_Num);
	}

	switch(nowSelectMode){
		case Mode_NormalPlay:
			if(C_KeyboardManager::GetInstance().Input(KEY_INPUT_SPACE) == 1){
				nowStageNum = 1;
				nowGameState = State_GameStart;
				C_SoundPlayer::GetInstance().PlayBGM("Stage");
			}
			break;
		case Mode_SelectStage:
			if(C_KeyboardManager::GetInstance().Input(KEY_INPUT_LEFT) == 1){
				if(nowStageNum > 1){
					nowStageNum--;
				}
			}
			if(C_KeyboardManager::GetInstance().Input(KEY_INPUT_RIGHT) == 1){
				if(nowStageNum < Max_Stage_Num){
					nowStageNum++;
				}
			}

			if(C_KeyboardManager::GetInstance().Input(KEY_INPUT_SPACE) == 1){
				nowGameState = State_GameStart;
				C_SoundPlayer::GetInstance().PlayBGM("Stage");
			}
			break;
		case Mode_Exit:
			if(C_KeyboardManager::GetInstance().Input(KEY_INPUT_SPACE) == 1){
				nowGameState = State_Nore;
			}
			break;
	}

}

void C_ModeSelect::Draw(){

	int normalPlayAlpha(128);
	int selectStageAlpha(128);
	int extraStageAlpha(128);
	int exitAlpha(128);

	DrawGraph(0, 0, backGroundImage, TRUE);

	switch(nowSelectMode){
		case Mode_NormalPlay:
			normalPlayAlpha = 255;
			break;
		case Mode_SelectStage:
			selectStageAlpha = 255;
			break;
		case Mode_Exit:
			exitAlpha = 255;
			break;
	}

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, normalPlayAlpha);
	DrawGraph(0, 0, normalPlayImage, TRUE);
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, selectStageAlpha);
	DrawGraph(0, 0, selectStageImage, TRUE);
	//ƒtƒƒA”•\Ž¦
	if(nowStageNum < 10){
		DrawRotaGraph(450, 230, 0.7, 0.0, numberImage[nowStageNum], TRUE);
	} else{
		DrawRotaGraph(400, 230, 0.7, 0.0, numberImage[nowStageNum / 10], TRUE);		//2Œ…–Ú
		DrawRotaGraph(460, 230, 0.7, 0.0, numberImage[nowStageNum % 10], TRUE);		//1Œ…–Ú
	}
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, exitAlpha);
	DrawGraph(0, 0, backImage, TRUE);


	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

}