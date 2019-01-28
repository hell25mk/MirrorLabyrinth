/*****************************************************************************************************
-----�t�@�C���T�v-----
�h�A�I�u�W�F�N�g
����S�Ď擾���Ȃ��ƒʂ邱�Ƃ��ł��Ȃ�
******************************************************************************************************/

#pragma once

#include "../Base/BaseBlock.h"

class Door : public BaseBlock{

public:
	Door(Position<int> argPos, const int* maxKeyNum, int* getKeyNum);
	virtual ~Door();
	virtual void Update() override;
	virtual void Draw() override;
	virtual bool HitAction() override;

private:
	const int *maxKeyNum;
	int* getKeyNum;

};

