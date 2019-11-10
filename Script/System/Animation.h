/*****************************************************************************************************
-----�t�@�C���T�v-----
�A�j���[�V�������s���N���X
�A�j���[�V�����̑J�ڂ݂̂��s���`��͌��̃N���X�ōs��
******************************************************************************************************/

#pragma once

class Animation{

public:
	/// <summary>
	/// �����o������������
	/// </summary>
	/// <param name="animeOrder">�A�j���[�V�������s���摜�̔ԍ����i�[�����z��</param>
	/// <param name="orderSize">animeOrder����ǂ͈̔͂��A�j���[�V���������邩</param>
	/// <param name="animeChangeTime">�A�j���[�V����������Ԋu</param>
	/// <param name="imageNumber">�I�u�W�F�N�g�̉摜�ԍ����i�[�����|�C���^</param>
	Animation(int animeOrder[],int orderSize,int animeChangeTime,int* imageNumber);
	/// <summary>
	/// ���������m�ۂ��Ă����ꍇ�͉������
	/// </summary>
	~Animation();

	/// <summary>
	/// 1���[�v���ŕK�v�ȍX�V�������s��
	/// </summary>
	void Update();

private:
	int* animeOrder;
	int animeOrderSize;
	int animeChangeTime;
	int animeCount;
	int animeNumber;
	int* imageNumber;

};

