#pragma once

#include "../Base/BaseScene.h"

class C_ConfigScene : public C_BaseScene{

public:
	C_ConfigScene(C_SceneChanger *argSceneChanger);
	virtual ~C_ConfigScene();
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
	int *menuImage;
	int *levelImage;
	int *contentImage;

};

