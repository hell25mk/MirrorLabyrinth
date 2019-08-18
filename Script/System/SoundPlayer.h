/*****************************************************************************************************
-----ファイル概要-----
Soundを管理するクラス
******************************************************************************************************/

#pragma once

#include "Singleton.h"
#include <map>
#include <string>

class SoundPlayer : public Singleton<SoundPlayer>{

public:
	friend class Singleton<SoundPlayer>;

	/// <summary>
	/// 初期化処理を行う
	/// </summary>
	virtual void Create() override;

	/// <summary>
	/// BGMを再生する
	/// </summary>
	/// <param name="argKey">再生するBGMのキーワード</param>
	void PlayBGM(std::string argKey);
	/// <summary>
	/// BGMを停止する
	/// </summary>
	void StopBGM();
	/// <summary>
	/// SEを再生する
	/// </summary>
	/// <param name="argKey">再生するSEのキーワード</param>
	void PlaySE(std::string argKey);

protected:
	SoundPlayer(){}
	virtual ~SoundPlayer(){}

private:
	std::map<std::string, int> sound;
	std::string nowPlaySound;

};

