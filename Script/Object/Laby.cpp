#include "Laby.h"
#include "DxLib.h"
#include "../Manager/FileManager.h"
#include "../System/Position.h"
#include "../Base/BaseBlock.h"
#include "ObjectList.h"

const int Laby::Laby_Height = 15;
const int Laby::Laby_Width = 20;
const int Image_Width = 5;
const int Image_Height = 3;
const int Block_Size = 32;

//読み込まれなかった場合のテストマップ
//csvファイルに変えたほうがいいかもしれない
std::vector<int> LabySampleVector{
	 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	 1,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,
	 1,0,1,0,1,0,1,0,1,1,1,1,1,1,1,1,1,1,0,1,
	 1,0,1,0,1,0,1,0,1,0,0,0,0,1,0,0,0,1,0,1,
	 1,0,1,0,1,0,1,0,1,0,1,1,0,1,0,1,0,1,0,1,
	 1,0,1,0,1,0,1,0,1,0,0,1,0,1,0,1,0,1,0,1,
	 1,0,0,0,1,0,0,0,1,1,0,1,0,0,0,1,0,0,0,1,
	 1,1,1,1,1,1,1,1,1,1,2,1,1,1,1,1,1,1,1,1,
	 1,0,0,0,1,0,0,0,1,1,0,1,0,0,0,1,0,0,0,1,
	 1,0,1,0,1,0,1,0,1,0,0,1,0,1,0,1,0,1,0,1,
	 1,0,1,0,1,0,1,0,1,0,1,1,0,1,0,1,0,1,0,1,
	 1,0,1,0,1,0,1,0,1,0,0,0,0,1,0,0,0,1,0,1,
	 1,0,1,0,1,0,1,0,1,1,1,1,1,1,1,1,1,1,0,1,
	 1,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,
	 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
};

/// <summary>
/// コンストラクタ
/// </summary>
Laby::Laby(){

	labyVector.resize(Laby_Height * Laby_Width);
	blockVector.resize(Laby_Height * Laby_Width);
	maxKeyNum = 0;
	getKeyNum = 0;

}

/// <summary>
/// デストラクタ
/// </summary>
Laby::~Laby(){
	
	std::vector<int>().swap(labyVector);

}

/// <summary>
/// 更新処理を行う
/// </summary>
void Laby::Update() {

	for (auto itr = blockVector.begin(); itr != blockVector.end();) {

		(*itr)->Update();
		itr++;

	}

}

/// <summary>
/// 描画処理を行う
/// </summary>
void Laby::Draw() {

	for (auto itr = blockVector.begin(); itr != blockVector.end();) {

		(*itr)->Draw();
		itr++;

	}

}

/// <summary>
/// リストにオブジェクトを追加する
/// </summary>
/// <param name="argBlockKind">オブジェクトの種類</param>
/// <param name="argPos">座標</param>
void Laby::PushBlockObject(int argBlockKind, Position<int> argPos){

	int pos = argPos.GetY() * Laby_Width + argPos.GetX();

	//ブロックを登録
	labyVector[pos] = argBlockKind;

	//種類が増えた場合を考えて効率的な方法を見つける必要有り
	switch(argBlockKind){
		case Laby_Player:
			blockVector[pos] = std::shared_ptr<BaseBlock>(new Road(argPos));
			break;
		case Laby_Wall:
			blockVector[pos] = std::shared_ptr<BaseBlock>(new Wall(argPos));
			break;
		case Laby_Road:
			blockVector[pos] = std::shared_ptr<BaseBlock>(new Road(argPos));
			break;
		case Laby_Stairs:
			blockVector[pos] = std::shared_ptr<BaseBlock>(new Stairs(argPos));
			break;
		case Laby_Door:
			blockVector[pos] = std::shared_ptr<BaseBlock>(new Door(argPos, &maxKeyNum, &getKeyNum));
			break;
		case Laby_Key:
			blockVector[pos] = std::shared_ptr<BaseBlock>(new Key(argPos, &getKeyNum));
			maxKeyNum++;
			break;
		case Laby_Block:
			blockVector[pos] = std::shared_ptr<BaseBlock>(new Block(argPos));
			break;
	}

}

/// <summary>
/// プレイヤーの移動先が移動できる場所か確認する
/// </summary>
/// <param name="argDire">プレイヤーの移動方向</param>
/// <param name="argPos">プレイヤーの座標</param>
/// <returns>移動できる場合true</returns>
bool Laby::MoveCheck(int argDire, Position<int> argPos){

	bool checkFlag = false;
	Position<int> tempPos;			//仮座標
	int vy[4] = { 1,0,0,-1 };		//y移動量
	int vx[4] = { 0,1,-1,0 };		//x移動量
	//int test[4] = { Laby_Height - 1,Laby_Width - 1,0,0 };		//移動可能範囲

	tempPos.SetY(argPos.GetY() / Block_Size + vy[argDire]);
	tempPos.SetX(argPos.GetX() / Block_Size + vx[argDire]);

#pragma region 参照チェック
	if(tempPos.GetX() < 0){
		return checkFlag;
	}
	if(tempPos.GetX() > Laby_Width - 1){
		return checkFlag;
	}
	if(tempPos.GetY() < 0){
		return checkFlag;
	}
	if(tempPos.GetY() > Laby_Height - 1){
		return checkFlag;
	}
#pragma endregion

	//移動先が移動不可の場合falseを返す
	int pos = tempPos.GetY() * Laby_Width + tempPos.GetX();
	if(!blockVector[pos]->HitAction()){
		return checkFlag;
	}

	checkFlag = true;

	return checkFlag;
}

/// <summary>
/// プレイヤーが階段に到達したか確認する
/// </summary>
/// <param name="argPos"></param>
/// <returns>プレイヤーの座標が階段と同じならtrue</returns>
bool Laby::ClearCheck(Position<int> const argPos){

	//プレイヤーの現在位置を配列番号に直す
	Position<int> tempPos;
	tempPos = argPos;
	int pos = (tempPos.GetY() / Block_Size) * Laby_Width + (tempPos.GetX() / Block_Size);
	//プレイヤーの座標が階段と同じでなければfalseを返す
	if(labyVector[pos] != Laby_Stairs){
		return false;
	}

	return true;
}