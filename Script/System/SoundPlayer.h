/*****************************************************************************************************
-----ファイル概要-----
Soundを管理するクラス
******************************************************************************************************/

#pragma once

#include "Singleton.h"
#include <map>

class C_SoundPlayer : public C_Singleton<C_SoundPlayer>{

public:
	friend class C_Singleton<C_SoundPlayer>;

	virtual void Create() override;
	void PlayBGM(std::string argKey);
	void StopBGM();
	void PlaySE(std::string argKey);

protected:
	C_SoundPlayer(){}
	virtual ~C_SoundPlayer(){}

private:
	std::map<std::string, int> sound;
	std::string nowPlaySound;

};

