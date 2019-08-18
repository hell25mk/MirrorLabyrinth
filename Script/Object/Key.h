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
	/// �R���X�g���N�^
	/// </summary>
	/// <param name="argPos">���W</param>
	/// <param name="getKeyNum">�擾�������̐����i�[�����|�C���^</param>
	Key(Position<int> argPos,int* getKeyNum);
	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	virtual ~Key();

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
	bool isGet;
	int* getKeyNum;

};

