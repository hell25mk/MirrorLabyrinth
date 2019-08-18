/*****************************************************************************************************
-----ファイル概要-----
道オブジェクト
通れる
******************************************************************************************************/

#pragma once

#include "../Base/BaseBlock.h"

class Road : public BaseBlock{

public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="argPos">座標</param>
	Road(Position<int> argPos);
	/// <summary>
	/// デストラクタ
	/// </summary>
	~Road();

	/// <summary>
	/// 更新処理を行う
	/// </summary>
	virtual void Update() override;
	/// <summary>
	/// 描画処理を行う
	/// </summary>
	virtual void Draw() override;

	/// <summary>
	/// オブジェクトに当たった時のアクション処理
	/// </summary>
	/// <returns>そのオブジェクトが通過できる場合true</returns>
	virtual bool HitAction() override;

};

