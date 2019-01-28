#include "GamePlay.h"
#include "DxLib.h"
#include "../../Object/Laby.h"
#include "../../Object/Player.h"
#include "../../Object/Mirror.h"
#include "../../UI/Timer.h"
#include "../../UI/GameText.h"
#include "../../Manager/FileManager.h"
#include "../../System/SoundPlayer.h"

const int Player_Object = 0;

GamePlay::GamePlay(GameScene *argGameScene):GameState(argGameScene){

	StageCreate();

}

GamePlay::~GamePlay(){

	SoundPlayer::GetInstance().StopBGM();
	delete laby;
	delete player;
	delete mirror;
	delete timer;
	delete gameText;

}

void GamePlay::Update(){

	int keyInput = Dire_Nore;

	laby->Update();

	if(KeyboardManager::GetInstance().Input(KEY_INPUT_UP) == 1){
		keyInput = Dire_Up;
	}
	if(KeyboardManager::GetInstance().Input(KEY_INPUT_DOWN) == 1){
		keyInput = Dire_Down;
	}
	if(KeyboardManager::GetInstance().Input(KEY_INPUT_LEFT) == 1){
		keyInput = Dire_Left;
	}
	if(KeyboardManager::GetInstance().Input(KEY_INPUT_RIGHT) == 1){
		keyInput = Dire_Right;
	}

	if(keyInput != Dire_Nore){
		player->Direction(keyInput);
		mirror->Direction();

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

void GamePlay::Draw(){

	laby->Draw();
	player->Draw();
	mirror->Draw();
	timer->Draw();
	gameText->Draw();

}

void GamePlay::StageCreate(){

	char fileName[64];
	sprintf_s(fileName, sizeof(fileName), "Stage/Stage%d.csv", gameScene->GetStageNum());

	int fp;
	char inputc;
	Position<int> pos;
	int x = 0;
	int y = 0;

	fp = FileManager::GetInstance().FileOpen(fileName);
	if(fp == NULL){
		printfDx("�t�@�C����ǂݍ��߂܂���ł���");
		gameScene->NextScene(Scene_Title);
		return;
	}

	laby = new Laby();

	while(1){

		//�ꕶ���擾
		inputc = FileRead_getc(fp);

		//�X���b�V���̓R�����g�Ȃ̂œǂݔ�΂�
		if(inputc == '/'){
			while(FileRead_getc(fp) != '\n');
			continue;
		}

		//��؂���΂�
		if(inputc == ',' || inputc == '\n' || inputc == '\r'){
			continue;
		}

		//�t�@�C�������ɗ����ꍇ���[�v�t���O��ύX����
		if(inputc == EOF){
			break;
		}

		int createObj = atoi(&inputc);

		if(createObj == Player_Object){
			player = new Player(pos);
		}
		
		laby->PushBlockObject(createObj, pos);

		x++;
		if(x % gameScene->Laby_Width == 0){
			y++;
			x = 0;
		}

		pos.SetPosition(x, y);

	}

	mirror = new Mirror(player);
	timer = new Timer();
	gameText = new GameText();

	FileManager::GetInstance().FileClose();

}