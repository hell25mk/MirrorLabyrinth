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
	/// �R���X�g���N�^
	/// </summary>
	/// <param name="argSceneChanger">SceneChanger�̃|�C���^</param>
	GameStart(GameScene* argGameScene);
	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	virtual ~GameStart();

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
	int floorImage;

};

