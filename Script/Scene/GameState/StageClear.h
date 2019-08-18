/*****************************************************************************************************
-----ファイル概要-----
GameStateを継承
ステージクリアの状態
******************************************************************************************************/

#pragma once

#include "GameState.h"

class StageClear : public GameState{

public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="argSceneChanger">SceneChangerのポインタ</param>
	StageClear(GameScene* argGameScene);
	/// <summary>
	/// デストラクタ
	/// </summary>
	virtual ~StageClear();

	/// <summary>
	/// 更新処理を行う
	/// </summary>
	virtual void Update() override;
	/// <summary>
	/// 描画処理を行う
	/// </summary>
	virtual void Draw() override;

private:
	int nowStageNum;
	int numberImage[10];
	int stageClearImage;

};

