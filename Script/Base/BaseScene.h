/*****************************************************************************************************
-----ファイル概要-----
各シーンの基底クラス
******************************************************************************************************/

#pragma once

#include "DxLib.h"
#include "../Manager/SceneChanger.h"
#include "../Manager/KeyboardManager.h"

class BaseScene{

public:
	/// <summary>
	/// メンバを初期化する
	/// </summary>
	/// <param name="argSceneChanger">SceneChangerのポインタ</param>
	BaseScene(SceneChanger* argSceneChanger);
	/// <summary>
	/// メモリを確保していた場合は解放する
	/// </summary>
	virtual ~BaseScene();

	/// <summary>
	/// 1ループ内で必要な更新処理を行う
	/// </summary>
	virtual void Update() = 0;
	/// <summary>
	/// 1ループ内で必要な描画処理を行う
	/// </summary>
	virtual void Draw() = 0;

protected:
	SceneChanger* sceneChanger;			//シーン切り替え用ポインタ

};

