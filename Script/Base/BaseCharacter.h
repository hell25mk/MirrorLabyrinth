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
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	BaseCharacter();
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	/// <param name="argPos">���W</param>
	BaseCharacter(Position<int> argPos);
	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	virtual ~BaseCharacter();

	/// <summary>
	/// �X�V�������s��
	/// </summary>
	virtual void Update() = 0;
	/// <summary>
	/// �`�揈�����s��
	/// </summary>
	virtual void Draw() = 0;

protected:
	static const int Image_Size;				//�摜�̕����T�C�Y�i�c�����T�C�Y�j
	static const int Image_Width;				//�摜�̉������T�C�Y
	static const int Image_Height;				//�摜�̏c�����T�C�Y
	static const int AnimeChange_Time;			//�A�j���[�V�����̕ϓ�����

protected:
	Animation* animation;						//�A�j���[�V�����p�̃|�C���^
	bool alivaFlag;								//�I�u�W�F�N�g�������Ă��邩
	static int* image;							//�摜�|�C���^(����̃Q�[���ł̓v���C���[�͓����摜���g���̂�static�ɂ��ċ��L���Ă���)
	int dire;									//�I�u�W�F�N�g�̌����Ă������
	int imageNumber;							//���݂̉摜�ԍ�

};

