#include "ConfigScene.h"
#include "../System/GameInfo.h"
#include <iostream>

C_ConfigScene::C_ConfigScene(C_SceneChanger *argSceneChanger): C_BaseScene(argSceneChanger){
	
	backGroundImage = LoadGraph("Image/Share/BackGround.png");
	gameLevelImage = LoadGraph("Image/Config/ConfigMenuGameLevel.png");
	easyImage = LoadGraph("Image/Config/EasyLevel.png");
	easyContentImage = LoadGraph("Image/Config/EasyLevelContent.png");
	normalImage = LoadGraph("Image/Config/NormalLevel.png");
	normalContentImage = LoadGraph("Image/Config/normalLevelContent.png");
	hardImage = LoadGraph("Image/Config/HardLevel.png");
	hardContentImage = LoadGraph("Image/Config/hardLevelContent.png");
	backImage = LoadGraph("Image/Config/ConfigMenuBack.png");

}

C_ConfigScene::~C_ConfigScene(){
}

void C_ConfigScene::Update(){

#ifdef _DEBUG
	if(C_KeyboardManager::GetInstance().Input(KEY_INPUT_ESCAPE) == 1){
		sceneChanger->SceneChange(Scene_Title);
	}
#endif // _DEBUG

	if(C_KeyboardManager::GetInstance().Input(KEY_INPUT_DOWN) == 1){
		selectMenu = (e_ConfigMenu)((selectMenu + 1) % ConfigMenu_Num);
	}

	if(C_KeyboardManager::GetInstance().Input(KEY_INPUT_UP) == 1){
		selectMenu = (e_ConfigMenu)((selectMenu + (ConfigMenu_Num - 1)) % ConfigMenu_Num);
	}

	if(C_KeyboardManager::GetInstance().Input(KEY_INPUT_SPACE) == 1){
		if(selectMenu == ConfigMenu_Exit){
			sceneChanger->SceneChange(Scene_Title);
		}
	}

	switch(selectMenu){
		case ConfigMenu_GameLevel:
			if(C_KeyboardManager::GetInstance().Input(KEY_INPUT_LEFT) == 1){
				C_GameInfo::GetInstance().DownGameLevel();
			}
			if(C_KeyboardManager::GetInstance().Input(KEY_INPUT_RIGHT) == 1){
				C_GameInfo::GetInstance().UpGameLevel();
			}
			if(C_GameInfo::GetInstance().GetGameLevel() == Level_Hard && C_KeyboardManager::GetInstance().Input(KEY_INPUT_RIGHT) == 60){
				C_GameInfo::GetInstance().ExpertGameLevel();
			}
			break;
	}
	
}

void C_ConfigScene::Draw(){

	DrawGraph(0, 0, backGroundImage, TRUE);

#pragma region Menu
	int gameLevelAlpha(128);
	int exitAlpha(128);

	switch(selectMenu){
		case ConfigMenu_GameLevel:
			gameLevelAlpha = 255;
			break;
		case ConfigMenu_Exit:
			exitAlpha = 255;
			break;
	}

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, gameLevelAlpha);
	DrawGraph(0, 0, gameLevelImage, TRUE);
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, exitAlpha);
	DrawGraph(0, 0, backImage, TRUE);
#pragma endregion

#pragma region GameLevel
	int easyAlpha(128);
	int normalAlpha(128);
	int hardAlpha(128);

	e_GameLevel gameLevel = C_GameInfo::GetInstance().GetGameLevel();

	switch(gameLevel){
		case Level_Easy:
			easyAlpha = 255;
			break;
		case Level_Normal:
			normalAlpha = 255;
			break;
		case Level_Hard:
			hardAlpha = 255;
			break;
	}

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, easyAlpha);
	DrawGraph(0, 0, easyImage, TRUE);
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, normalAlpha);
	DrawGraph(0, 0, normalImage, TRUE);
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, hardAlpha);
	DrawGraph(0, 0, hardImage, TRUE);

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255);
	switch(gameLevel){
		case Level_Easy:
			DrawGraph(0, 0, easyContentImage, TRUE);
			break;
		case Level_Normal:
			DrawGraph(0, 0, normalContentImage, TRUE);
			break;
		case Level_Hard:
			DrawGraph(0, 0, hardContentImage, TRUE);
			break;
	}
#pragma endregion

	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

}