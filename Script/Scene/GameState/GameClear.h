/*****************************************************************************************************
-----�t�@�C���T�v-----
GameState���p��
�Q�[���N���A�̏��
******************************************************************************************************/

#pragma once

#include "GameState.h"

class GameClear : public GameState{

public:
	/// <summary>
	/// �����o������������
	/// </summary>
	/// <param name="argSceneChanger">SceneChanger�̃|�C���^</param>
	GameClear(GameScene* argGameScene);
	/// <summary>
	/// ���������m�ۂ��Ă����ꍇ�͉������
	/// </summary>
	virtual ~GameClear();

	/// <summary>
	/// 1���[�v���ŕK�v�ȍX�V�������s��
	/// </summary>
	virtual void Update() override;
	/// <summary>
	/// 1���[�v���ŕK�v�ȕ`�揈�����s��
	/// </summary>
	virtual void Draw() override;

private:
	int gameClearImage;

};

