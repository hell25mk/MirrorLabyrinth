/*****************************************************************************************************
-----ファイル概要-----
鍵オブジェクト
全て取得することでドアを開くことができる
******************************************************************************************************/

#pragma once

#include "../Base/BaseBlock.h"

class Key : public BaseBlock{

public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="argPos">座標</param>
	/// <param name="getKeyNum">取得した鍵の数を格納したポインタ</param>
	Key(Position<int> argPos,int* getKeyNum);
	/// <summary>
	/// デストラクタ
	/// </summary>
	virtual ~Key();

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
	bool isGet;
	int* getKeyNum;

};

