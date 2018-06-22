#include "Door.h"
#include "DxLib.h"
#include "../System/Position.h"
#include "../Define/Enum.h"

C_Door::C_Door(C_Position<int> argPos):C_BaseBlock(argPos){

	doorOpenFlag = false;

}

C_Door::~C_Door(){
}

void C_Door::Update(){



}

void C_Door::Draw(){

	/*if(doorOpenFlag){
		DrawGraph((pos.x * Block_Size), (pos.y * Block_Size), image[Door_Open], TRUE);
	} else{
		DrawGraph((pos.x * Block_Size), (pos.y * Block_Size), image[Door_Close], TRUE);
	}*/
}

void C_Door::SetMaxKeyNum(int argMaxKeyNum){

	maxKeyNum = argMaxKeyNum;

}

void C_Door::CheckDoorOpenFlag(int argNowKeyNum){

	if(maxKeyNum == argNowKeyNum){
		doorOpenFlag = true;
	}

}

bool C_Door::GetDoorOpenFlag(){

	return doorOpenFlag;
}