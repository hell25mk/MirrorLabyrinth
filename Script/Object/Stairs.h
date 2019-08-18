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
	/// �R���X�g���N�^
	/// </summary>
	/// <param name="argPos">���W</param>
	Stairs(Position<int> argPos);
	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	~Stairs();

	/// <summary>
	/// �X�V�������s��
	/// </summary>
	virtual void Update() override;
	/// <summary>
	/// �`�揈�����s��
	/// </summary>
	virtual void Draw() override;

	/// <summary>
	/// �I�u�W�F�N�g�ɓ����������̃A�N�V��������
	/// </summary>
	/// <returns>���̃I�u�W�F�N�g���ʉ߂ł���ꍇtrue</returns>
	virtual bool HitAction() override;

};

