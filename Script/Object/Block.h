/*****************************************************************************************************
-----�t�@�C���T�v-----
�u���b�N�I�u�W�F�N�g
��{�͒ʂ邱�Ƃ��ł��Ȃ�
��������𖞂����ƒʂ邱�Ƃ��ł���
******************************************************************************************************/

#pragma once

#include "../Base/BaseBlock.h"

class Block : public BaseBlock{

public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	/// <param name="argPos">���W</param>
	Block(Position<int> argPos);
	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	virtual ~Block();

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

private:
	int endurance;			//�ϋv�l
	int damage;				//�󂯂��_���[�W

};

