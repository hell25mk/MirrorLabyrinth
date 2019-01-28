/*****************************************************************************************************
-----�t�@�C���T�v-----
�V�[���̈ړ���`����Ǘ�����N���X
******************************************************************************************************/

#pragma once

#include "SceneChanger.h"
#include <stack>

class BaseScene;

class SceneManager : public SceneChanger{

public:
	SceneManager();
	virtual ~SceneManager();
	void Update();
	void Draw();
	void SceneChange(e_Scene argNextScene) override;
	int GetNextScene();

private:
	BaseScene* nowScene;
	e_Scene nextScene;
	std::stack<BaseScene*> stackName;

};

