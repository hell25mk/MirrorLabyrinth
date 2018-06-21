#include "Animation.h"

C_Animation::C_Animation(int animeOrder[], int orderSize, int animeChangeTime, int *imageNumber){

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

C_Animation::~C_Animation(){

	delete animeOrder;

}

void C_Animation::Update(){

	animeCount++;

	if(animeCount % animeChangeTime != 0){
		return;
	}

	animeCount = 0;
	animeNumber >= (animeOrderSize - 1) ? animeNumber = 0 : animeNumber++;

	*imageNumber = animeOrder[animeNumber];

}

void C_Animation::Change(){

	animeCount = 0;
	animeNumber = 0;

}