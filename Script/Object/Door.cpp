#include "Door.h"
#include "DxLib.h"
#include "../System/Position.h"
#include "../Define/Enum.h"

C_Door::C_Door(C_Position<int> argPos):C_BaseBlock(argPos){

	imageKind = Laby_CloseDoor;
	passFlag = false;

}

C_Door::~C_Door(){
}

void C_Door::Update(){



}

void C_Door::Draw(){

	DrawGraph((pos.x * Block_Size), (pos.y * Block_Size), image[Laby_Road], TRUE);
	DrawGraph((pos.x * Block_Size), (pos.y * Block_Size), image[imageKind], TRUE);
	
}

bool C_Door::HitAction(){

	/*if(maxKeyNum == argNowKeyNum){
		passFlag = true;
		imageKind = Laby_OpenDoor;
	}*/
	imageKind = Laby_OpenDoor;
	passFlag = true;

	return passFlag;
}

void C_Door::SetMaxKeyNum(int argMaxKeyNum){

	maxKeyNum = argMaxKeyNum;

}

void C_Door::CheckDoorOpenFlag(int argNowKeyNum){

	if(maxKeyNum == argNowKeyNum){
		passFlag = true;
		imageKind = Laby_OpenDoor;
	}

}

bool C_Door::GetDoorOpenFlag(){

	return passFlag;
}