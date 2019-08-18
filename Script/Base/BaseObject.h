/*****************************************************************************************************
-----�t�@�C���T�v-----
�I�u�W�F�N�g�̊��N���X
******************************************************************************************************/

#pragma once

#include "DxLib.h"
#include "../System/Position.h"

class BaseObject{

public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	BaseObject();
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	/// <param name="argPos">���W</param>
	BaseObject(Position<int> argPos);
	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	virtual ~BaseObject();

	/// <summary>
	/// �X�V�������s��
	/// </summary>
	virtual void Update() = 0;
	/// <summary>
	/// �`�揈�����s��
	/// </summary>
	virtual void Draw() = 0;

protected:
	static const int Block_Size;		//1�}�X�̃T�C�Y

protected:
	Position<int> pos;				//�I�u�W�F�N�g�̍��W

};

