/*****************************************************************************************************
-----�t�@�C���T�v-----
GameState���p��
�X�e�[�W�I���̏��
******************************************************************************************************/

#pragma once

#include "GameState.h"

class ModeSelect : public GameState{

public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	/// <param name="argSceneChanger">SceneChanger�̃|�C���^</param>
	ModeSelect(GameScene* argGameScene);
	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	virtual ~ModeSelect();

	/// <summary>
	/// �X�V�������s��
	/// </summary>
	virtual void Update() override;
	/// <summary>
	/// �`�揈�����s��
	/// </summary>
	virtual void Draw() override;

private:
	//���j���[�p
	typedef enum{
		Mode_Play,
		Mode_Select,
		Mode_Exit,

		Mode_Num,
	}eModeSelect;

private:
	int nowSelectMode;
	int nowStageNum;
	int numberImage[10];
	int backGroundImage;
	int* menuImage;

};

