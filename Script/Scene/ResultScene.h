/*****************************************************************************************************
-----ファイル概要-----
リザルトシーン
******************************************************************************************************/

#pragma once

#include "../Base/BaseScene.h"

class ResultScene : public BaseScene{

public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="argSceneChanger">SceneChangerのポインタ</param>
	ResultScene(SceneChanger* argSceneChanger);
	/// <summary>
	/// デストラクタ
	/// </summary>
	virtual ~ResultScene();

	/// <summary>
	/// 更新処理を行う
	/// </summary>
	void Update() override;
	/// <summary>
	/// 描画処理を行う
	/// </summary>
	void Draw() override;

private:
	int resultImage;
	int pleaseKeyImage;
	int flashCount;
	bool willFlash;

};
