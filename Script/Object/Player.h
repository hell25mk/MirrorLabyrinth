#pragma once

#include "../Define/Enum.h"
#include "../Base/BaseCharacter.h"

class C_Mirror;
class C_Animation;

class C_Player : public C_BaseCharacter{

public:
	C_Player(C_Position<int> argPos);
	virtual ~C_Player();
	virtual void Update() override;
	virtual void Draw() override;
	void Move(int argMoveDire);
	C_Position<int> GetPosition();
	int GetDirection();

private:
	bool moveFlag;
	C_Mirror *mirror;
	C_Animation *animation;

};

