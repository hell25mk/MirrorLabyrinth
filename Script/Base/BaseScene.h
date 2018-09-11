/*****************************************************************************************************
-----�t�@�C���T�v-----
�e�V�[���̊��N���X
******************************************************************************************************/

#pragma once

#include "DxLib.h"
#include "../Manager/SceneChanger.h"
#include "../Manager/KeyboardManager.h"

class C_BaseScene{

public:
	C_BaseScene(C_SceneChanger *argSceneChanger);
	virtual ~C_BaseScene();
	virtual void Update() = 0;
	virtual void Draw() = 0;

protected:
	C_SceneChanger *sceneChanger;			//�V�[���؂�ւ��p�|�C���^

};

