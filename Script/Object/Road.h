/*****************************************************************************************************
-----�t�@�C���T�v-----
���I�u�W�F�N�g
�ʂ��
******************************************************************************************************/

#pragma once

#include "../Base/BaseBlock.h"

class C_Road : public C_BaseBlock{

public:
	C_Road(C_Position<int> argPos);
	~C_Road();
	virtual void Update() override;
	virtual void Draw() override;
	virtual bool HitAction() override;

};

