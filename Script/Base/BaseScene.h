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
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	/// <param name="argSceneChanger">SceneChanger�̃|�C���^</param>
	BaseScene(SceneChanger* argSceneChanger);
	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	virtual ~BaseScene();

	/// <summary>
	/// �X�V�������s��
	/// </summary>
	virtual void Update() = 0;
	/// <summary>
	/// �`�揈�����s��
	/// </summary>
	virtual void Draw() = 0;

protected:
	SceneChanger* sceneChanger;			//�V�[���؂�ւ��p�|�C���^

};

