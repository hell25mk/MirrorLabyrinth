/*****************************************************************************************************
-----�t�@�C���T�v-----
���I�u�W�F�N�g
�ʂ��
******************************************************************************************************/

#pragma once

#include "../Base/BaseBlock.h"

class Road : public BaseBlock{

public:
	Road(Position<int> argPos);
	~Road();
	virtual void Update() override;
	virtual void Draw() override;
	virtual bool HitAction() override;

};

