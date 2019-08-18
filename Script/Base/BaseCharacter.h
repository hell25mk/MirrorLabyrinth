/*****************************************************************************************************
クラス名　：BaseCharacter
------------------------------------------------------------------------------------------------------
クラス概要：キャラクターの基本要素を持つクラス
******************************************************************************************************/

/*****************************************************************************************************
-----ファイル概要-----
BaseObjectを継承
各キャラクターの基底クラス
******************************************************************************************************/

#pragma once

#include "BaseObject.h"

class Animation;

class BaseCharacter : public BaseObject{

public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	BaseCharacter();
	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="argPos">座標</param>
	BaseCharacter(Position<int> argPos);
	/// <summary>
	/// デストラクタ
	/// </summary>
	virtual ~BaseCharacter();

	/// <summary>
	/// 更新処理を行う
	/// </summary>
	virtual void Update() = 0;
	/// <summary>
	/// 描画処理を行う
	/// </summary>
	virtual void Draw() = 0;

protected:
	static const int Image_Size;				//画像の分割サイズ（縦横同サイズ）
	static const int Image_Width;				//画像の横分割サイズ
	static const int Image_Height;				//画像の縦分割サイズ
	static const int AnimeChange_Time;			//アニメーションの変動時間

protected:
	Animation* animation;						//アニメーション用のポインタ
	bool alivaFlag;								//オブジェクトが生きているか
	static int* image;							//画像ポインタ(今回のゲームではプレイヤーは同じ画像を使うのでstaticにして共有している)
	int dire;									//オブジェクトの向いている方向
	int imageNumber;							//現在の画像番号

};

