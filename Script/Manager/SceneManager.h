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
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	SceneManager();
	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	virtual ~SceneManager();

	/// <summary>
	/// �X�V�������s��
	/// </summary>
	void Update();
	/// <summary>
	/// �`�揈�����s��
	/// </summary>
	void Draw();

	/// <summary>
	/// �V�[���ύX���K�v�ȏꍇ�A�w�肳�ꂽ�V�[���𐶐�����
	/// </summary>
	/// <returns>�ړ��悪Scene_End�ȊO�Ȃ�true</returns>
	bool SceneChange();
	/// <summary>
	/// ���Ɉړ�����V�[�����X�V����
	/// </summary>
	/// <param name="nextScene">�ړ���̃V�[���ԍ�</param>
	void SetNextScene(eSceneType argNextScene) override;
	/// <summary>
	/// ���Ɉړ�����V�[�����擾����
	/// </summary>
	/// <returns></returns>
	int GetNextScene();

private:
	BaseScene* nowScene;
	eSceneType nextScene;
	//std::stack<BaseScene*> stackName;

};

