/*****************************************************************************************************
-----ファイル概要-----
オブジェクトの基底クラス
******************************************************************************************************/

#pragma once

#include "DxLib.h"
#include "../System/Position.h"

class BaseObject{

public:
	/// <summary>
	/// メンバを初期化する
	/// </summary>
	BaseObject();
	/// <summary>
	/// メンバを初期化する
	/// </summary>
	/// <param name="argPos">座標</param>
	BaseObject(Position<int> argPos);
	/// <summary>
	/// メモリを確保していた場合は解放する
	/// </summary>
	virtual ~BaseObject();

	/// <summary>
	/// 1ループ内で必要な更新処理を行う
	/// </summary>
	virtual void Update() = 0;
	/// <summary>
	/// 1ループ内で必要な描画処理を行う
	/// </summary>
	virtual void Draw() = 0;

protected:
	static const int Block_Size;		//1マスのサイズ

protected:
	Position<int> pos;				//オブジェクトの座標

};

