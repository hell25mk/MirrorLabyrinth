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
	/// コンストラクタ
	/// </summary>
	/// <param name="argSceneChanger">SceneChangerのポインタ</param>
	BaseScene(SceneChanger* argSceneChanger);
	/// <summary>
	/// デストラクタ
	/// </summary>
	virtual ~BaseScene();

	/// <summary>
	/// 更新処理を行う
	/// </summary>
	virtual void Update() = 0;
	/// <summary>
	/// 描画処理を行う
	/// </summary>
	virtual void Draw() = 0;

protected:
	SceneChanger* sceneChanger;			//シーン切り替え用ポインタ

};

