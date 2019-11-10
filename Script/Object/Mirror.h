/*****************************************************************************************************
-----ファイル概要-----
プレイヤーの投影
プレイヤーと逆側の迷路に配置される
左右は一致
映ったり映らなかったりする
******************************************************************************************************/

#pragma once

#include "../Base/BaseCharacter.h"

class Player;

class Mirror : public BaseCharacter{

public:
	/// <summary>
	/// メンバを初期化する
	/// </summary>
	/// <param name="player">プレイヤーを格納したポインタ</param>
	Mirror(Player* player);
	/// <summary>
	/// メモリを確保していた場合は解放する
	/// </summary>
	virtual ~Mirror();

	/// <summary>
	/// 1ループ内で必要な更新処理を行う
	/// </summary>
	virtual void Update() override;
	/// <summary>
	/// 1ループ内で必要な描画処理を行う
	/// </summary>
	virtual void Draw() override;

	/// <summary>
/// プレイヤーの座標に対する場所に移動する
/// </summary>
	void Move();
	/// <summary>
	/// プレイヤーの向きに対する向きに変更する
	/// </summary>
	void Direction();
	/// <summary>
	/// 点滅しているかどうかを切り替える
	/// </summary>
	void Fhashing();

private:
	Player* player;
	int flashTime;
	bool willFlash;

};