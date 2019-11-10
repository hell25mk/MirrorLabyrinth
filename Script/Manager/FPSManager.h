/*****************************************************************************************************
-----�t�@�C���T�v-----
FPS�����ɕۂN���X
�Q�[���v���O���~���O�̊قɂ������̂܂�
******************************************************************************************************/

#pragma once

#include "../System/Singleton.h"

class FPSManager : public Singleton<FPSManager>{

public:
	friend class Singleton<FPSManager>;
	/// <summary>
	/// �������������s��
	/// </summary>
	virtual void Create() override;
	/// <summary>
	/// �I���������s��
	/// </summary>
	virtual void Destroy() override;

	/// <summary>
	/// 1���[�v���ŕK�v�ȍX�V�������s��
	/// </summary>
	void Update();
	/// <summary>
	/// 1���[�v���ŕK�v�ȕ`�揈�����s��
	/// </summary>
	void Draw();

	/// <summary>
	/// FPS�����̂��ߏ�����ҋ@������
	/// </summary>
	void Wait();

protected:
	FPSManager() : startTime(0),timeCount(0),fps(0.0f){ }
	virtual ~FPSManager(){ }

private:
	static const int Average_Sample;		//���σT���v����
	static const int Basis_FPS;				//�ݒ�FPS

	int startTime;		//����J�n����
	int timeCount;		//�J�E���^
	float fps;			//FPS

};

