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
	/// メンバを初期化する
	/// </summary>
	/// <param name="argSceneChanger">SceneChangerのポインタ</param>
	GameStart(GameScene* argGameScene);
	/// <summary>
	/// メモリを確保していた場合は解放する
	/// </summary>
	virtual ~GameStart();

	/// <summary>
	/// 1ループ内で必要な更新処理を行う
	/// </summary>
	virtual void Update() override;
	/// <summary>
	/// 1ループ内で必要な描画処理を行う
	/// </summary>
	virtual void Draw() override;

private:
	int nowStageNum;
	int numberImage[10];
	int floorImage;

};

