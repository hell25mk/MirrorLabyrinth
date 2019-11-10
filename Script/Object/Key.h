/*****************************************************************************************************
-----�t�@�C���T�v-----
���I�u�W�F�N�g
�S�Ď擾���邱�ƂŃh�A���J�����Ƃ��ł���
******************************************************************************************************/

#pragma once

#include "../Base/BaseBlock.h"

class Key : public BaseBlock{

public:
	/// <summary>
	/// �����o������������
	/// </summary>
	/// <param name="argPos">���W</param>
	/// <param name="getKeyNum">�擾�������̐����i�[�����|�C���^</param>
	Key(Position<int> argPos,int* getKeyNum);
	/// <summary>
	/// ���������m�ۂ��Ă����ꍇ�͉������
	/// </summary>
	virtual ~Key();

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

private:
	bool isGet;
	int* getKeyNum;

};

