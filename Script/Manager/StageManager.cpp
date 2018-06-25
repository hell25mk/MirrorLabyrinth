#include "StageManager.h"
#include "DxLib.h"
#include "KeyboardManager.h"
#include "../Object/Laby.h"
#include "../Object/Player.h"
#include "../UI/Timer.h"
#include "../UI/GameText.h"
#include "../System/Position.h"
#include "../System/SoundPlayer.h"
#include "../Manager/FileManager.h"

const int C_StageManager::Max_Stage_Num = 20;
const int C_StageManager::Laby_Height = 15;
const int C_StageManager::Laby_Width = 20;

C_StageManager::C_StageManager(){

	nowStageNum = 1;

	backGroundImage = LoadGraph("Image/Share/BackGround.png");
	LoadDivGraph("Image/Share/Number.png", 10, 10, 1, 96, 96, numberImage);
	floorImage = LoadGraph("Image/Game/Floor.png");
	stageClearImage = LoadGraph("Image/Game/StageClear.png");
	gameClearImage = LoadGraph("Image/Game/GameClear.png");
	gameOverImage = LoadGraph("Image/Game/GameOver.png");
	normalPlayImage = LoadGraph("Image/Game/ModeSelectNormalPlay.png");
	selectStageImage = LoadGraph("Image/Game/ModeSelectSelectStage.png");
	extraStageImage = LoadGraph("ImageGame//ModeSelectExtraStage.png");
	backImage = LoadGraph("Image/Game/ModeSelecBack.png");
	
#ifdef _DEBUG
	nowStageNum = Max_Stage_Num;
#endif //ステージ確認

	nowGameState = State_ModeSelect;
	nowSelectMode = Mode_NormalPlay;

}


C_StageManager::~C_StageManager(){

	C_SoundPlayer::GetInstance().StopBGM();
	delete laby;
	delete player;
	delete timer;
	delete gameText;

}

void C_StageManager::StageInit(){

	//初期化
	laby = NULL;
	player = NULL;
	timer = NULL;
	gameText = NULL;
	nowGameState = State_GamePlay;
	
	//生成
	C_Position<int> pos;
	laby = new C_Laby(nowStageNum);
	pos.x = 1;
	pos.y = 13;
	player = new C_Player(pos);
	timer = new C_Timer();
	gameText = new C_GameText();

}

void C_StageManager::StageCreate(){

	/*C_Position pos;

	char fileName[64];
	sprintf_s(fileName, sizeof(fileName), "Stage/Stage%d.csv", nowStageNum);

	int fp = C_FileManager::GetInstance().FileOpen(fileName);
	char inputc;
	pos.x = 0;
	pos.y = 0;

	if(fp == NULL){
		labyVector = LabySampleVector;
		return;
	}

	while(1){

		//一文字取得
		inputc = FileRead_getc(fp);

		//スラッシュはコメントなので読み飛ばす
		if(inputc == '/'){
			while(FileRead_getc(fp) != '\n');
			continue;
		}

		//区切りを飛ばす
		if(inputc == ',' || inputc == '\n' || inputc == '\r'){
			continue;
		}

		//ファイル末尾に来た場合ループフラグを変更する
		if(inputc == EOF){
			break;
		}

		//ドアと鍵を生成する
		labyVector[pos.y * Laby_Width + pos.x] = atoi(&inputc);

		switch(labyVector[pos.y * Laby_Width + pos.x]){
			case Laby_Wall:
				//wall.push_back(C_Wall(pos));
				break;
			case Laby_Door:
				door = new C_Door(pos);
				break;
			case Laby_Key:
				keyList.push_back(C_Key(pos));
				break;
			case Laby_BreakWall:
				breakWallList.push_back(C_BreakWall(pos));
				break;
		}

		pos.x++;
		if(pos.x % Laby_Width == 0){
			pos.y++;
			pos.x = 0;
		}

	}

	C_FileManager::GetInstance().FileClose();*/

}

#pragma region ModeSelect
void C_StageManager::ModeSelectUpdate(){

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
		/*case Mode_ExtraStage:
			if(C_KeyboardManager::GetInstance().Input(KEY_INPUT_SPACE) == 1){
				//nowStageNum = 99;
				nowGameState = State_GameStart;
			}
			break;*/
		case Mode_Exit:
			if(C_KeyboardManager::GetInstance().Input(KEY_INPUT_SPACE) == 1){
				nowGameState = State_Nore;
			}
			break;
	}
	
}

