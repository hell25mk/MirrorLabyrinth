#include "Door.h"
#include "DxLib.h"
#include "../System/Position.h"
#include "../Define/Enum.h"

C_Door::C_Door(C_Position<int> argPos, const int *maxKeyNum, int *getKeyNum):C_BaseBlock(argPos){

	this->maxKeyNum = maxKeyNum;
	this->getKeyNum = getKeyNum;
	imageKind = Laby_CloseDoor;
	passFlag = false;

}

C_Door::~C_Door(){
}

void C_Door::Update(){

	if(*maxKeyNum == *getKeyNum){
		passFlag = true;
		imageKind = Laby_OpenDoor;
	}

}

void C_Door::Draw(){

	DrawGraph((pos.x * Block_Size), (pos.y * Block_Size), image[Laby_Road], TRUE);
	DrawGraph((pos.x * Block_Size), (pos.y * Block_Size), image[imageKind], TRUE);
	
}

bool C_Door::HitAction(){

	return passFlag;
}