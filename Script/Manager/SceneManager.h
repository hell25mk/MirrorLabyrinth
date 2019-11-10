/*****************************************************************************************************
-----ファイル概要-----
シーンの移動や描画を管理するクラス
******************************************************************************************************/

#pragma once

#include "SceneChanger.h"
#include <stack>

class BaseScene;

class SceneManager : public SceneChanger{

public:
	/// <summary>
	/// メンバを初期化する
	/// </summary>
	SceneManager();
	/// <summary>
	/// メモリを確保していた場合は解放する
	/// </summary>
	virtual ~SceneManager();

	/// <summary>
	/// 1ループ内で必要な更新処理を行う
	/// </summary>
	void Update();
	/// <summary>
	/// 1ループ内で必要な描画処理を行う
	/// </summary>
	void Draw();

	/// <summary>
	/// シーン変更が必要な場合、指定されたシーンを生成する
	/// </summary>
	/// <returns>移動先がScene_End以外ならtrue</returns>
	bool SceneChange();
	/// <summary>
	/// 次に移動するシーンを更新する
	/// </summary>
	/// <param name="nextScene">移動先のシーン番号</param>
	void SetNextScene(eSceneType argNextScene) override;
	/// <summary>
	/// 次に移動するシーンを取得する
	/// </summary>
	/// <returns></returns>
	int GetNextScene();

private:
	BaseScene* nowScene;
	eSceneType nextScene;
	//std::stack<BaseScene*> stackName;

};

