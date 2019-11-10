/*****************************************************************************************************
-----�t�@�C���T�v-----
�Q�[���S�̂��Ǘ�����N���X
Main�ł͂��̃N���X�݂̂𐶐�����
******************************************************************************************************/

#pragma once

#include "../System/Singleton.h"

class SceneManager;

class GameManager : public Singleton<GameManager>{

public:
	friend class Singleton<GameManager>;
	/// <summary>
	/// �������������s��
	/// </summary>
	virtual void Create() override;
	/// <summary>
	/// �I���������s��
	/// </summary>
	virtual void Destroy() override;

	/// <summary>
	/// 1���[�v���ŕK�v�ȍX�V�������s��
	/// </summary>
	/// <returns>�V�[���̈ړ��悪Scene_End�ȊO�������ꍇtrue��Ԃ�</returns>
	bool Update();
	/// <summary>
	/// 1���[�v���ŕK�v�ȕ`�揈�����s��
	/// </summary>
	void Draw();

protected:
	GameManager() : sceneManager(){ }
	virtual ~GameManager(){ }

private:
	SceneManager* sceneManager;

};

