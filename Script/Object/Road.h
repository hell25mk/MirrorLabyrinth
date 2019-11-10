/*****************************************************************************************************
-----�t�@�C���T�v-----
���I�u�W�F�N�g
�ʂ��
******************************************************************************************************/

#pragma once

#include "../Base/BaseBlock.h"

class Road : public BaseBlock{

public:
	/// <summary>
	/// �����o������������
	/// </summary>
	/// <param name="argPos">���W</param>
	Road(Position<int> argPos);
	/// <summary>
	/// ���������m�ۂ��Ă����ꍇ�͉������
	/// </summary>
	~Road();

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

