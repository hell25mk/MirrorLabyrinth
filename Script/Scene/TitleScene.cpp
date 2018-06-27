#include "TitleScene.h"
#include "../System/SoundPlayer.h"

C_TitleScene::C_TitleScene(C_SceneChanger *argSceneChanger):C_BaseScene(argSceneChanger){

	C_SoundPlayer::GetInstance().PlayBGM("Title");

	backGroundImage = LoadGraph("Image/Share/BackGround.png");
	titleImage = LoadGraph("Image/Title/Title.png");

	menuImage = new int[Title_Num];
	menuImage[Title_Start] = LoadGraph("Image/Title/TitleMenuStart.png");
	menuImage[Title_Config] = LoadGraph("Image/Title/TitleMenuConfig.png");
	menuImage[Title_Exit] = LoadGraph("Image/Title/TitleMenuExit.png");

	selectMenu = Title_Start;

}

C_TitleScene::~C_TitleScene(){

	delete[] menuImage;

}

void C_TitleScene::Update(){

#ifdef _DEBUG
	if(C_KeyboardManager::GetInstance().Input(KEY_INPUT_ESCAPE) == 1){
		sceneChanger->SceneChange(Scene_End);
}

	if(C_KeyboardManager::GetInstance().Input(KEY_INPUT_A) == 1){
		sceneChanger->SceneChange(Scene_Game);
	}
#endif // DEBUG

	if(C_KeyboardManager::GetInstance().Input(KEY_INPUT_DOWN) == 1){
		selectMenu = (e_TitleMenu)((selectMenu + 1) % Title_Num);
	}

	if(C_KeyboardManager::GetInstance().Input(KEY_INPUT_UP) == 1){
		selectMenu = (e_TitleMenu)((selectMenu + (Title_Num - 1)) % Title_Num);
	}

	if(C_KeyboardManager::GetInstance().Input(KEY_INPUT_SPACE) == 1){
		switch(selectMenu){
			case Title_Start:
				sceneChanger->SceneChange(Scene_Game);
				break;
			case Title_Config:
				sceneChanger->SceneChange(Scene_Config);
				break;
			case Title_Exit:
				sceneChanger->SceneChange(Scene_End);
				break;
		}
	}

}

void C_TitleScene::Draw(){

	//”wŒi
	DrawGraph(0, 0, backGroundImage, TRUE);
	//ƒ^ƒCƒgƒ‹
	DrawGraph(0, 0, titleImage,TRUE);

	int drawAlpha[Title_Num] = { 128,128,128 };

	drawAlpha[selectMenu] = 255;

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, drawAlpha[Title_Start]);
	DrawGraph(0, 0, menuImage[Title_Start], TRUE);
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, drawAlpha[Title_Config]);
	DrawGraph(0, 0, menuImage[Title_Config], TRUE);
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, drawAlpha[Title_Exit]);
	DrawGraph(0, 0, menuImage[Title_Exit], TRUE);

	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

}