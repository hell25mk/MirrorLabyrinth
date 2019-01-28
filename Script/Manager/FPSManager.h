/*****************************************************************************************************
-----ファイル概要-----
FPSを一定に保つクラス
ゲームプログラミングの館にあるやつそのまま
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
	static const int Average_Sample;		//平均サンプル数
	static const int Basis_FPS;				//設定FPS

	int startTime;		//測定開始時刻
	int timeCount;		//カウンタ
	float fps;			//FPS

};

