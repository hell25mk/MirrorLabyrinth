/*****************************************************************************************************
-----�t�@�C���T�v-----
�ǃI�u�W�F�N�g
�ʂ�Ȃ�
******************************************************************************************************/

#pragma once

#include "../Base/BaseBlock.h"

class Wall : public BaseBlock{

public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	/// <param name="argPos">���W</param>
	Wall(Position<int> argPos);
	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	~Wall();

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

