/*****************************************************************************************************
-----�t�@�C���T�v-----
�ǃI�u�W�F�N�g
�ʂ�Ȃ�
******************************************************************************************************/

#pragma once

#include "../Base/BaseBlock.h"

class Wall : public BaseBlock{

public:
	Wall(Position<int> argPos);
	virtual ~Wall();
	virtual void Update() override;
	virtual void Draw() override;
	virtual bool HitAction() override;

};

