/*****************************************************************************************************
-----ファイル概要-----
迷路オブジェクト
******************************************************************************************************/

#pragma once

#include "../System/Position.h"
#include <memory>
#include <vector>

class BaseBlock;
class Player;
class Mirror;

class Laby {

public:
	/// <summary>
	/// メンバを初期化する
	/// </summary>
	Laby();
	/// <summary>
	/// メモリを確保していた場合は解放する
	/// </summary>
	~Laby();

	/// <summary>
	/// 1ループ内で必要な更新処理を行う
	/// </summary>
	void Update();
	/// <summary>
	/// 1ループ内で必要な描画処理を行う
	/// </summary>
	void Draw();

	/// <summary>
	/// リストにオブジェクトを追加する
	/// </summary>
	/// <param name="argBlockKind">オブジェクトの種類</param>
	/// <param name="argPos">座標</param>
	void PushBlockObject(int argBlockKind, Position<int> argPos);
	/// <summary>
	/// プレイヤーの移動先が移動できる場所か確認する
	/// </summary>
	/// <param name="argDire">プレイヤーの移動方向</param>
	/// <param name="argPos">プレイヤーの座標</param>
	/// <returns>移動できる場合true</returns>
	bool MoveCheck(int argDire, Position<int> argPos);
	/// <summary>
	/// <summary>
	/// プレイヤーが階段に到達したか確認する
	/// </summary>
	/// <param name="argPos"></param>
	/// <returns>プレイヤーの座標が階段と同じならtrue</returns>
	bool ClearCheck(Position<int> argPos);

private:
	static const int Laby_Height;		//迷路の縦のマス目数
	static const int Laby_Width;		//迷路の横のマス目数

	//オブジェクトの種類の列挙
	typedef enum {
		Laby_Player,
		Laby_Wall,
		Laby_Road,
		Laby_Stairs,
		Laby_Door,
		Laby_Key,
		Laby_Block,

		Laby_Nore,
	}eObjectKind;

private:
	Position<int> pos;
	std::vector<int> labyVector;
	std::vector<std::shared_ptr<BaseBlock>> blockVector;
	int maxKeyNum;
	int getKeyNum;

};

