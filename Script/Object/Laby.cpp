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

	labyVector[argPos.y * Laby_Width + argPos.x] = argBlockKind;

	switch(argBlockKind){
		case Laby_Player:
			blockVector[argPos.y * Laby_Width + argPos.x] = std::shared_ptr<C_BaseBlock>(new C_Road(argPos));
			break;
		case Laby_Wall:
			blockVector[argPos.y * Laby_Width + argPos.x] = std::shared_ptr<C_BaseBlock>(new C_Wall(argPos));
			break;
		case Laby_Road:
			blockVector[argPos.y * Laby_Width + argPos.x] = std::shared_ptr<C_BaseBlock>(new C_Road(argPos));
			break;
		case Laby_Stairs:
			blockVector[argPos.y * Laby_Width + argPos.x] = std::shared_ptr<C_BaseBlock>(new C_Stairs(argPos));
			break;
		case Laby_Door:
			blockVector[argPos.y * Laby_Width + argPos.x] = std::shared_ptr<C_BaseBlock>(new C_Door(argPos, &maxKeyNum, &getKeyNum));
			break;
		case Laby_Key:
			blockVector[argPos.y * Laby_Width + argPos.x] = std::shared_ptr<C_BaseBlock>(new C_Key(argPos, &getKeyNum));
			maxKeyNum++;
			break;
		case Laby_Block:
			blockVector[argPos.y * Laby_Width + argPos.x] = std::shared_ptr<C_BaseBlock>(new C_Block(argPos));
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
	C_Position<int> tempPos;
	int vy[4] = { 1,0,0,-1 };		//y移動量
	int vx[4] = { 0,1,-1,0 };		//x移動量
	//int test[4] = { Laby_Height - 1,Laby_Width - 1,0,0 };		//移動可能範囲

	tempPos.y = argPos.y / Block_Size + vy[argDire];
	tempPos.x = argPos.x / Block_Size + vx[argDire];

#pragma region 参照チェック
	if(tempPos.x < 0){
		return false;
	}
	if(tempPos.x > Laby_Width - 1){
		return false;
	}
	if(tempPos.y < 0){
		return false;
	}
	if(tempPos.y > Laby_Height - 1){
		return false;
	}
#pragma endregion

	if(!blockVector[tempPos.y * Laby_Width + tempPos.x]->HitAction()){
		return false;
	}

	checkFlag = true;

	return checkFlag;
}

bool C_Laby::ClearCheck(C_Position<int> const argPos){

	C_Position<int> tempPos;

	tempPos.x = argPos.x / Block_Size;
	tempPos.y = argPos.y / Block_Size;

	int test = tempPos.y * Laby_Width + tempPos.x;

	if(labyVector[test] != Laby_Stairs){
		return false;
	}

	return true;
}