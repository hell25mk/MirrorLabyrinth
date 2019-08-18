/*****************************************************************************************************
-----�t�@�C���T�v-----
���Ԃ��Ǘ�����N���X
******************************************************************************************************/

#pragma once

#include "../Define/Enum.h"

class Timer{

public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	Timer();
	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	~Timer();

	/// <summary>
	/// �X�V�������s��
	/// </summary>
	void Update();
	/// <summary>
	/// �`�揈�����s��
	/// </summary>
	void Draw();

	/// <summary>
	/// ���݂̐i�s���Ԃ��擾
	/// </summary>
	/// <returns>�i�s��̎���</returns>
	int GetGameTimer();

private:
	static const int BasisTime;
	int nowGameTime;
	int startTime;
	int second;
	int minute;

};

