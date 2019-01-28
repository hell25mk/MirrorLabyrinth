/*****************************************************************************************************
-----�t�@�C���T�v-----
�I�u�W�F�N�g�̊��N���X
******************************************************************************************************/

#pragma once

#include "DxLib.h"
#include "../System/Position.h"

class BaseObject{

public:
	BaseObject();
	BaseObject(Position<int> argPos);
	virtual ~BaseObject();
	virtual void Update() = 0;
	virtual void Draw() = 0;

protected:
	static const int Block_Size;		//1�}�X�̃T�C�Y

protected:
	Position<int> pos;				//�I�u�W�F�N�g�̍��W

};

