/*****************************************************************************************************
-----�t�@�C���T�v-----
�h�A�I�u�W�F�N�g
����S�Ď擾���Ȃ��ƒʂ邱�Ƃ��ł��Ȃ�
******************************************************************************************************/

#pragma once

#include "../Base/BaseBlock.h"

class Door : public BaseBlock{

public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	/// <param name="argPos">���W</param>
	/// <param name="maxKeyNum">���̍ő吔���i�[�����|�C���^</param>
	/// <param name="getKeyNum">�擾�������̐����i�[�����|�C���^</param>
	Door(Position<int> argPos, const int* maxKeyNum, int* getKeyNum);
	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	virtual ~Door();

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
	const int* maxKeyNum;
	int* getKeyNum;

};

