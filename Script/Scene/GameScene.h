/*****************************************************************************************************
-----�t�@�C���T�v-----
�Q�[���V�[��
�Q�[����Ԃ��Ǘ�
******************************************************************************************************/

#pragma once

#include "../Base/BaseScene.h"

class GameState;

class GameScene : public BaseScene{

public:
	/// <summary>
	/// �����o������������
	/// </summary>
	/// <param name="argSceneChanger">SceneChanger�̃|�C���^</param>
	GameScene(SceneChanger* argSceneChanger);
	/// <summary>
	/// ���������m�ۂ��Ă����ꍇ�͉������
	/// </summary>
	virtual ~GameScene();

	/// <summary>
	/// 1���[�v���ŕK�v�ȍX�V�������s��
	/// </summary>
	virtual void Update() override;
	/// <summary>
	/// 1���[�v���ŕK�v�ȕ`�揈�����s��
	/// </summary>
	virtual void Draw() override;

	/// <summary>
	/// �Q�[���̏�Ԃɍ��킹���N���X�𐶐�����
	/// </summary>
	/// <param name="argGameState"></param>
	void SetGameState(int argGameState);
	/// <summary>
	/// ���Ɉړ�����V�[�����X�V����
	/// </summary>
	/// <param name="nextScene">�ړ���̃V�[���ԍ�</param>
	void NextScene(int argNextScene);
	/// <summary>
	/// ���݂̃X�e�[�W�����X�V����
	/// </summary>
	/// <param name="argStageNum">���B�����X�e�[�W��</param>
	void SetStageNum(int argStageNum);
	/// <summary>
	/// ���݂̃X�e�[�W�����擾����
	/// </summary>
	/// <returns>���݂̃X�e�[�W��</returns>
	int GetStageNum();

public:
	static const int Max_Stage_Num;
	static const int Laby_Height;
	static const int Laby_Width;
	//�Q�[���V�[���̏�ԊǗ��p
	typedef enum{
		State_ModeSelect,
		State_GameStart,
		State_GamePlay,
		State_StageClear,
		State_GameClear,
		State_GameOver,
		State_Result,

		State_Nore,
	}eGameState;

private:
	GameState* gameState;
	int nowStageNum;

};

