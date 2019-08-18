#include "ConfigScene.h"
#include "../System/GameInfo.h"
#include "../System/SoundPlayer.h"

/// <summary>
/// コンストラクタ
/// </summary>
/// <param name="argSceneChanger">SceneChangerのポインタ</param>
ConfigScene::ConfigScene(SceneChanger* argSceneChanger) : BaseScene(argSceneChanger),selectMenu(){
	
	//背景画像
	backGroundImage = LoadGraph("Image/Share/BackGround.png");

	//メニュー画面の画像
	menuImage = new int[Config_Num];
	menuImage[Config_GameLevel] = LoadGraph("Image/Config/ConfigMenuGameLevel.png");
	menuImage[Config_Exit] = LoadGraph("Image/Config/ConfigMenuBack.png");

	//難易度の画像
	levelImage = new int[Level_Num];
	levelImage[Level_Easy] = LoadGraph("Image/Config/EasyLevel.png");
	levelImage[Level_Normal] = LoadGraph("Image/Config/NormalLevel.png");
	levelImage[Level_Hard] = LoadGraph("Image/Config/HardLevel.png");

	//難易度の説明画像
	contentImage = new int[Level_Num];
	contentImage[Level_Easy] = LoadGraph("Image/Config/EasyLevelContent.png");
	contentImage[Level_Normal] = LoadGraph("Image/Config/NormalLevelContent.png");
	contentImage[Level_Hard] = LoadGraph("Image/Config/HardLevelContent.png");

}

/// <summary>
/// デストラクタ
/// </summary>
ConfigScene::~ConfigScene(){

	delete[] contentImage;
	delete[] levelImage;
	delete[] menuImage;

}

/// <summary>
/// 更新処理を行う
/// </summary>
void ConfigScene::Update(){

#ifdef _DEBUG
	if(KeyboardManager::GetInstance().Input(KEY_INPUT_ESCAPE) == 1){
		sceneChanger->SetNextScene(Scene_Title);
	}
#endif //ESCでタイトルへ戻る

	UpdateMenuSelect();

	//ゲームレベルを選択していないなら処理を終える
	if (selectMenu != Config_GameLevel) {
		return;
	}

	UpdateGameLevel();
	
}

/// <summary>
///	描画処理を行う
/// </summary>
void ConfigScene::Draw(){

	DrawGraph(0, 0, backGroundImage, TRUE);		//拝啓の描画
	DrawMenu();
	DrawGameLevel();

	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

}

/// <summary>
/// 選択されているメニューを更新する
/// </summary>
void ConfigScene::UpdateMenuSelect() {

	//メニューの上下
	if (KeyboardManager::GetInstance().Input(KEY_INPUT_DOWN) == 1) {
		SoundPlayer::GetInstance().PlaySE("Menu1");
		selectMenu = (eConfigMenu)((selectMenu + 1) % Config_Num);
	}
	if (KeyboardManager::GetInstance().Input(KEY_INPUT_UP) == 1) {
		SoundPlayer::GetInstance().PlaySE("Menu1");
		selectMenu = (eConfigMenu)((selectMenu + (Config_Num - 1)) % Config_Num);
	}

	//メニューの選択
	if (KeyboardManager::GetInstance().Input(KEY_INPUT_SPACE) == 1) {
		if (selectMenu == Config_Exit) {
			SoundPlayer::GetInstance().PlaySE("Menu2");
			sceneChanger->SetNextScene(Scene_Title);
		}
	}

}

/// <summary>
/// ゲームレベルを更新する
/// </summary>
void ConfigScene::UpdateGameLevel() {

	//ゲームレベルの選択
	if (KeyboardManager::GetInstance().Input(KEY_INPUT_LEFT) == 1) {
		SoundPlayer::GetInstance().PlaySE("Menu1");
		GameInfo::GetInstance().DownGameLevel();
	}
	if (KeyboardManager::GetInstance().Input(KEY_INPUT_RIGHT) == 1) {
		SoundPlayer::GetInstance().PlaySE("Menu1");
		GameInfo::GetInstance().UpGameLevel();
	}

	/*switch(selectMenu){
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
	}*/

}

/// <summary>
/// メニュー関連を表示する
/// </summary>
void ConfigScene::DrawMenu(){

	int drawAlpha[2] = { 128,128 };

	drawAlpha[selectMenu] = 255;

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, drawAlpha[Config_GameLevel]);
	DrawGraph(0, 0, menuImage[Config_GameLevel], TRUE);
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, drawAlpha[Config_Exit]);
	DrawGraph(0, 0, menuImage[Config_Exit], TRUE);

}

/// <summary>
/// ゲームレベル関連を描画する
/// </summary>
void ConfigScene::DrawGameLevel(){

	int drawAlpha[3] = { 128,128,128 };
	eGameLevel gameLevel = GameInfo::GetInstance().GetGameLevel();

	//現在選択されているゲームレベルの透明度を最大にする(透過させない)
	drawAlpha[gameLevel] = 255;

	//各レベルの画像を表示する(選択されているレベル以外は薄く表示される)
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, drawAlpha[Level_Easy]);
	DrawGraph(0, 0, levelImage[Level_Easy], TRUE);
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, drawAlpha[Level_Normal]);
	DrawGraph(0, 0, levelImage[Level_Normal], TRUE);
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, drawAlpha[Level_Hard]);
	DrawGraph(0, 0, levelImage[Level_Hard], TRUE);

	//レベルの説明テキストを表示する
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255);
	DrawGraph(0, 0, contentImage[gameLevel], TRUE);

}