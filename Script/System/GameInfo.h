#pragma once

#include "Singleton.h"
#include "../Define/Enum.h"
#include <map>

enum e_GameLevel{
	Level_Easy,
	Level_Normal,
	Level_Hard,
	Level_Expert,

	Level_Num,
};

class C_GameInfo : public C_Singleton<C_GameInfo>{

public:
	friend class C_Singleton<C_GameInfo>;
	
	void SetInfo(std::string argKey, int argValue);
	int GetInfo(std::string argKey) const;

	virtual void Create() override;
	void UpGameLevel();
	void DownGameLevel();
	void ExpertGameLevel();
	e_GameLevel GetGameLevel();

protected:
	C_GameInfo(){}
	virtual ~C_GameInfo(){}

private:
	std::map<std::string, int> info;
	e_GameLevel gameLevel;

};