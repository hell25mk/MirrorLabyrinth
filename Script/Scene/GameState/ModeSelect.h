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
	/// �����o������������
	/// </summary>
	/// <param name="argSceneChanger">SceneChanger�̃|�C���^</param>
	ModeSelect(GameScene* argGameScene);
	/// <summary>
	/// ���������m�ۂ��Ă����ꍇ�͉������
	/// </summary>
	virtual ~ModeSelect();

	/// <summary>
	/// 1���[�v���ŕK�v�ȍX�V�������s��
	/// </summary>
	virtual void Update() override;
	/// <summary>
	/// 1���[�v���ŕK�v�ȕ`�揈�����s��
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

