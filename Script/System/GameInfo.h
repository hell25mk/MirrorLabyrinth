#pragma once

#include "Singleton.h"
#include "../Define/Enum.h"
#include <map>

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

	void UpImageType();
	void DownImageType();
	e_ImageType GetImageType();

protected:
	C_GameInfo(){}
	virtual ~C_GameInfo(){}

private:
	std::map<std::string, int> info;
	e_GameLevel gameLevel;
	e_ImageType imageType;

};