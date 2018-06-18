#pragma once

#include "../System/Singleton.h"

class C_FPSManager : public C_Singleton<C_FPSManager>{

public:
	friend class C_Singleton<C_FPSManager>;
	virtual void Create() override;
	virtual void Destroy() override;
	bool Update();
	void Draw();
	void Wait();

protected:
	C_FPSManager(){ }
	virtual ~C_FPSManager(){ }

private:
	static const int Average_Sample;		//���σT���v����
	static const int Basis_FPS;				//�ݒ�FPS

	int startTime;		//����J�n����
	int timeCount;		//�J�E���^
	float fps;			//FPS

};

