#include "Road.h"
#include "../System/Position.h"
#include "../Define/Enum.h"

/// <summary>
/// メンバを初期化する
/// </summary>
/// <param name="argPos">座標</param>
Road::Road(Position<int> argPos):BaseBlock(argPos){

	imageKind = Laby_Road;

}

/// <summary>
/// メモリを確保していた場合は解放する
/// </summary>
Road::~Road(){
}

/// <summary>
/// 1ループ内で必要な更新処理を行う
/// </summary>
void Road::Update(){
}

/// <summary>
/// 1ループ内で必要な描画処理を行う
/// </summary>
void Road::Draw(){

	DrawGraph((pos.GetDx() * Block_Size), (pos.GetDy() * Block_Size), image[imageKind], TRUE);

}

/// <summary>
/// オブジェクトに当たった時のアクション処理
/// </summary>
/// <returns>そのオブジェクトが通過できる場合true</returns>
bool Road::HitAction(){

	return canMove;
}