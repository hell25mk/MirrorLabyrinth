/*****************************************************************************************************
-----�t�@�C���T�v-----
���I�u�W�F�N�g
�S�Ď擾���邱�ƂŃh�A���J�����Ƃ��ł���
******************************************************************************************************/

#pragma once

#include "../Base/BaseBlock.h"

class Key : public BaseBlock{

public:
	Key(Position<int> argPos,int* getKeyNum);
	virtual ~Key();
	virtual void Update() override;
	virtual void Draw() override;
	virtual bool HitAction() override;

private:
	bool getFlag;
	int* getKeyNum;

};

