/*****************************************************************************************************
-----ファイル概要-----
アニメーションを行うクラス
アニメーションの遷移のみを行い描画は元のクラスで行う
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

