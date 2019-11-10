#include "BaseObject.h"

const int BaseObject::Block_Size = 32;

/// <summary>
/// メンバを初期化する
/// </summary>
BaseObject::BaseObject() : pos(){
}

/// <summary>
/// メンバを初期化する
/// </summary>
/// <param name="argPos">座標</param>
BaseObject::BaseObject(Position<int> const argPos){

	//座標の格納
	pos = argPos;

}

/// <summary>
/// メモリを確保していた場合は解放する
/// </summary>
BaseObject::~BaseObject(){
}
