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
	/// <summary>
	/// 初期化処理を行う
	/// </summary>
	virtual void Create() override;
	/// <summary>
	/// 終了処理を行う
	/// </summary>
	virtual void Destroy() override;

	/// <summary>
	/// 1ループ内で必要な更新処理を行う
	/// </summary>
	void Update();
	/// <summary>
	/// 1ループ内で必要な描画処理を行う
	/// </summary>
	void Draw();

	/// <summary>
	/// FPS調整のため処理を待機させる
	/// </summary>
	void Wait();

protected:
	FPSManager() : startTime(0),timeCount(0),fps(0.0f){ }
	virtual ~FPSManager(){ }

private:
	static const int Average_Sample;		//平均サンプル数
	static const int Basis_FPS;				//設定FPS

	int startTime;		//測定開始時刻
	int timeCount;		//カウンタ
	float fps;			//FPS

};

