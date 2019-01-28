#include "Door.h"
#include "DxLib.h"
#include "../System/Position.h"
#include "../Define/Enum.h"

Door::Door(Position<int> argPos, const int *maxKeyNum, int *getKeyNum):BaseBlock(argPos){

	this->maxKeyNum = maxKeyNum;
	this->getKeyNum = getKeyNum;
	imageKind = Laby_CloseDoor;
	passFlag = false;

}

Door::~Door(){
}

void Door::Update(){

	if(*maxKeyNum == *getKeyNum){
		passFlag = true;
		imageKind = Laby_OpenDoor;
	}

}

void Door::Draw(){

	DrawGraph((pos.GetDx() * Block_Size), (pos.GetDy() * Block_Size), image[Laby_Road], TRUE);
	DrawGraph((pos.GetDx() * Block_Size), (pos.GetDy() * Block_Size), image[imageKind], TRUE);
	
}

bool Door::HitAction(){

	return passFlag;
}