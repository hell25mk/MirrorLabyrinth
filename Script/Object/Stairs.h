/*****************************************************************************************************
-----�t�@�C���T�v-----
�K�i�I�u�W�F�N�g
�H�蒅���Ǝ��̃t���A�ֈړ��ł���
���t���A�ւ̈ړ���Laby�ŊǗ�
******************************************************************************************************/

#pragma once

#include "../Base/BaseBlock.h"

class Stairs : public BaseBlock{

public:
	Stairs(Position<int> argPos);
	virtual ~Stairs();
	virtual void Update() override;
	virtual void Draw() override;
	virtual bool HitAction() override;

};

