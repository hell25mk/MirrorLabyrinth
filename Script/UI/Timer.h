/*****************************************************************************************************
-----�t�@�C���T�v-----
���Ԃ��Ǘ�����N���X
******************************************************************************************************/

#pragma once

#include "../Define/Enum.h"

class Timer{

public:
	/// <summary>
	/// �����o������������
	/// </summary>
	Timer();
	/// <summary>
	/// ���������m�ۂ��Ă����ꍇ�͉������
	/// </summary>
	~Timer();

	/// <summary>
	/// 1���[�v���ŕK�v�ȍX�V�������s��
	/// </summary>
	void Update();
	/// <summary>
	/// 1���[�v���ŕK�v�ȕ`�揈�����s��
	/// </summary>
	void Draw();

	/// <summary>
	/// ���݂̐i�s���Ԃ��擾
	/// </summary>
	/// <returns>�i�s��̎���</returns>
	int GetGameTimer();

private:
	static const int Basis_Time;
	int nowGameTime;
	int startTime;
	int second;
	int minute;

};

