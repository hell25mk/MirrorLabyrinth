#include "Door.h"
#include "DxLib.h"
#include "../System/Position.h"
#include "../Define/Enum.h"

C_Door::C_Door(C_Position<int> argPos):C_BaseBlock(argPos){

	imageKind = Laby_CloseDoor;
	doorOpenFlag = false;

}

C_Door::~C_Door(){
}

void C_Door::Update(){



}

void C_Door::Draw(){

	DrawGraph((pos.x * Block_Size), (pos.y * Block_Size), image[Laby_Road], TRUE);
	DrawGraph((pos.x * Block_Size), (pos.y * Block_Size), image[imageKind], TRUE);
	
}

void C_Door::HitAction(){



}

void C_Door::SetMaxKeyNum(int argMaxKeyNum){

	maxKeyNum = argMaxKeyNum;

}

void C_Door::CheckDoorOpenFlag(int argNowKeyNum){

	if(maxKeyNum == argNowKeyNum){
		doorOpenFlag = true;
		imageKind = Laby_OpenDoor;
	}

}

bool C_Door::GetDoorOpenFlag(){

	return doorOpenFlag;
}