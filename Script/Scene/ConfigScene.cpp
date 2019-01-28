#include "ConfigScene.h"
#include "../System/GameInfo.h"
#include "../System/SoundPlayer.h"

ConfigScene::ConfigScene(SceneChanger *argSceneChanger): BaseScene(argSceneChanger){
	
	backGroundImage = LoadGraph("Image/Share/BackGround.png");

	menuImage = new int[Config_Num];
	menuImage[Config_GameLevel] = LoadGraph("Image/Config/ConfigMenuGameLevel.png");
	menuImage[Config_Exit] = LoadGraph("Image/Config/ConfigMenuBack.png");

	levelImage = new int[Level_Num];
	levelImage[Level_Easy] = LoadGraph("Image/Config/EasyLevel.png");
	levelImage[Level_Normal] = LoadGraph("Image/Config/NormalLevel.png");
	levelImage[Level_Hard] = LoadGraph("Image/Config/HardLevel.png");

	contentImage = new int[Level_Num];
	contentImage[Level_Easy] = LoadGraph("Image/Config/EasyLevelContent.png");
	contentImage[Level_Normal] = LoadGraph("Image/Config/NormalLevelContent.png");
	contentImage[Level_Hard] = LoadGraph("Image/Config/HardLevelContent.png");

}

ConfigScene::~ConfigScene(){

	delete[] contentImage;
	delete[] levelImage;
	delete[] menuImage;

}

void ConfigScene::Update(){

#ifdef _DEBUG
	if(KeyboardManager::GetInstance().Input(KEY_INPUT_ESCAPE) == 1){
		sceneChanger->SceneChange(Scene_Title);
	}
#endif // _DEBUG

	if(KeyboardManager::GetInstance().Input(KEY_INPUT_DOWN) == 1){
		SoundPlayer::GetInstance().PlaySE("Menu1");
		selectMenu = (e_ConfigMenu)((selectMenu + 1) % Config_Num);
	}

	if(KeyboardManager::GetInstance().Input(KEY_INPUT_UP) == 1){
		SoundPlayer::GetInstance().PlaySE("Menu1");
		selectMenu = (e_ConfigMenu)((selectMenu + (Config_Num - 1)) % Config_Num);
	}

	if(KeyboardManager::GetInstance().Input(KEY_INPUT_SPACE) == 1){
		if(selectMenu == Config_Exit){
			SoundPlayer::GetInstance().PlaySE("Menu2");
			sceneChanger->SceneChange(Scene_Title);
		}
	}

	switch(selectMenu){
		case Config_GameLevel:
			if(KeyboardManager::GetInstance().Input(KEY_INPUT_LEFT) == 1){
				SoundPlayer::GetInstance().PlaySE("Menu1");
				GameInfo::GetInstance().DownGameLevel();
			}
			if(KeyboardManager::GetInstance().Input(KEY_INPUT_RIGHT) == 1){
				SoundPlayer::GetInstance().PlaySE("Menu1");
				GameInfo::GetInstance().UpGameLevel();
			}
			break;
	}
	
}

void ConfigScene::Draw(){

	DrawGraph(0, 0, backGroundImage, TRUE);
	Menu();
	GameLevel();

	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

}

void ConfigScene::Menu(){

	int drawAlpha[2] = { 128,128 };

	drawAlpha[selectMenu] = 255;

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, drawAlpha[Config_GameLevel]);
	DrawGraph(0, 0, menuImage[Config_GameLevel], TRUE);
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, drawAlpha[Config_Exit]);
	DrawGraph(0, 0, menuImage[Config_Exit], TRUE);

}

void ConfigScene::GameLevel(){

	int drawAlpha[3] = { 128,128,128 };
	e_GameLevel gameLevel = GameInfo::GetInstance().GetGameLevel();

	drawAlpha[gameLevel] = 255;

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, drawAlpha[Level_Easy]);
	DrawGraph(0, 0, levelImage[Level_Easy], TRUE);
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, drawAlpha[Level_Normal]);
	DrawGraph(0, 0, levelImage[Level_Normal], TRUE);
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, drawAlpha[Level_Hard]);
	DrawGraph(0, 0, levelImage[Level_Hard], TRUE);

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255);
	DrawGraph(0, 0, contentImage[gameLevel], TRUE);

}