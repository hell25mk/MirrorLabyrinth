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
	/// �����o������������
	/// </summary>
	BaseObject();
	/// <summary>
	/// �����o������������
	/// </summary>
	/// <param name="argPos">���W</param>
	BaseObject(Position<int> argPos);
	/// <summary>
	/// ���������m�ۂ��Ă����ꍇ�͉������
	/// </summary>
	virtual ~BaseObject();

	/// <summary>
	/// 1���[�v���ŕK�v�ȍX�V�������s��
	/// </summary>
	virtual void Update() = 0;
	/// <summary>
	/// 1���[�v���ŕK�v�ȕ`�揈�����s��
	/// </summary>
	virtual void Draw() = 0;

protected:
	static const int Block_Size;		//1�}�X�̃T�C�Y

protected:
	Position<int> pos;				//�I�u�W�F�N�g�̍��W

};

