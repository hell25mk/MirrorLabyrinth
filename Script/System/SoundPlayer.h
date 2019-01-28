/*****************************************************************************************************
-----ファイル概要-----
Soundを管理するクラス
******************************************************************************************************/

#pragma once

#include "Singleton.h"
#include <map>

class SoundPlayer : public Singleton<SoundPlayer>{

public:
	friend class Singleton<SoundPlayer>;

	virtual void Create() override;
	void PlayBGM(std::string argKey);
	void StopBGM();
	void PlaySE(std::string argKey);

protected:
	SoundPlayer(){}
	virtual ~SoundPlayer(){}

private:
	std::map<std::string, int> sound;
	std::string nowPlaySound;

};

