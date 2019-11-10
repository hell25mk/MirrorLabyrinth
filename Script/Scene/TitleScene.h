/*****************************************************************************************************
-----�t�@�C���T�v-----
�^�C�g���V�[��
******************************************************************************************************/

#pragma once

#include "../Base/BaseScene.h"

class TitleScene : public BaseScene{

public:
	/// <summary>
	/// �����o������������
	/// </summary>
	/// <param name="argSceneChanger">SceneChanger�̃|�C���^</param>
	TitleScene(SceneChanger* argSceneChanger);
	/// <summary>
	/// ���������m�ۂ��Ă����ꍇ�͉������
	/// </summary>
	virtual ~TitleScene();

	/// <summary>
	/// 1���[�v���ŕK�v�ȍX�V�������s��
	/// </summary>
	void Update() override;
	/// <summary>
	/// 1���[�v���ŕK�v�ȕ`�揈�����s��
	/// </summary>
	void Draw() override;

private:
	//���j���[�p
	typedef enum{
		Title_Start,
		Title_Config,
		Title_Exit,

		Title_Num,
	}eTitleMenu;

private:
	eTitleMenu selectMenu;
	int backGroundImage;
	int titleImage;
	int* menuImage;

};

