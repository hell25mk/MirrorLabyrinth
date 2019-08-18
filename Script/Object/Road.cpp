#include "Road.h"
#include "../System/Position.h"
#include "../Define/Enum.h"

/// <summary>
/// コンストラクタ
/// </summary>
/// <param name="argPos">座標</param>
Road::Road(Position<int> argPos):BaseBlock(argPos){

	imageKind = Laby_Road;

}

/// <summary>
/// デストラクタ
/// </summary>
Road::~Road(){
}

/// <summary>
/// 更新処理を行う
/// </summary>
void Road::Update(){
}

/// <summary>
/// 描画処理を行う
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