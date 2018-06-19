#pragma once

#include "../Define/Enum.h"
#include "../Base/BaseObject.h"
#include "Player.h"

class C_Mirror : public C_BaseObject{

public:
	C_Mirror(C_Position argPos,int argImageType);
	virtual ~C_Mirror();
	void Update(C_Position argPos, e_Direction argDire);
	virtual void Update() override;
	virtual void Draw() override;
	void Animation();
	void Fhashing();

private:
	int *mirrorImage;
	int imageType;
	int nowDire;
	int flashTime;
	bool flashFlag;
	int animeTime;
	int animeImage;
	bool animeChangeFlag;
	bool moveFlag;

};