void C_StageManager::ModeSelectDraw(){

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
		/*case Mode_ExtraStage:
			extraStageAlpha = 255;
			break;*/
		case Mode_Exit:
			exitAlpha = 255;
			break;
	}

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, normalPlayAlpha);
	DrawGraph(0, 0, normalPlayImage, TRUE);
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, selectStageAlpha);
	DrawGraph(0, 0, selectStageImage, TRUE);
	//フロア数表示
	if(nowStageNum < 10){
		DrawRotaGraph(450, 230, 0.7, 0.0, numberImage[nowStageNum], TRUE);
	} else{
		DrawRotaGraph(400, 230, 0.7, 0.0, numberImage[nowStageNum / 10], TRUE);		//2桁目
		DrawRotaGraph(460, 230, 0.7, 0.0, numberImage[nowStageNum % 10], TRUE);		//1桁目
	}
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, extraStageAlpha);
	//DrawGraph(0, 0, extraStageImage, TRUE);
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, exitAlpha);
	DrawGraph(0, 0, backImage, TRUE);


	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

}
#pragma endregion


#pragma region GameStart
void C_StageManager::GameStartUpdate(){

	if(C_KeyboardManager::GetInstance().Input(KEY_INPUT_SPACE) == 1){
		nowGameState = State_GamePlay;
		StageInit();
	}

}

void C_StageManager::GameStartDraw(){

	bool drawStageNumFlag = nowStageNum < 10;
	if(drawStageNumFlag){
		DrawRotaGraph(400, 150, 1.2, 0.0, numberImage[nowStageNum], TRUE);
	} else{
		DrawRotaGraph(340, 150, 1.2, 0.0, numberImage[nowStageNum / 10], TRUE);		//2桁目
		DrawRotaGraph(420, 150, 1.2, 0.0, numberImage[nowStageNum % 10], TRUE);		//1桁目
	}

	DrawGraph(0, 0, floorImage, TRUE);

}
#pragma endregion

#pragma region GamePlay
void C_StageManager::GamePlayUpdate(){

	int keyInput = Dire_Nore;

	laby->Update();

	if(C_KeyboardManager::GetInstance().Input(KEY_INPUT_UP) == 1){
		keyInput = Dire_Up;
	}
	if(C_KeyboardManager::GetInstance().Input(KEY_INPUT_DOWN) == 1){
		keyInput = Dire_Down;
	}
	if(C_KeyboardManager::GetInstance().Input(KEY_INPUT_LEFT) == 1){
		keyInput = Dire_Left;
	}
	if(C_KeyboardManager::GetInstance().Input(KEY_INPUT_RIGHT) == 1){
		keyInput = Dire_Right;
	}

	if(keyInput != Dire_Nore){
		if(laby->MoveCheck(keyInput, player->GetPosition())){
			player->Move(keyInput);
		}
	}

	player->Update();

	nowGameState = laby->GetGameState(player->GetPosition());

	timer->Update();

	bool timeOverFlag = timer->GetGameTimer() <= 0;
	if(timeOverFlag){
		nowGameState = State_GameOver;
	}

}

void C_StageManager::GamePlayDraw(){

	laby->Draw();
	player->Draw();
	timer->Draw();
	gameText->Draw();

}
#pragma endregion

#pragma region StageClear
void C_StageManager::StageClearUpdate(){

	if(C_KeyboardManager::GetInstance().Input(KEY_INPUT_SPACE) != 1){
		return;
	}

	nowStageNum++;

	bool stageCheckFlag = nowStageNum > Max_Stage_Num;
	if(stageCheckFlag){
		nowGameState = State_GameClear;
	} else{
		nowGameState = State_GameStart;
	}

}

void C_StageManager::StageClearDraw(){

	bool drawStageNumFlag = nowStageNum < 10;
	if(drawStageNumFlag){
		DrawRotaGraph(400, 150, 1.2, 0.0, numberImage[nowStageNum], TRUE);
	} else{
		DrawRotaGraph(340, 150, 1.2, 0.0, numberImage[nowStageNum / 10], TRUE);		//2桁目
		DrawRotaGraph(420, 150, 1.2, 0.0, numberImage[nowStageNum % 10], TRUE);		//1桁目
	}

	DrawGraph(0, 0, stageClearImage, TRUE);

}
#pragma endregion

#pragma region GameClear
void C_StageManager::GameClearUpdate(){

	C_SoundPlayer::GetInstance().StopBGM();

	if(C_KeyboardManager::GetInstance().Input(KEY_INPUT_SPACE) == 1){
		nowGameState = State_Result;
	}

}

void C_StageManager::GameClearDraw(){

	DrawGraph(0, 0, gameClearImage, TRUE);

}
#pragma endregion

#pragma region GameOver
void C_StageManager::GameOverUpdate(){

	C_SoundPlayer::GetInstance().StopBGM();

	if(C_KeyboardManager::GetInstance().Input(KEY_INPUT_SPACE) == 1){
		nowGameState = State_Result;
	}

}

void C_StageManager::GameOverDraw(){

	DrawGraph(0, 0, gameOverImage, TRUE);

}
#pragma endregion

e_GameState C_StageManager::GetGameState(){

	return nowGameState;
}