#include "Wall.h"
#include "../Define/Enum.h"

const int Laby_Height = 15;
const int Laby_Width = 20;

/// <summary>
/// メンバを初期化する
/// </summary>
/// <param name="argPos">座標</param>
Wall::Wall(Position<int> argPos):BaseBlock(argPos){

	imageKind = Laby_Wall;
	canMove = false;

}

/// <summary>
/// メモリを確保していた場合は解放する
/// </summary>
Wall::~Wall(){
}

/// <summary>
/// 1ループ内で必要な更新処理を行う
/// </summary>
void Wall::Update(){
}

/// <summary>
/// 1ループ内で必要な描画処理を行う
/// </summary>
void Wall::Draw(){

	DrawGraph((pos.GetDx() * Block_Size), (pos.GetDy() * Block_Size), image[Laby_Road], TRUE);

	//外壁
	if(pos.GetY() == 0 || pos.GetY() == (Laby_Height - 1) || pos.GetX() == 0 || pos.GetX() == (Laby_Width - 1)){
		DrawGraph((pos.GetDx() * Block_Size), (pos.GetDy() * Block_Size), image[imageKind], TRUE);
		return;
	}

	//中心から下かどうか
	if((pos.GetY()) > (Laby_Height / 2)){
		DrawGraph((pos.GetDx() * Block_Size), (pos.GetDy() * Block_Size), image[Laby_Road], TRUE);
		return;
	}

	DrawGraph((pos.GetDx() * Block_Size), (pos.GetDy() * Block_Size), image[imageKind], TRUE);

}
/// <summary>
/// オブジェクトに当たった時のアクション処理
/// </summary>
/// <returns>そのオブジェクトが通過できる場合true</returns>
bool Wall::HitAction(){

	return canMove;
}
