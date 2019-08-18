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
	/// �R���X�g���N�^
	/// </summary>
	/// <param name="argSceneChanger">SceneChanger�̃|�C���^</param>
	GameClear(GameScene* argGameScene);
	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	virtual ~GameClear();

	/// <summary>
	/// �X�V�������s��
	/// </summary>
	virtual void Update() override;
	/// <summary>
	/// �`�揈�����s��
	/// </summary>
	virtual void Draw() override;

private:
	int gameClearImage;

};

