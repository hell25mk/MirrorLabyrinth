#pragma once

#include "SceneChanger.h"
#include <stack>

class C_BaseScene;

class C_SceneManager : public C_SceneChanger{

public:
	C_SceneManager();
	virtual ~C_SceneManager();
	void Update();
	void Draw();
	void SceneChange(e_Scene argNextScene) override;
	int GetNextScene();

	void MusicInit();

private:
	C_BaseScene *nowScene;
	e_Scene nextScene;
	std::stack<C_BaseScene*> stackName;

};

