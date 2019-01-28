/*****************************************************************************************************
-----�t�@�C���T�v-----
BaseObject���p��
�e�u���b�N�̊��N���X
******************************************************************************************************/

#pragma once

#include "BaseObject.h"

namespace{
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
	}e_BlockImageKind;
}

class BaseBlock : public BaseObject{

public:
	BaseBlock();
	BaseBlock(Position<int> argPos);
	virtual ~BaseBlock();
	virtual void Update() = 0;
	virtual void Draw() = 0;
	virtual bool HitAction() = 0;

protected:
	static const int Image_Width;
	static const int Image_Height;

protected:
	bool passFlag;					//�ʂ�邩�ǂ���
	static int* image;				//�摜�|�C���^
	int imageKind;					//�摜�̎��

};

