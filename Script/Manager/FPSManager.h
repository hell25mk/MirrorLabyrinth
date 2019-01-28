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
	virtual void Create() override;
	virtual void Destroy() override;
	bool Update();
	void Draw();
	void Wait();

protected:
	FPSManager(){ }
	virtual ~FPSManager(){ }

private:
	static const int Average_Sample;		//���σT���v����
	static const int Basis_FPS;				//�ݒ�FPS

	int startTime;		//����J�n����
	int timeCount;		//�J�E���^
	float fps;			//FPS

};

