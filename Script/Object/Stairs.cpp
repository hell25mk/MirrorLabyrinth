#include "Stairs.h"
#include "../System/SoundPlayer.h"
#include "../Define/Enum.h"

const int Laby_Height = 15;

/// <summary>
/// メンバを初期化する
/// </summary>
/// <param name="argPos">座標</param>
Stairs::Stairs(Position<int> argPos):BaseBlock(argPos){

	imageKind = Laby_Stairs;

}

/// <summary>
/// メモリを確保していた場合は解放する
/// </summary>
Stairs::~Stairs(){
}

/// <summary>
/// 1ループ内で必要な更新処理を行う
/// </summary>
void Stairs::Update(){
}

/// <summary>
/// 1ループ内で必要な描画処理を行う
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
