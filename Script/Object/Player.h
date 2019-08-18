/*****************************************************************************************************
-----ファイル概要-----
プレイヤーのクラス
******************************************************************************************************/

#pragma once

#include "../Base/BaseCharacter.h"

class Animation;

class Player : public BaseCharacter{

public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="argPos">座標</param>
	Player(Position<int> argPos);
	/// <summary>
	/// デストラクタ
	/// </summary>
	virtual ~Player();

	/// <summary>
	/// 更新処理を行う
	/// </summary>
	virtual void Update() override;
	/// <summary>
	/// 描画処理を行う
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

