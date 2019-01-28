/*****************************************************************************************************
-----�t�@�C���T�v-----
�e�V�[���̊��N���X
******************************************************************************************************/

#pragma once

#include "DxLib.h"
#include "../Manager/SceneChanger.h"
#include "../Manager/KeyboardManager.h"

class BaseScene{

public:
	BaseScene(SceneChanger *argSceneChanger);
	virtual ~BaseScene();
	virtual void Update() = 0;
	virtual void Draw() = 0;

protected:
	SceneChanger* sceneChanger;			//�V�[���؂�ւ��p�|�C���^

};

