/*****************************************************************************************************
-----�t�@�C���T�v-----
�v���C���[�̓��e
�v���C���[�Ƌt���̖��H�ɔz�u�����
���E�͈�v
�f������f��Ȃ������肷��
******************************************************************************************************/

#pragma once

#include "../Base/BaseCharacter.h"

class Player;

class Mirror : public BaseCharacter{

public:
	Mirror(Player *player);
	virtual ~Mirror();
	virtual void Update() override;
	virtual void Draw() override;
	void Move();
	void Direction();
	void Fhashing();

private:
	Player *player;
	int flashTime;
	bool flashFlag;

};