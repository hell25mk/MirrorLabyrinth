#include "StageClear.h"
#include "DxLib.h"

/// <summary>
/// メンバを初期化する
/// </summary>
/// <param name="argSceneChanger">SceneChangerのポインタ</param>
StageClear::StageClear(GameScene *argGameScene):GameState(argGameScene){

	nowStageNum = gameScene->GetStageNum();
	LoadDivGraph("Image/Share/Number.png", 10, 10, 1, 96, 96, numberImage);
	stageClearImage = LoadGraph("Image/Game/StageClear.png");

}

/// <summary>
/// メモリを確保していた場合は解放する
/// </summary>
StageClear::~StageClear(){
}

/// <summary>
/// 1ループ内で必要な更新処理を行う
/// </summary>
void StageClear::Update(){

	if(KeyboardManager::GetInstance().Input(KEY_INPUT_SPACE) == 1){
		int nextStageNum = nowStageNum + 1;
		bool stageCheckFlag = nextStageNum > gameScene->Max_Stage_Num;

		if(!stageCheckFlag){
			gameScene->SetStageNum(nextStageNum);
			gameScene->SetGameState(gameScene->State_GameStart);
			return;
		}

		gameScene->SetGameState(gameScene->State_GameClear);
	}

}

/// <summary>
/// 1ループ内で必要な描画処理を行う
/// </summary>
void StageClear::Draw(){

	//ステージ数が1桁か2桁かによって処理を変える
	bool drawStageNumFlag = nowStageNum < 10;
	if(drawStageNumFlag){
		DrawRotaGraph(400, 150, 1.2, 0.0, numberImage[nowStageNum], TRUE);
	} else{
		DrawRotaGraph(340, 150, 1.2, 0.0, numberImage[nowStageNum / 10], TRUE);		//2桁目
		DrawRotaGraph(420, 150, 1.2, 0.0, numberImage[nowStageNum % 10], TRUE);		//1桁目
	}

	DrawGraph(0, 0, stageClearImage, TRUE);
	
}