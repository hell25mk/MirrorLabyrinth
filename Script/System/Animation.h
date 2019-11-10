/*****************************************************************************************************
-----ファイル概要-----
アニメーションを行うクラス
アニメーションの遷移のみを行い描画は元のクラスで行う
******************************************************************************************************/

#pragma once

class Animation{

public:
	/// <summary>
	/// メンバを初期化する
	/// </summary>
	/// <param name="animeOrder">アニメーションを行う画像の番号を格納した配列</param>
	/// <param name="orderSize">animeOrderからどの範囲をアニメーションさせるか</param>
	/// <param name="animeChangeTime">アニメーションをする間隔</param>
	/// <param name="imageNumber">オブジェクトの画像番号を格納したポインタ</param>
	Animation(int animeOrder[],int orderSize,int animeChangeTime,int* imageNumber);
	/// <summary>
	/// メモリを確保していた場合は解放する
	/// </summary>
	~Animation();

	/// <summary>
	/// 1ループ内で必要な更新処理を行う
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

