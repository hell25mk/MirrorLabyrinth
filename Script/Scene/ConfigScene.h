/*****************************************************************************************************
-----ファイル概要-----
設定シーン
難易度とか変更可能
******************************************************************************************************/

#pragma once

#include "../Base/BaseScene.h"

class ConfigScene : public BaseScene{

public:
	ConfigScene(SceneChanger* argSceneChanger);
	virtual ~ConfigScene();
	void Update() override;
	void Draw() override;
	void Menu();
	void GameLevel();

private:
	typedef enum{
		Config_GameLevel,
		Config_Exit,

		Config_Num,
	}e_ConfigMenu;

private:
	e_ConfigMenu selectMenu;
	int backGroundImage;
	int* menuImage;
	int* levelImage;
	int* contentImage;

};

