/*****************************************************************************************************
-----�t�@�C���T�v-----
�ǃI�u�W�F�N�g
�ʂ�Ȃ�
******************************************************************************************************/

#pragma once

#include "../Base/BaseBlock.h"

class C_Wall : public C_BaseBlock{

public:
	C_Wall(C_Position<int> argPos);
	virtual ~C_Wall();
	virtual void Update() override;
	virtual void Draw() override;
	virtual bool HitAction() override;

};

