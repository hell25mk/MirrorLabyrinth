/*****************************************************************************************************
-----�t�@�C���T�v-----
�v���C���[�̃N���X
******************************************************************************************************/

#pragma once

#include "../Base/BaseCharacter.h"

class Animation;

class Player : public BaseCharacter{

public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	/// <param name="argPos">���W</param>
	Player(Position<int> argPos);
	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	virtual ~Player();

	/// <summary>
	/// �X�V�������s��
	/// </summary>
	virtual void Update() override;
	/// <summary>
	/// �`�揈�����s��
	/// </summary>
	virtual void Draw() override;

	/// <summary>
	/// ���W���X�V����
	/// </summary>
	/// <param name="argMoveDire">�ړ��������</param>
	void Move(int argMoveDire);
	/// <summary>
	/// �������X�V����
	/// </summary>
	/// <param name="argMoveDire">�ړ��������</param>
	void Direction(int argMoveDire);
	/// <summary>
	/// ���W���擾����
	/// </summary>
	/// <returns>�v���C���[�̍��W</returns>
	Position<int> GetPosition();
	/// <summary>
	/// �������擾����
	/// </summary>
	/// <returns>�v���C���[�̌���</returns>
	int GetDirection();

private:
	Animation* animation;

};

