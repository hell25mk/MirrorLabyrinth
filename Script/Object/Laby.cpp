#include "Laby.h"
#include "DxLib.h"
#include "../Manager/FileManager.h"
#include "../System/Position.h"
#include "../Base/BaseBlock.h"
#include "ObjectList.h"

const int C_Laby::Laby_Height = 15;
const int C_Laby::Laby_Width = 20;
const int Image_Width = 5;
const int Image_Height = 3;
const int Block_Size = 32;

//読み込まれなかった場合のテストマップ
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

C_Laby::C_Laby(){

	labyVector.resize(Laby_Height * Laby_Width);
	blockVector.resize(Laby_Height * Laby_Width);
	maxKeyNum = 0;
	getKeyNum = 0;

}

C_Laby::~C_Laby(){
	
	std::vector<int>().swap(labyVector);

}

void C_Laby::PushBlockObject(int argBlockKind, C_Position<int> argPos){

	//ブロックを登録
	labyVector[argPos.GetY() * Laby_Width + argPos.GetX()] = argBlockKind;

	switch(argBlockKind){
		case Laby_Player:
			blockVector[argPos.GetY() * Laby_Width + argPos.GetX()] = std::shared_ptr<C_BaseBlock>(new C_Road(argPos));
			break;
		case Laby_Wall:
			blockVector[argPos.GetY() * Laby_Width + argPos.GetX()] = std::shared_ptr<C_BaseBlock>(new C_Wall(argPos));
			break;
		case Laby_Road:
			blockVector[argPos.GetY() * Laby_Width + argPos.GetX()] = std::shared_ptr<C_BaseBlock>(new C_Road(argPos));
			break;
		case Laby_Stairs:
			blockVector[argPos.GetY() * Laby_Width + argPos.GetX()] = std::shared_ptr<C_BaseBlock>(new C_Stairs(argPos));
			break;
		case Laby_Door:
			blockVector[argPos.GetY() * Laby_Width + argPos.GetX()] = std::shared_ptr<C_BaseBlock>(new C_Door(argPos, &maxKeyNum, &getKeyNum));
			break;
		case Laby_Key:
			blockVector[argPos.GetY() * Laby_Width + argPos.GetX()] = std::shared_ptr<C_BaseBlock>(new C_Key(argPos, &getKeyNum));
			maxKeyNum++;
			break;
		case Laby_Block:
			blockVector[argPos.GetY() * Laby_Width + argPos.GetX()] = std::shared_ptr<C_BaseBlock>(new C_Block(argPos));
			break;
	}

}

void C_Laby::Update(){

	for(auto itr = blockVector.begin(); itr != blockVector.end();){

		(*itr)->Update();
		itr++;

	}

}

void C_Laby::Draw(){

	for(auto itr = blockVector.begin(); itr != blockVector.end();){

		(*itr)->Draw();
		itr++;

	}

}

bool C_Laby::MoveCheck(int argDire, C_Position<int> argPos){

	bool checkFlag = false;
	C_Position<int> tempPos;		//仮座標
	int vy[4] = { 1,0,0,-1 };		//y移動量
	int vx[4] = { 0,1,-1,0 };		//x移動量
	//int test[4] = { Laby_Height - 1,Laby_Width - 1,0,0 };		//移動可能範囲

	tempPos.SetY(argPos.GetY() / Block_Size + vy[argDire]);
	tempPos.SetX(argPos.GetX() / Block_Size + vx[argDire]);

#pragma region 参照チェック
	if(tempPos.GetX() < 0){
		return false;
	}
	if(tempPos.GetX() > Laby_Width - 1){
		return false;
	}
	if(tempPos.GetY() < 0){
		return false;
	}
	if(tempPos.GetY() > Laby_Height - 1){
		return false;
	}
#pragma endregion

	if(!blockVector[tempPos.GetY() * Laby_Width + tempPos.GetX()]->HitAction()){
		return false;
	}

	checkFlag = true;

	return checkFlag;
}

bool C_Laby::ClearCheck(C_Position<int> const argPos){

	C_Position<int> tempPos;

	tempPos = argPos;

	int test = (tempPos.GetY() / Block_Size) * Laby_Width + (tempPos.GetX() / Block_Size);

	if(labyVector[test] != Laby_Stairs){
		return false;
	}

	return true;
}