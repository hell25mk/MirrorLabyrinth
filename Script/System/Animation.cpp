#include "Animation.h"

/// <summary>
/// �R���X�g���N�^
/// </summary>
/// <param name="animeOrder">�A�j���[�V�������s���摜�̔ԍ����i�[�����z��</param>
/// <param name="orderSize">animeOrder����ǂ͈̔͂��A�j���[�V���������邩</param>
/// <param name="animeChangeTime">�A�j���[�V����������Ԋu</param>
/// <param name="imageNumber">�I�u�W�F�N�g�̉摜�ԍ����i�[�����|�C���^</param>
Animation::Animation(int animeOrder[], int orderSize, int animeChangeTime, int* imageNumber){

	this->animeOrderSize = orderSize;
	this->animeOrder = new int[animeOrderSize];
	for(int i = 0; i < animeOrderSize; i++){

		this->animeOrder[i] = animeOrder[i];

	}
	this->animeChangeTime = animeChangeTime;
	this->imageNumber = imageNumber;
	animeCount = 0;
	animeNumber = 0;

}

/// <summary>
/// �f�X�g���N�^
/// </summary>
Animation::~Animation(){

	delete animeOrder;

}

/// <summary>
/// �X�V�������s��
/// </summary>
void Animation::Update(){

	animeCount++;

	if(animeCount % animeChangeTime != 0){
		return;
	}

	animeCount = 0;
	animeNumber >= (animeOrderSize - 1) ? animeNumber = 0 : animeNumber++;

	*imageNumber = animeOrder[animeNumber];

}