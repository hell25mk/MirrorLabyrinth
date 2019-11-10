/*****************************************************************************************************
-----ファイル概要-----
ゲーム全体を管理するクラス
Mainではこのクラスのみを生成する
******************************************************************************************************/

#pragma once

#include "../System/Singleton.h"

class SceneManager;

class GameManager : public Singleton<GameManager>{

public:
	friend class Singleton<GameManager>;
	/// <summary>
	/// 初期化処理を行う
	/// </summary>
	virtual void Create() override;
	/// <summary>
	/// 終了処理を行う
	/// </summary>
	virtual void Destroy() override;

	/// <summary>
	/// 1ループ内で必要な更新処理を行う
	/// </summary>
	/// <returns>シーンの移動先がScene_End以外だった場合trueを返す</returns>
	bool Update();
	/// <summary>
	/// 1ループ内で必要な描画処理を行う
	/// </summary>
	void Draw();

protected:
	GameManager() : sceneManager(){ }
	virtual ~GameManager(){ }

private:
	SceneManager* sceneManager;

};

