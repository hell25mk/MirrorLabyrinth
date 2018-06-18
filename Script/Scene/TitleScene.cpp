#include "TitleScene.h"
#include "../System/SoundPlayer.h"

C_TitleScene::C_TitleScene(C_SceneChanger *argSceneChanger):C_BaseScene(argSceneChanger){

	C_SoundPlayer::GetInstance().PlayBGM("Title");

	backGroundImage = LoadGraph("Image/Share/BackGround.png");
	titleImage = LoadGraph("Image/Title/Title.png");
	startImage = LoadGraph("Image/Title/TitleMenuStart.png");
	configImage = LoadGraph("Image/Title/TitleMenuConfig.png");
	exitImage = LoadGraph("Image/Title/TitleMenuExit.png");

	selectMenu = TitleMenu_Start;

}

C_TitleScene::~C_TitleScene(){
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
		selectMenu = (e_TitleMenu)((selectMenu + 1) % TitleMenu_Num);
	}

	if(C_KeyboardManager::GetInstance().Input(KEY_INPUT_UP) == 1){
		selectMenu = (e_TitleMenu)((selectMenu + (TitleMenu_Num - 1)) % TitleMenu_Num);
	}

	if(C_KeyboardManager::GetInstance().Input(KEY_INPUT_SPACE) == 1){
		switch(selectMenu){
			case TitleMenu_Start:
				C_SoundPlayer::GetInstance().StopBGM();
				sceneChanger->SceneChange(Scene_Game);
				break;
			case TitleMenu_Config:
				sceneChanger->SceneChange(Scene_Config);
				break;
			case TitleMenu_Exit:
				sceneChanger->SceneChange(Scene_End);
				break;
		}
	}

}

void C_TitleScene::Draw(){

	DrawGraph(0, 0, backGroundImage, TRUE);
	
	//ƒ^ƒCƒgƒ‹
	DrawGraph(0, 0, titleImage,TRUE);

	int startAlpha(128);
	int configAlpha(128);
	int exitAlpha(128);

	switch(selectMenu){
		case TitleMenu_Start:
			startAlpha = 255;
			break;
		case TitleMenu_Config:
			configAlpha = 255;
			break;
		case TitleMenu_Exit:
			exitAlpha = 255;
			break;
	}

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, startAlpha);
	DrawGraph(0, 0, startImage, TRUE);
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, configAlpha);
	DrawGraph(0, 0, configImage, TRUE);
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, exitAlpha);
	DrawGraph(0, 0, exitImage, TRUE);

	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

}