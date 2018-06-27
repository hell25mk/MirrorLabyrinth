#pragma once

#include "../Base/BaseScene.h"

class C_TitleScene : public C_BaseScene{

public:
	C_TitleScene(C_SceneChanger *argSceneChanger);
	virtual ~C_TitleScene();
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
	int *menuImage;

};

