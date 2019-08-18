/*****************************************************************************************************
-----�t�@�C���T�v-----
�^�C�g���V�[��
******************************************************************************************************/

#pragma once

#include "../Base/BaseScene.h"

class TitleScene : public BaseScene{

public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	/// <param name="argSceneChanger">SceneChanger�̃|�C���^</param>
	TitleScene(SceneChanger* argSceneChanger);
	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	virtual ~TitleScene();

	/// <summary>
	/// �X�V�������s��
	/// </summary>
	void Update() override;
	/// <summary>
	/// �`�揈�����s��
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

