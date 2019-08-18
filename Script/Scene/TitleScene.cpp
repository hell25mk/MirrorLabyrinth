#include "TitleScene.h"
#include "../System/SoundPlayer.h"

/// <summary>
/// コンストラクタ
/// </summary>
/// <param name="argSceneChanger">SceneChangerのポインタ</param>
TitleScene::TitleScene(SceneChanger *argSceneChanger):BaseScene(argSceneChanger){

	SoundPlayer::GetInstance().PlayBGM("Title");

	backGroundImage = LoadGraph("Image/Share/BackGround.png");
	titleImage = LoadGraph("Image/Title/Title.png");

	menuImage = new int[Title_Num];
	menuImage[Title_Start] = LoadGraph("Image/Title/TitleMenuStart.png");
	menuImage[Title_Config] = LoadGraph("Image/Title/TitleMenuConfig.png");
	menuImage[Title_Exit] = LoadGraph("Image/Title/TitleMenuExit.png");

	selectMenu = Title_Start;

}

/// <summary>
/// デストラクタ
/// </summary>
TitleScene::~TitleScene(){

	delete[] menuImage;

}

/// <summary>
/// 更新処理を行う
/// </summary>
void TitleScene::Update(){

#ifdef _DEBUG
	if(KeyboardManager::GetInstance().Input(KEY_INPUT_ESCAPE) == 1){
		sceneChanger->SetNextScene(Scene_End);
	}

	if(KeyboardManager::GetInstance().Input(KEY_INPUT_A) == 1){
		sceneChanger->SetNextScene(Scene_Game);
	}
#endif //ESCでゲーム終了、Aでゲームシーンへ移動

	//メニューの上下
	if(KeyboardManager::GetInstance().Input(KEY_INPUT_DOWN) == 1){
		SoundPlayer::GetInstance().PlaySE("Menu1");
		selectMenu = (eTitleMenu)((selectMenu + 1) % Title_Num);
	}
	if(KeyboardManager::GetInstance().Input(KEY_INPUT_UP) == 1){
		SoundPlayer::GetInstance().PlaySE("Menu1");
		selectMenu = (eTitleMenu)((selectMenu + (Title_Num - 1)) % Title_Num);
	}

	//メニューの選択
	if(KeyboardManager::GetInstance().Input(KEY_INPUT_SPACE) == 1){
		SoundPlayer::GetInstance().PlaySE("Menu2");
		//選択されたメニューによってシーンを切り替える
		switch(selectMenu){
			case Title_Start:
				sceneChanger->SetNextScene(Scene_Game);
				break;
			case Title_Config:
				sceneChanger->SetNextScene(Scene_Config);
				break;
			case Title_Exit:
				sceneChanger->SetNextScene(Scene_End);
				break;
		}
	}

}

/// <summary>
/// 描画処理を行う
/// </summary>
void TitleScene::Draw(){

	//背景
	DrawGraph(0, 0, backGroundImage, TRUE);
	//タイトル
	DrawGraph(0, 0, titleImage,TRUE);

	int drawAlpha[Title_Num] = { 128,128,128 };

	//選択されているメニュー以外は薄く表示する
	drawAlpha[selectMenu] = 255;
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, drawAlpha[Title_Start]);
	DrawGraph(0, 0, menuImage[Title_Start], TRUE);
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, drawAlpha[Title_Config]);
	DrawGraph(0, 0, menuImage[Title_Config], TRUE);
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, drawAlpha[Title_Exit]);
	DrawGraph(0, 0, menuImage[Title_Exit], TRUE);

	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

}