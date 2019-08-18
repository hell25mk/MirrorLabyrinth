/*****************************************************************************************************
-----ファイル概要-----
GameStateを継承
ゲームクリアの状態
******************************************************************************************************/

#pragma once

#include "GameState.h"

class GameClear : public GameState{

public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="argSceneChanger">SceneChangerのポインタ</param>
	GameClear(GameScene* argGameScene);
	/// <summary>
	/// デストラクタ
	/// </summary>
	virtual ~GameClear();

	/// <summary>
	/// 更新処理を行う
	/// </summary>
	virtual void Update() override;
	/// <summary>
	/// 描画処理を行う
	/// </summary>
	virtual void Draw() override;

private:
	int gameClearImage;

};

