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

/// <summary>
/// メンバを初期化する
/// </summary>
/// <param name="argSceneChanger">SceneChangerのポインタ</param>
GamePlay::GamePlay(GameScene* argGameScene):GameState(argGameScene){

	StageCreate();

}

/// <summary>
/// メモリを確保していた場合は解放する
/// </summary>
GamePlay::~GamePlay(){

	SoundPlayer::GetInstance().StopBGM();
	delete laby;
	delete player;
	delete mirror;
	delete timer;
	delete gameText;

}

/// <summary>
/// 1ループ内で必要な更新処理を行う
/// </summary>
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

	//プレイヤーが階段にいるか確認する
	if(laby->ClearCheck(player->GetPosition())){
		gameScene->SetGameState(gameScene->State_StageClear);
	}

	//タイマーを更新し時間切れの場合、ゲームオーバー画面へ
	timer->Update();
	bool isTimeOver = timer->GetGameTimer() <= 0;
	if(isTimeOver){
		gameScene->SetGameState(gameScene->State_GameOver);
	}

}

/// <summary>
/// 描画処理行う
/// </summary>
void GamePlay::Draw(){

	laby->Draw();
	player->Draw();
	mirror->Draw();
	timer->Draw();
	gameText->Draw();

}

/// <summary>
/// ファイルからステージを生成する
/// </summary>
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
		printfDx("ファイルを読み込めませんでした");
		gameScene->NextScene(Scene_Title);
		return;
	}

	laby = new Laby();

	while(true){

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