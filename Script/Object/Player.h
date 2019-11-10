/*--------------------------------------------------------------------------------------------------------------------*
*<file>Player.h</file>
*<summary>
*����v���C���[�ɕK�v�ȃN���X
*</summary>
----------------------------------------------------------------------------------------------------------------------*/

#pragma once

#include "../Base/BaseCharacter.h"

class Animation;

class Player : public BaseCharacter{

public:
	/// <summary>
	/// �����o������������
	/// </summary>
	/// <param name="argPos">���W</param>
	Player(Position<int> argPos);
	/// <summary>
	/// ���������m�ۂ��Ă����ꍇ�͉������
	/// </summary>
	virtual ~Player();

	/// <summary>
	/// 1���[�v���ŕK�v�ȍX�V�������s��
	/// </summary>
	virtual void Update() override;
	/// <summary>
	/// 1���[�v���ŕK�v�ȕ`�揈�����s��
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

