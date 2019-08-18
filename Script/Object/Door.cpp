#include "Door.h"
#include "DxLib.h"
#include "../System/Position.h"
#include "../Define/Enum.h"

/// <summary>
/// コンストラクタ
/// </summary>
/// <param name="argPos">座標</param>
/// <param name="maxKeyNum">鍵の最大数を格納したポインタ</param>
/// <param name="getKeyNum">取得した鍵の数を格納したポインタ</param>
Door::Door(Position<int> argPos, const int *maxKeyNum, int *getKeyNum):BaseBlock(argPos){

	this->maxKeyNum = maxKeyNum;
	this->getKeyNum = getKeyNum;
	imageKind = Laby_CloseDoor;
	canMove = false;

}

/// <summary>
/// デストラクタ
/// </summary>
Door::~Door(){
}

/// <summary>
/// 更新処理を行う
/// </summary>
void Door::Update(){

	//取得した鍵の数が鍵の最大数になった場合と通れるようにする
	if(*maxKeyNum == *getKeyNum){
		canMove = true;
		imageKind = Laby_OpenDoor;
	}

}

/// <summary>
/// 描画処理を行う
/// </summary>
void Door::Draw(){

	DrawGraph((pos.GetDx() * Block_Size), (pos.GetDy() * Block_Size), image[Laby_Road], TRUE);
	DrawGraph((pos.GetDx() * Block_Size), (pos.GetDy() * Block_Size), image[imageKind], TRUE);
	
}

/// <summary>
/// オブジェクトに当たった時のアクション処理
/// </summary>
/// <returns>そのオブジェクトが通過できる場合true</returns>
bool Door::HitAction(){

	return canMove;
}