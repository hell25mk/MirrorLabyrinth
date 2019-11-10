/*****************************************************************************************************
-----�t�@�C���T�v-----
�v���C���[�̓��e
�v���C���[�Ƌt���̖��H�ɔz�u�����
���E�͈�v
�f������f��Ȃ������肷��
******************************************************************************************************/

#pragma once

#include "../Base/BaseCharacter.h"

class Player;

class Mirror : public BaseCharacter{

public:
	/// <summary>
	/// �����o������������
	/// </summary>
	/// <param name="player">�v���C���[���i�[�����|�C���^</param>
	Mirror(Player* player);
	/// <summary>
	/// ���������m�ۂ��Ă����ꍇ�͉������
	/// </summary>
	virtual ~Mirror();

	/// <summary>
	/// 1���[�v���ŕK�v�ȍX�V�������s��
	/// </summary>
	virtual void Update() override;
	/// <summary>
	/// 1���[�v���ŕK�v�ȕ`�揈�����s��
	/// </summary>
	virtual void Draw() override;

	/// <summary>
/// �v���C���[�̍��W�ɑ΂���ꏊ�Ɉړ�����
/// </summary>
	void Move();
	/// <summary>
	/// �v���C���[�̌����ɑ΂�������ɕύX����
	/// </summary>
	void Direction();
	/// <summary>
	/// �_�ł��Ă��邩�ǂ�����؂�ւ���
	/// </summary>
	void Fhashing();

private:
	Player* player;
	int flashTime;
	bool willFlash;

};