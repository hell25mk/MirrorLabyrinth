#include "Key.h"
#include "DxLib.h"
#include "../System/Position.h"
#include "../System/SoundPlayer.h"
#include "../Define/Enum.h"

/// コンストラクタ
/// </summary>
/// <param name="argPos">座標</param>
/// <param name="getKeyNum">取得した鍵の数を格納したポインタ</param>
Key::Key(Position<int> argPos, int *getKeyNum):BaseBlock(argPos){

	this->getKeyNum = getKeyNum;

	//ランダムでキーの色を変更する(ゲーム自体に影響はない)
	int rand = GetRand(9);
	if(rand % 2){
		imageKind = Laby_RubyKey;
	} else{
		imageKind = Laby_DiaKey;
	}

	isGet = false;

}

/// <summary>
/// デストラクタ
/// </summary>
Key::~Key(){
}

/// <summary>
/// 更新処理を行う
/// </summary>
void Key::Update(){
}

/// <summary>
/// 描画処理を行う
/// </summary>
void Key::Draw(){

	DrawGraph((pos.GetDx() * Block_Size), (pos.GetDy() * Block_Size), image[Laby_Road], TRUE);

	//鍵が入手済みでないなら描画する
	if(!isGet){
		DrawGraph((pos.GetDx() * Block_Size), (pos.GetDy() * Block_Size), image[imageKind], TRUE);
	}

}
/// <summary>
/// オブジェクトに当たった時のアクション処理
/// </summary>
/// <returns>そのオブジェクトが通過できる場合true</returns>
bool Key::HitAction(){

	if(isGet){
		return canMove;
	}

	//取得した鍵の数を増やす
	*getKeyNum += 1;
	SoundPlayer::GetInstance().PlaySE("Key");

	isGet = true;

	return canMove;
}