/*****************************************************************************************************
-----�t�@�C���T�v-----
GameState���p��
�Q�[���̏�Ԃ̊��N���X
******************************************************************************************************/

#pragma once

#include "GameState.h"

class GameStart : public GameState{

public:
	/// <summary>
	/// �����o������������
	/// </summary>
	/// <param name="argSceneChanger">SceneChanger�̃|�C���^</param>
	GameStart(GameScene* argGameScene);
	/// <summary>
	/// ���������m�ۂ��Ă����ꍇ�͉������
	/// </summary>
	virtual ~GameStart();

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
	int floorImage;

};

