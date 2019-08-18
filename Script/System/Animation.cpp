#include "Animation.h"

/// <summary>
/// コンストラクタ
/// </summary>
/// <param name="animeOrder">アニメーションを行う画像の番号を格納した配列</param>
/// <param name="orderSize">animeOrderからどの範囲をアニメーションさせるか</param>
/// <param name="animeChangeTime">アニメーションをする間隔</param>
/// <param name="imageNumber">オブジェクトの画像番号を格納したポインタ</param>
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
/// デストラクタ
/// </summary>
Animation::~Animation(){

	delete animeOrder;

}

/// <summary>
/// 更新処理を行う
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