/*****************************************************************************************************
-----�t�@�C���T�v-----
�K�i�I�u�W�F�N�g
�H�蒅���Ǝ��̃t���A�ֈړ��ł���
���t���A�ւ̈ړ���Laby�ŊǗ�
******************************************************************************************************/

#pragma once

#include "../Base/BaseBlock.h"

class Stairs : public BaseBlock{

public:
	/// <summary>
	/// �����o������������
	/// </summary>
	/// <param name="argPos">���W</param>
	Stairs(Position<int> argPos);
	/// <summary>
	/// ���������m�ۂ��Ă����ꍇ�͉������
	/// </summary>
	~Stairs();

	/// <summary>
	/// 1���[�v���ŕK�v�ȍX�V�������s��
	/// </summary>
	virtual void Update() override;
	/// <summary>
	/// 1���[�v���ŕK�v�ȕ`�揈�����s��
	/// </summary>
	virtual void Draw() override;

	/// <summary>
	/// �I�u�W�F�N�g�ɓ����������̃A�N�V��������
	/// </summary>
	/// <returns>���̃I�u�W�F�N�g���ʉ߂ł���ꍇtrue</returns>
	virtual bool HitAction() override;

};

