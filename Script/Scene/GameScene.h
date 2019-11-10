/*****************************************************************************************************
-----ファイル概要-----
ゲームシーン
ゲーム状態を管理
******************************************************************************************************/

#pragma once

#include "../Base/BaseScene.h"

class GameState;

class GameScene : public BaseScene{

public:
	/// <summary>
	/// メンバを初期化する
	/// </summary>
	/// <param name="argSceneChanger">SceneChangerのポインタ</param>
	GameScene(SceneChanger* argSceneChanger);
	/// <summary>
	/// メモリを確保していた場合は解放する
	/// </summary>
	virtual ~GameScene();

	/// <summary>
	/// 1ループ内で必要な更新処理を行う
	/// </summary>
	virtual void Update() override;
	/// <summary>
	/// 1ループ内で必要な描画処理を行う
	/// </summary>
	virtual void Draw() override;

	/// <summary>
	/// ゲームの状態に合わせたクラスを生成する
	/// </summary>
	/// <param name="argGameState"></param>
	void SetGameState(int argGameState);
	/// <summary>
	/// 次に移動するシーンを更新する
	/// </summary>
	/// <param name="nextScene">移動先のシーン番号</param>
	void NextScene(int argNextScene);
	/// <summary>
	/// 現在のステージ数を更新する
	/// </summary>
	/// <param name="argStageNum">到達したステージ数</param>
	void SetStageNum(int argStageNum);
	/// <summary>
	/// 現在のステージ数を取得する
	/// </summary>
	/// <returns>現在のステージ数</returns>
	int GetStageNum();

public:
	static const int Max_Stage_Num;
	static const int Laby_Height;
	static const int Laby_Width;
	//ゲームシーンの状態管理用
	typedef enum{
		State_ModeSelect,
		State_GameStart,
		State_GamePlay,
		State_StageClear,
		State_GameClear,
		State_GameOver,
		State_Result,

		State_Nore,
	}eGameState;

private:
	GameState* gameState;
	int nowStageNum;

};

