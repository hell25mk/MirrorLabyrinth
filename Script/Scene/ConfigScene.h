/*****************************************************************************************************
-----ファイル概要-----
設定シーン
難易度とか変更可能
******************************************************************************************************/

#pragma once

#include "../Base/BaseScene.h"

class ConfigScene : public BaseScene{

public:
	/// <summary>
	/// メンバを初期化する
	/// </summary>
	/// <param name="argSceneChanger">SceneChangerのポインタ</param>
	ConfigScene(SceneChanger* argSceneChanger);
	/// <summary>
	/// メモリを確保していた場合は解放する
	/// </summary>
	virtual ~ConfigScene();

	/// <summary>
	/// 1ループ内で必要な更新処理を行う
	/// </summary>
	void Update() override;
	/// <summary>
	/// 1ループ内で必要な描画処理を行う
	/// </summary>
	void Draw() override;

	/// <summary>
	/// 選択されているメニューを更新する
	/// </summary>
	void UpdateMenuSelect();
	/// <summary>
	/// ゲームレベルを更新する
	/// </summary>
	void UpdateGameLevel();
	/// <summary>
	/// メニュー関連を表示する
	/// </summary>
	void DrawMenu();
	/// <summary>
	/// ゲームレベル関連を描画する
	/// </summary>
	void DrawGameLevel();

private:
	//メニュー用
	typedef enum{
		Config_GameLevel,
		Config_Exit,

		Config_Num,
	}eConfigMenu;

private:
	eConfigMenu selectMenu;
	int backGroundImage;
	int* menuImage;
	int* levelImage;
	int* contentImage;

};

