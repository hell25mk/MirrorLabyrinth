/*****************************************************************************************************
-----ファイル概要-----
タイトルシーン
******************************************************************************************************/

#pragma once

#include "../Base/BaseScene.h"

class TitleScene : public BaseScene{

public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="argSceneChanger">SceneChangerのポインタ</param>
	TitleScene(SceneChanger* argSceneChanger);
	/// <summary>
	/// デストラクタ
	/// </summary>
	virtual ~TitleScene();

	/// <summary>
	/// 更新処理を行う
	/// </summary>
	void Update() override;
	/// <summary>
	/// 描画処理を行う
	/// </summary>
	void Draw() override;

private:
	//メニュー用
	typedef enum{
		Title_Start,
		Title_Config,
		Title_Exit,

		Title_Num,
	}eTitleMenu;

private:
	eTitleMenu selectMenu;
	int backGroundImage;
	int titleImage;
	int* menuImage;

};

