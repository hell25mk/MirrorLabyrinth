/*****************************************************************************************************
-----ファイル概要-----
GameStateを継承
ゲームの状態の基底クラス
******************************************************************************************************/

#pragma once

#include "GameState.h"

class GameStart : public GameState{

public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="argSceneChanger">SceneChangerのポインタ</param>
	GameStart(GameScene* argGameScene);
	/// <summary>
	/// デストラクタ
	/// </summary>
	virtual ~GameStart();

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
	int floorImage;

};

