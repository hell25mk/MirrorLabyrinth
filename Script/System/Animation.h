/*****************************************************************************************************
-----�t�@�C���T�v-----
�A�j���[�V�������s���N���X
�A�j���[�V�����̑J�ڂ݂̂��s���`��͌��̃N���X�ōs��
******************************************************************************************************/

#pragma once

class Animation{

public:
	Animation(int animeOrder[],int orderSize,int animeChangeTime,int* imageNumber);
	~Animation();
	void Update();

private:
	int* animeOrder;
	int animeOrderSize;
	int animeChangeTime;
	int animeCount;
	int animeNumber;
	int* imageNumber;

};

