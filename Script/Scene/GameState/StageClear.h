/*****************************************************************************************************
-----�t�@�C���T�v-----
GameState���p��
�X�e�[�W�N���A�̏��
******************************************************************************************************/

#pragma once

#include "GameState.h"

class StageClear : public GameState{

public:
	/// <summary>
	/// �����o������������
	/// </summary>
	/// <param name="argSceneChanger">SceneChanger�̃|�C���^</param>
	StageClear(GameScene* argGameScene);
	/// <summary>
	/// ���������m�ۂ��Ă����ꍇ�͉������
	/// </summary>
	virtual ~StageClear();

	/// <summary>
	/// 1���[�v���ŕK�v�ȍX�V�������s��
	/// </summary>
	virtual void Update() override;
	/// <summary>
	/// 1���[�v���ŕK�v�ȕ`�揈�����s��
	/// </summary>
	virtual void Draw() override;

private:
	int nowStageNum;
	int numberImage[10];
	int stageClearImage;

};

