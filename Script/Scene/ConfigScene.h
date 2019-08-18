/*****************************************************************************************************
-----�t�@�C���T�v-----
�ݒ�V�[��
��Փx�Ƃ��ύX�\
******************************************************************************************************/

#pragma once

#include "../Base/BaseScene.h"

class ConfigScene : public BaseScene{

public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	/// <param name="argSceneChanger">SceneChanger�̃|�C���^</param>
	ConfigScene(SceneChanger* argSceneChanger);
	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	virtual ~ConfigScene();

	/// <summary>
	/// �X�V�������s��
	/// </summary>
	void Update() override;
	/// <summary>
	/// �`�揈�����s��
	/// </summary>
	void Draw() override;

	/// <summary>
	/// �I������Ă��郁�j���[���X�V����
	/// </summary>
	void UpdateMenuSelect();
	/// <summary>
	/// �Q�[�����x�����X�V����
	/// </summary>
	void UpdateGameLevel();
	/// <summary>
	/// ���j���[�֘A��\������
	/// </summary>
	void DrawMenu();
	/// <summary>
	/// �Q�[�����x���֘A��`�悷��
	/// </summary>
	void DrawGameLevel();

private:
	//���j���[�p
	typedef enum{
		Config_GameLevel,
		Config_Exit,

		Config_Num,
	}eConfigMenu;

private:
	eConfigMenu selectMenu;
	int backGroundImage;
	int* menuImage;
	int* levelImage;
	int* contentImage;

};

