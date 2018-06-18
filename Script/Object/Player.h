#pragma once

#include "../Define/Enum.h"
#include "../Base/BaseObject.h"

class C_Mirror;

class C_Player : public C_BaseObject{

public:
	C_Player(C_Position argPos);
	virtual ~C_Player();
	void Update();
	virtual void Draw() override;
	void Move(int argMoveDire);
	void Animation();
	C_Position GetPosition();

private:
	int *playerImage;
	int imageType;
	e_Direction nowDire;
	int animeTime;
	int animeImage;
	bool animeChangeFlag;
	bool moveFlag;
	C_Mirror *mirror;

};

