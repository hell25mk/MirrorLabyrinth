/*****************************************************************************************************
-----ファイル概要-----
ゲーム全体の情報を管理するクラス
作り方次第で消せる
******************************************************************************************************/

#pragma once

#include "Singleton.h"
#include "../Define/Enum.h"
#include <map>
#include <string>

enum e_GameLevel{
	Level_Easy,
	Level_Normal,
	Level_Hard,

	Level_Num,
};

class GameInfo : public Singleton<GameInfo>{

public:
	friend class Singleton<GameInfo>;
	
	void SetInfo(std::string argKey, int argValue);
	int GetInfo(std::string argKey) const;

	virtual void Create() override;
	void UpGameLevel();
	void DownGameLevel();
	e_GameLevel GetGameLevel();

protected:
	GameInfo() = default;
	virtual ~GameInfo(){}

private:
	std::map<std::string, int> info;
	e_GameLevel gameLevel;

};