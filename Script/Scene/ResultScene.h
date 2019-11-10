/*****************************************************************************************************
-----ファイル概要-----
リザルトシーン
******************************************************************************************************/

#pragma once

#include "../Base/BaseScene.h"

class ResultScene : public BaseScene{

public:
	/// <summary>
	/// メンバを初期化する
	/// </summary>
	/// <param name="argSceneChanger">SceneChangerのポインタ</param>
	ResultScene(SceneChanger* argSceneChanger);
	/// <summary>
	/// メモリを確保していた場合は解放する
	/// </summary>
	virtual ~ResultScene();

	/// <summary>
	/// 1ループ内で必要な更新処理を行う
	/// </summary>
	void Update() override;
	/// <summary>
	/// 1ループ内で必要な描画処理を行う
	/// </summary>
	void Draw() override;

private:
	int resultImage;
	int pleaseKeyImage;
	int flashCount;
	bool willFlash;

};
