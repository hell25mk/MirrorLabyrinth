/*****************************************************************************************************
-----�t�@�C���T�v-----
�u���b�N�I�u�W�F�N�g
��{�͒ʂ邱�Ƃ��ł��Ȃ�
��������𖞂����ƒʂ邱�Ƃ��ł���
******************************************************************************************************/

#pragma once

#include "../Base/BaseBlock.h"

class Block : public BaseBlock{

public:
	Block(Position<int> argPos);
	virtual ~Block();
	virtual void Update() override;
	virtual void Draw() override;
	virtual bool HitAction() override;

private:
	int damage;

};

