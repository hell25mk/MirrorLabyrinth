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
	/// コンストラクタ
	/// </summary>
	/// <param name="argPos">座標</param>
	Block(Position<int> argPos);
	/// <summary>
	/// デストラクタ
	/// </summary>
	virtual ~Block();

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

private:
	int endurance;			//耐久値
	int damage;				//受けたダメージ

};

