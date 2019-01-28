/*****************************************************************************************************
�N���X���@�FBaseCharacter
------------------------------------------------------------------------------------------------------
�N���X�T�v�F�L�����N�^�[�̊�{�v�f�����N���X
******************************************************************************************************/

/*****************************************************************************************************
-----�t�@�C���T�v-----
BaseObject���p��
�e�L�����N�^�[�̊��N���X
******************************************************************************************************/

#pragma once

#include "BaseObject.h"

class Animation;

class BaseCharacter : public BaseObject{

public:
	BaseCharacter();
	BaseCharacter(Position<int> argPos);
	virtual ~BaseCharacter();
	virtual void Update() = 0;
	virtual void Draw() = 0;

protected:
	static const int Image_Size;				//�摜�̕����T�C�Y�i�c�����T�C�Y�j
	static const int Image_Width;				//�摜�̉������T�C�Y
	static const int Image_Height;				//�摜�̏c�����T�C�Y
	static const int AnimeChange_Time;			//�A�j���[�V�����̕ϓ�����

protected:
	Animation * animation;						//�A�j���[�V�����p�̃|�C���^
	bool alivaFlag;								//�I�u�W�F�N�g�������Ă��邩
	static int *image;							//�摜�|�C���^
	int dire;									//�I�u�W�F�N�g�̌����Ă������
	int imageNumber;							//���݂̉摜�ԍ�

};

