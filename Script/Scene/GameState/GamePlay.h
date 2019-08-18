/*****************************************************************************************************
-----ファイル概要-----
GameStateを継承
ゲームプレイ中の状態
******************************************************************************************************/

#pragma once

#include "GameState.h"

class Laby;
class Player;
class Mirror;
class Timer;
class GameText;

class GamePlay : public GameState{

public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="argSceneChanger">SceneChangerのポインタ</param>
	GamePlay(GameScene* argGameScene);
	/// <summary>
	/// デストラクタ
	/// </summary>
	virtual ~GamePlay();

	/// <summary>
	/// 更新処理を行う
	/// </summary>
	virtual void Update() override;
	/// <summary>
	/// 描画処理を行う
	/// </summary>
	virtual void Draw() override;

	/// <summary>
	/// ファイルからステージを生成する
	/// </summary>
	void StageCreate();

private:
	Laby* laby;
	Player* player;
	Mirror* mirror;
	Timer* timer;
	GameText* gameText;

};

