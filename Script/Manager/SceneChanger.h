/*****************************************************************************************************
-----�t�@�C���T�v-----
�V�[���؂�ւ��s���N���X
******************************************************************************************************/

#pragma once

typedef enum{
	Scene_Title,	//�^�C�g���V�[��
	Scene_Game,		//�Q�[���V�[��
	Scene_Config,	//�ݒ�V�[��
	Scene_Result,

	Scene_End,		//�Q�[���I��
	Scene_Nore,		//����
}e_Scene;

class SceneChanger{

public:
	virtual ~SceneChanger(){};
	virtual void SceneChange(e_Scene nextScene) = 0;

};