/*--------------------------------------------------------------------------------------------------------------------*
*<file>BaseBlock.h</file>
*<summary>
*ブロックのに必要なクラス
*</summary>
----------------------------------------------------------------------------------------------------------------------*/

#pragma once

#include "BaseObject.h"

namespace{
	//ブロックの画像番号
	typedef enum{
		Laby_Road,
		Laby_Wall,
		Laby_Stairs,
		Laby_Nore1,
		Laby_Nore2,
		Laby_CloseDoor,
		Laby_OpenDoor,
		Laby_RubyKey,
		Laby_DiaKey,
		Laby_Nore3,
		Laby_Block1,
		Laby_Block2,
		Laby_Block3,
		Laby_Block4,
		Laby_Nore4,
	}eBlockImageKind;
}

class BaseBlock : public BaseObject{

public:
	/// <summary>
	/// メンバを初期化する
	/// </summary>
	BaseBlock();
	/// <summary>
	/// メンバを初期化する
	/// </summary>
	/// <param name="argPos">座標</param>
	BaseBlock(Position<int> argPos);
	/// <summary>
	/// メモリを確保していた場合は解放する
	/// </summary>
	virtual ~BaseBlock();

	/// <summary>
	/// 1ループ内で必要な更新処理を行う
	/// </summary>
	virtual void Update() = 0;
	/// <summary>
	/// 1ループ内で必要な描画処理を行う
	/// </summary>
	virtual void Draw() = 0;

	/// <summary>
	/// オブジェクトに当たった時のアクション処理
	/// </summary>
	/// <returns>そのオブジェクトが通過できる場合true</returns>
	virtual bool HitAction() = 0;

protected:
	static const int Image_Width;
	static const int Image_Height;

protected:
	bool canMove;					//通れるかどうか
	static int* image;				//画像ポインタ
	int imageKind;					//画像の種類

};

