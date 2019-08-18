#include "GameStart.h"
#include "DxLib.h"
#include "../../System/SoundPlayer.h"

/// <summary>
/// コンストラクタ
/// </summary>
/// <param name="argSceneChanger">SceneChangerのポインタ</param>
GameStart::GameStart(GameScene* argGameScene):GameState(argGameScene){

	nowStageNum = gameScene->GetStageNum();
	SoundPlayer::GetInstance().PlayBGM("Stage");

	LoadDivGraph("Image/Share/Number.png", 10, 10, 1, 96, 96, numberImage);
	floorImage = LoadGraph("Image/Game/Floor.png");

}

/// <summary>
/// デストラクタ
/// </summary>
GameStart::~GameStart(){
}

/// <summary>
/// 更新処理を行う
/// </summary>
void GameStart::Update(){

	if(KeyboardManager::GetInstance().Input(KEY_INPUT_SPACE) == 1){
		gameScene->SetGameState(gameScene->State_GamePlay);
	}

}

/// <summary>
/// 描画処理を行う
/// </summary>
void GameStart::Draw(){

	//ステージが1桁か2桁かで処理を切り替える
	bool isDrawStageNum = nowStageNum < 10;
	if(isDrawStageNum){
		DrawRotaGraph(400, 150, 1.2, 0.0, numberImage[nowStageNum], TRUE);
	} else{
		DrawRotaGraph(340, 150, 1.2, 0.0, numberImage[nowStageNum / 10], TRUE);		//2桁目
		DrawRotaGraph(420, 150, 1.2, 0.0, numberImage[nowStageNum % 10], TRUE);		//1桁目
	}

	DrawGraph(0, 0, floorImage, TRUE);

}