/*****************************************************************************************************
-----ファイル概要-----
ブロックオブジェクト
基本は通ることができない
ある条件を満たすと通ることができる
******************************************************************************************************/

#pragma once

#include "../Base/BaseBlock.h"

class Block : public BaseBlock{

public:
	/// <summary>
	/// メンバを初期化する
	/// </summary>
	/// <param name="argPos">座標</param>
	Block(Position<int> argPos);
	/// <summary>
	/// メモリを確保していた場合は解放する
	/// </summary>
	virtual ~Block();

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

private:
	int endurance;
	int damage;

};

