#include "Block.h"
#include "DxLib.h"
#include "../System/Position.h"
#include "../System/SoundPlayer.h"
#include "../Define/Enum.h"

const int Reflect_Space = 14;

/// <summary>
/// コンストラクタ
/// </summary>
/// <param name="argPos">座標</param>
Block::Block(Position<int> argPos):BaseBlock(argPos){

	imageKind = Laby_Block1;
	endurance = Laby_Block4 - Laby_Block1;
	damage = 0;
	canMove = false;

}

/// <summary>
/// デストラクタ
/// </summary>
Block::~Block(){
}

/// <summary>
/// 更新処理を行う
/// </summary>
void Block::Update(){
}

/// <summary>
/// 描画処理を行う
/// </summary>
void Block::Draw(){

	DrawGraph((pos.GetDx() * Block_Size), (pos.GetDy() * Block_Size), image[Laby_Road], TRUE);
	DrawGraph((pos.GetDx() * Block_Size), ((Reflect_Space - pos.GetDy()) * Block_Size), image[imageKind + damage], TRUE);

}

/// <summary>
/// オブジェクトに当たった時のアクション処理
/// </summary>
/// <returns>そのオブジェクトが通過できる場合true</returns>
bool Block::HitAction(){

	if(canMove){
		return canMove;
	}

	damage++;
	SoundPlayer::GetInstance().PlaySE("Block1");

	//ダメージが耐久値を上回った場合通れるようにする
	canMove = damage > (endurance);
	if(canMove){
		SoundPlayer::GetInstance().PlaySE("Block2");
	}

	return canMove;
}