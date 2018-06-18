#include "Door.h"
#include "DxLib.h"
#include "../System/Position.h"
#include "../Define/Enum.h"

C_Door::C_Door(C_Position argPos):C_BaseObject(argPos){

	blockMaterialImage = new int[BlockImage_X_Num * BlockImage_Y_Num];
	LoadDivGraph("Image/Object/LabyBlockMaterial.png", BlockImage_X_Num * BlockImage_Y_Num, BlockImage_X_Num, BlockImage_Y_Num, Block_Size, Block_Size, blockMaterialImage);

	doorOpenFlag = false;

}

C_Door::~C_Door(){
}

void C_Door::Draw(){

	if(doorOpenFlag){
		DrawGraph((pos.x * Block_Size), (pos.y * Block_Size), blockMaterialImage[Door_Open], TRUE);
	} else{
		DrawGraph((pos.x * Block_Size), (pos.y * Block_Size), blockMaterialImage[Door_Close], TRUE);
	}
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