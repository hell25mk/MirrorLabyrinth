/*****************************************************************************************************
-----ファイル概要-----
タイトルシーン
******************************************************************************************************/

#pragma once

#include "../Base/BaseScene.h"

class TitleScene : public BaseScene{

public:
	TitleScene(SceneChanger* argSceneChanger);
	virtual ~TitleScene();
	void Update() override;
	void Draw() override;

private:
	typedef enum{
		Title_Start,
		Title_Config,
		Title_Exit,

		Title_Num,
	}e_TitleMenu;

private:
	e_TitleMenu selectMenu;
	int backGroundImage;
	int titleImage;
	int* menuImage;

};

