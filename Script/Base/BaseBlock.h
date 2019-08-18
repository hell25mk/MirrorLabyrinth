/*****************************************************************************************************
-----�t�@�C���T�v-----
BaseObject���p��
�e�u���b�N�̊��N���X
******************************************************************************************************/

#pragma once

#include "BaseObject.h"

namespace{
	//�u���b�N�̉摜�ԍ�
	typedef enum{
		Laby_Road,
		Laby_Wall,
		Laby_Stairs,
		Laby_Nore1,
		Laby_Nore2,
		Laby_CloseDoor,
		Laby_OpenDoor,
		Laby_RubyKey,
		Laby_DiaKey,
		Laby_Nore3,
		Laby_Block1,
		Laby_Block2,
		Laby_Block3,
		Laby_Block4,
		Laby_Nore4,
	}eBlockImageKind;
}

class BaseBlock : public BaseObject{

public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	BaseBlock();
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	/// <param name="argPos">���W</param>
	BaseBlock(Position<int> argPos);
	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	virtual ~BaseBlock();

	/// <summary>
	/// �X�V�������s��
	/// </summary>
	virtual void Update() = 0;
	/// <summary>
	/// �`�揈�����s��
	/// </summary>
	virtual void Draw() = 0;

	/// <summary>
	/// �I�u�W�F�N�g�ɓ����������̃A�N�V��������
	/// </summary>
	/// <returns>���̃I�u�W�F�N�g���ʉ߂ł���ꍇtrue</returns>
	virtual bool HitAction() = 0;

protected:
	static const int Image_Width;
	static const int Image_Height;

protected:
	bool canMove;					//�ʂ�邩�ǂ���
	static int* image;				//�摜�|�C���^
	int imageKind;					//�摜�̎��

};

