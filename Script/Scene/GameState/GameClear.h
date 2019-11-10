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
	/// メンバを初期化する
	/// </summary>
	/// <param name="argSceneChanger">SceneChangerのポインタ</param>
	GameClear(GameScene* argGameScene);
	/// <summary>
	/// メモリを確保していた場合は解放する
	/// </summary>
	virtual ~GameClear();

	/// <summary>
	/// 1ループ内で必要な更新処理を行う
	/// </summary>
	virtual void Update() override;
	/// <summary>
	/// 1ループ内で必要な描画処理を行う
	/// </summary>
	virtual void Draw() override;

private:
	int gameClearImage;

};

