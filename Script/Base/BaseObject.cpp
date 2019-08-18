#include "BaseObject.h"

const int BaseObject::Block_Size = 32;

/// <summary>
/// コンストラクタ
/// </summary>
BaseObject::BaseObject() : pos(){
}

/// <summary>
/// コンストラクタ
/// </summary>
/// <param name="argPos">座標</param>
BaseObject::BaseObject(Position<int> const argPos){

	//座標の格納
	pos = argPos;

}

/// <summary>
/// デストラクタ
/// </summary>
BaseObject::~BaseObject(){
}
