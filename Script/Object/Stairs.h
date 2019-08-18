/*****************************************************************************************************
-----ファイル概要-----
階段オブジェクト
辿り着くと次のフロアへ移動できる
次フロアへの移動はLabyで管理
******************************************************************************************************/

#pragma once

#include "../Base/BaseBlock.h"

class Stairs : public BaseBlock{

public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="argPos">座標</param>
	Stairs(Position<int> argPos);
	/// <summary>
	/// デストラクタ
	/// </summary>
	~Stairs();

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

