#include "Stairs.h"
#include "../System/SoundPlayer.h"
#include "../Define/Enum.h"

const int Laby_Height = 15;

/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="argPos">座標</param>
Stairs::Stairs(Position<int> argPos):BaseBlock(argPos){

	imageKind = Laby_Stairs;

}

/// <summary>
/// デストラクタ
/// </summary>
Stairs::~Stairs(){
}

/// <summary>
/// 更新処理を行う
/// </summary>
void Stairs::Update(){
}

/// <summary>
/// 描画処理を行う
/// </summary>
void Stairs::Draw(){

	DrawGraph((pos.GetDx() * Block_Size), (pos.GetDy() * Block_Size), image[Laby_Road], TRUE);
	DrawGraph((pos.GetDx() * Block_Size), (pos.GetDy() * Block_Size), image[imageKind], TRUE);

}

/// <summary>
/// オブジェクトに当たった時のアクション処理
/// </summary>
/// <returns>そのオブジェクトが通過できる場合true</returns>
bool Stairs::HitAction(){

	return canMove;
}
