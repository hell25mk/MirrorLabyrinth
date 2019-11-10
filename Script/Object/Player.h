/*--------------------------------------------------------------------------------------------------------------------*
*<file>Player.h</file>
*<summary>
*操作プレイヤーに必要なクラス
*</summary>
----------------------------------------------------------------------------------------------------------------------*/

#pragma once

#include "../Base/BaseCharacter.h"

class Animation;

class Player : public BaseCharacter{

public:
	/// <summary>
	/// メンバを初期化する
	/// </summary>
	/// <param name="argPos">座標</param>
	Player(Position<int> argPos);
	/// <summary>
	/// メモリを確保していた場合は解放する
	/// </summary>
	virtual ~Player();

	/// <summary>
	/// 1ループ内で必要な更新処理を行う
	/// </summary>
	virtual void Update() override;
	/// <summary>
	/// 1ループ内で必要な描画処理を行う
	/// </summary>
	virtual void Draw() override;

	/// <summary>
	/// 座標を更新する
	/// </summary>
	/// <param name="argMoveDire">移動する方向</param>
	void Move(int argMoveDire);
	/// <summary>
	/// 向きを更新する
	/// </summary>
	/// <param name="argMoveDire">移動する方向</param>
	void Direction(int argMoveDire);
	/// <summary>
	/// 座標を取得する
	/// </summary>
	/// <returns>プレイヤーの座標</returns>
	Position<int> GetPosition();
	/// <summary>
	/// 向きを取得する
	/// </summary>
	/// <returns>プレイヤーの向き</returns>
	int GetDirection();

private:
	Animation* animation;

};

