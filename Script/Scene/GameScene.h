#pragma once

#include "../Base/BaseScene.h"
#include "../Manager/StageManager.h"

class C_GameScene : public C_BaseScene{

public:
	C_GameScene(C_SceneChanger *argSceneChanger);
	virtual ~C_GameScene();

	void Update() override;
	void Draw() override;

private:
	C_StageManager *stageManager;
	int gameState;

};

