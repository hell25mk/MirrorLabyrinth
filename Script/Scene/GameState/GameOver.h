/*****************************************************************************************************
-----ファイル概要-----
GameStateを継承
ゲームオーバーの状態
******************************************************************************************************/

#pragma once

#include "GameState.h"

class GameOver : public GameState{

public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="argSceneChanger">SceneChangerのポインタ</param>
	GameOver(GameScene* argGameScene);
	/// <summary>
	/// デストラクタ
	/// </summary>
	virtual ~GameOver();

	/// <summary>
	/// 更新処理を行う
	/// </summary>
	virtual void Update() override;
	/// <summary>
	/// 描画処理を行う
	/// </summary>
	virtual void Draw() override;

private:
	int gameOverImage;

};

