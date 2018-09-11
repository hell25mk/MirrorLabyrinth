/*****************************************************************************************************
-----ファイル概要-----
アニメーションを行うクラス
アニメーションの遷移のみを行い描画は元のクラスで行う
******************************************************************************************************/

#pragma once

class C_Animation{

public:
	C_Animation(int animeOrder[],int orderSize,int animeChangeTime,int *imageNumber);
	~C_Animation();
	void Update();

private:
	int *animeOrder;
	int animeOrderSize;
	int animeChangeTime;
	int animeCount;
	int animeNumber;
	int *imageNumber;

};

