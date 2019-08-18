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
	/// �R���X�g���N�^
	/// </summary>
	/// <param name="argSceneChanger">SceneChanger�̃|�C���^</param>
	StageClear(GameScene* argGameScene);
	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	virtual ~StageClear();

	/// <summary>
	/// �X�V�������s��
	/// </summary>
	virtual void Update() override;
	/// <summary>
	/// �`�揈�����s��
	/// </summary>
	virtual void Draw() override;

private:
	int nowStageNum;
	int numberImage[10];
	int stageClearImage;

};

