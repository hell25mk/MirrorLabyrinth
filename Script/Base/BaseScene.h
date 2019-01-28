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
	BaseScene(SceneChanger *argSceneChanger);
	virtual ~BaseScene();
	virtual void Update() = 0;
	virtual void Draw() = 0;

protected:
	SceneChanger* sceneChanger;			//シーン切り替え用ポインタ

};

