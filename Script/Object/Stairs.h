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
	/// メンバを初期化する
	/// </summary>
	/// <param name="argPos">座標</param>
	Stairs(Position<int> argPos);
	/// <summary>
	/// メモリを確保していた場合は解放する
	/// </summary>
	~Stairs();

	/// <summary>
	/// 1ループ内で必要な更新処理を行う
	/// </summary>
	virtual void Update() override;
	/// <summary>
	/// 1ループ内で必要な描画処理を行う
	/// </summary>
	virtual void Draw() override;

	/// <summary>
	/// オブジェクトに当たった時のアクション処理
	/// </summary>
	/// <returns>そのオブジェクトが通過できる場合true</returns>
	virtual bool HitAction() override;

};

