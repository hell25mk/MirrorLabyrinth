/*****************************************************************************************************
-----ファイル概要-----
リザルトシーン
******************************************************************************************************/

#pragma once

#include "../Base/BaseScene.h"

class ResultScene : public BaseScene{

public:
	ResultScene(SceneChanger* argSceneChanger);
	virtual ~ResultScene();
	void Update() override;
	void Draw() override;

private:
	int resultImage;
	int pleaseKeyImage;
	int flashCount;
	bool flashFlag;

};
