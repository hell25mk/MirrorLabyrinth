/*****************************************************************************************************
-----�t�@�C���T�v-----
�h�A�I�u�W�F�N�g
����S�Ď擾���Ȃ��ƒʂ邱�Ƃ��ł��Ȃ�
******************************************************************************************************/

#pragma once

#include "../Base/BaseBlock.h"

class C_Door : public C_BaseBlock{

public:
	C_Door(C_Position<int> argPos, const int *maxKeyNum, int *getKeyNum);
	virtual ~C_Door();
	virtual void Update() override;
	virtual void Draw() override;
	virtual bool HitAction() override;

private:
	const int *maxKeyNum;
	int *getKeyNum;

};

