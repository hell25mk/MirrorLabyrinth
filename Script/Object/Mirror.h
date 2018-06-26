#pragma once

#include "../Base/BaseCharacter.h"

class C_Player;

class C_Mirror : public C_BaseCharacter{

public:
	C_Mirror(C_Player *player);
	virtual ~C_Mirror();
	virtual void Update() override;
	virtual void Draw() override;
	virtual bool HitAction() override;
	void Move();
	void Fhashing();

private:
	C_Player *player;
	int flashTime;
	bool flashFlag;

};