/*****************************************************************************************************
-----�t�@�C���T�v-----
�V�[���؂�ւ��s���N���X
******************************************************************************************************/

#pragma once

typedef enum{
	Scene_Title,	//�^�C�g���V�[��
	Scene_Game,		//�Q�[���V�[��
	Scene_Config,	//�ݒ�V�[��
	Scene_Result,	//���U���g�V�[��

	Scene_End,		//�Q�[���I��
	Scene_None,		//����
}eSceneType;

class SceneChanger{

public:
	virtual ~SceneChanger(){};

	/// <summary>
	/// ���Ɉړ�����V�[�����X�V����
	/// </summary>
	/// <param name="nextScene">�ړ���̃V�[���ԍ�</param>
	virtual void SetNextScene(eSceneType nextScene) = 0;

};