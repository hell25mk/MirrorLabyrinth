#pragma once

#include "../Base/BaseScene.h"

class C_ResultScene : public C_BaseScene{

public:
	C_ResultScene(C_SceneChanger *argSceneChanger);
	virtual ~C_ResultScene();

	void Update() override;
	void Draw() override;

private:
	int resultImage;
	int pleaseKeyImage;

	int flashCount;
	bool flashFlag;

};
