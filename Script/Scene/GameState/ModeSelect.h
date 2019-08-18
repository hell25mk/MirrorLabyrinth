/*****************************************************************************************************
-----ファイル概要-----
GameStateを継承
ステージ選択の状態
******************************************************************************************************/

#pragma once

#include "GameState.h"

class ModeSelect : public GameState{

public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="argSceneChanger">SceneChangerのポインタ</param>
	ModeSelect(GameScene* argGameScene);
	/// <summary>
	/// デストラクタ
	/// </summary>
	virtual ~ModeSelect();

	/// <summary>
	/// 更新処理を行う
	/// </summary>
	virtual void Update() override;
	/// <summary>
	/// 描画処理を行う
	/// </summary>
	virtual void Draw() override;

private:
	//メニュー用
	typedef enum{
		Mode_Play,
		Mode_Select,
		Mode_Exit,

		Mode_Num,
	}eModeSelect;

private:
	int nowSelectMode;
	int nowStageNum;
	int numberImage[10];
	int backGroundImage;
	int* menuImage;

};

