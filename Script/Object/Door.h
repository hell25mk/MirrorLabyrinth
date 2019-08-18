/*****************************************************************************************************
-----ファイル概要-----
ドアオブジェクト
鍵を全て取得しないと通ることができない
******************************************************************************************************/

#pragma once

#include "../Base/BaseBlock.h"

class Door : public BaseBlock{

public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="argPos">座標</param>
	/// <param name="maxKeyNum">鍵の最大数を格納したポインタ</param>
	/// <param name="getKeyNum">取得した鍵の数を格納したポインタ</param>
	Door(Position<int> argPos, const int* maxKeyNum, int* getKeyNum);
	/// <summary>
	/// デストラクタ
	/// </summary>
	virtual ~Door();

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
	const int* maxKeyNum;
	int* getKeyNum;

};

