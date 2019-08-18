/*****************************************************************************************************
-----�t�@�C���T�v-----
GameState���p��
�Q�[���I�[�o�[�̏��
******************************************************************************************************/

#pragma once

#include "GameState.h"

class GameOver : public GameState{

public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	/// <param name="argSceneChanger">SceneChanger�̃|�C���^</param>
	GameOver(GameScene* argGameScene);
	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	virtual ~GameOver();

	/// <summary>
	/// �X�V�������s��
	/// </summary>
	virtual void Update() override;
	/// <summary>
	/// �`�揈�����s��
	/// </summary>
	virtual void Draw() override;

private:
	int gameOverImage;

};

