#include "GamePlay.h"
#include "DxLib.h"
#include "../../Object/Laby.h"
#include "../../Object/Player.h"
#include "../../Object/Mirror.h"
#include "../../UI/Timer.h"
#include "../../UI/GameText.h"
#include "../../Manager/FileManager.h"
#include "../../System/SoundPlayer.h"

const int Player_Object = 100;

C_GamePlay::C_GamePlay(C_GameScene *argGameScene):C_GameState(argGameScene){

	StageCreate();

}

C_GamePlay::~C_GamePlay(){

	C_SoundPlayer::GetInstance().StopBGM();
	delete laby;
	delete player;
	delete mirror;
	delete timer;
	delete gameText;

}

void C_GamePlay::Update(){

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
			mirror->Move();
		}
	}

	player->Update();
	mirror->Update();
	if(laby->ClearCheck(player->GetPosition())){
		gameScene->SetGameState(gameScene->State_StageClear);
	}

	timer->Update();
	bool timeOverFlag = timer->GetGameTimer() <= 0;
	if(timeOverFlag){
		gameScene->SetGameState(gameScene->State_GameOver);
	}

}

void C_GamePlay::Draw(){

	laby->Draw();
	player->Draw();
	mirror->Draw();
	timer->Draw();
	gameText->Draw();

}

void C_GamePlay::StageCreate(){

	char fileName[64];
	sprintf_s(fileName, sizeof(fileName), "Stage/Stage%d.csv", gameScene->GetStageNum());

	int fp;
	char inputc;
	C_Position<int> pos;
	pos.x = 0;
	pos.y = 0;

	fp = C_FileManager::GetInstance().FileOpen(fileName);
	if(fp == NULL){
		printfDx("ファイルを読み込めませんでした");
		gameScene->NextScene(Scene_Title);
		return;
	}

	laby = new C_Laby();

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

		int createObj = atoi(&inputc);

		if(createObj == Player_Object){
			//player = new C_Player(pos);
		} else{
			laby->PushBlockObject(createObj, pos);
		}

		pos.x++;
		if(pos.x % gameScene->Laby_Width == 0){
			pos.y++;
			pos.x = 0;
		}

	}

	pos.x = 1;
	pos.y = 13;
	player = new C_Player(pos);
	mirror = new C_Mirror(player);
	timer = new C_Timer();
	gameText = new C_GameText();

	C_FileManager::GetInstance().FileClose();

}