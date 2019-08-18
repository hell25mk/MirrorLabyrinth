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
	/// コンストラクタ
	/// </summary>
	BaseObject();
	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="argPos">座標</param>
	BaseObject(Position<int> argPos);
	/// <summary>
	/// デストラクタ
	/// </summary>
	virtual ~BaseObject();

	/// <summary>
	/// 更新処理を行う
	/// </summary>
	virtual void Update() = 0;
	/// <summary>
	/// 描画処理を行う
	/// </summary>
	virtual void Draw() = 0;

protected:
	static const int Block_Size;		//1マスのサイズ

protected:
	Position<int> pos;				//オブジェクトの座標

};

