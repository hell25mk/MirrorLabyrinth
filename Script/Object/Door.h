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
	/// メンバを初期化する
	/// </summary>
	/// <param name="argPos">座標</param>
	/// <param name="maxKeyNum">鍵の最大数を格納したポインタ</param>
	/// <param name="getKeyNum">取得した鍵の数を格納したポインタ</param>
	Door(Position<int> argPos, const int* maxKeyNum, int* getKeyNum);
	/// <summary>
	/// メモリを確保していた場合は解放する
	/// </summary>
	virtual ~Door();

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
	const int* maxKeyNum;
	int* getKeyNum;

};

