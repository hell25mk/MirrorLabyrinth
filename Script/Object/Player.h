#pragma once

#include "../Base/BaseCharacter.h"

class C_Animation;

class C_Player : public C_BaseCharacter{

public:
	C_Player(C_Position<int> argPos);
	virtual ~C_Player();
	virtual void Update() override;
	virtual void Draw() override;
	virtual bool HitAction() override;
	void Move(int argMoveDire);
	C_Position<int> GetPosition();
	int GetDirection();

private:
	bool moveFlag;
	C_Animation *animation;

};

