#pragma once

#include "../Base/BaseScene.h"

class C_ConfigScene : public C_BaseScene{

public:
	C_ConfigScene(C_SceneChanger *argSceneChanger);
	virtual ~C_ConfigScene();

	void Update() override;
	void Draw() override;

private:
	typedef enum{
		ConfigMenu_GameLevel,
		ConfigMenu_Exit,

		ConfigMenu_Num,
	}e_ConfigMenu;

	e_ConfigMenu selectMenu;
	int backGroundImage;
	int gameLevelImage;
	int easyImage;
	int easyContentImage;
	int normalImage;
	int normalContentImage;
	int hardImage;
	int hardContentImage;
	int backImage;

};

