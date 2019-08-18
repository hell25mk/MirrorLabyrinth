/*****************************************************************************************************
-----�t�@�C���T�v-----
GameState���p��
�Q�[���v���C���̏��
******************************************************************************************************/

#pragma once

#include "GameState.h"

class Laby;
class Player;
class Mirror;
class Timer;
class GameText;

class GamePlay : public GameState{

public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	/// <param name="argSceneChanger">SceneChanger�̃|�C���^</param>
	GamePlay(GameScene* argGameScene);
	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	virtual ~GamePlay();

	/// <summary>
	/// �X�V�������s��
	/// </summary>
	virtual void Update() override;
	/// <summary>
	/// �`�揈�����s��
	/// </summary>
	virtual void Draw() override;

	/// <summary>
	/// �t�@�C������X�e�[�W�𐶐�����
	/// </summary>
	void StageCreate();

private:
	Laby* laby;
	Player* player;
	Mirror* mirror;
	Timer* timer;
	GameText* gameText;

};

