#include "BreakWall.h"
#include "DxLib.h"
#include "../System/Position.h"
#include "../System/SoundPlayer.h"

const int Reflect_Space = 14;

C_BreakWall::C_BreakWall(C_Position argPos):C_BaseObject(argPos){

	blockMaterialImage = new int[BlockImage_X_Num * BlockImage_Y_Num];
	LoadDivGraph("Image/Object/LabyBlockMaterial.png", BlockImage_X_Num * BlockImage_Y_Num, BlockImage_X_Num, BlockImage_Y_Num, Block_Size, Block_Size, blockMaterialImage);

	nowWallDamage = 0;
	breakFlag = false;

}

C_BreakWall::~C_BreakWall(){
}

void C_BreakWall::Draw(){

	DrawGraph((pos.x * Block_Size), ((Reflect_Space - pos.y) * Block_Size), blockMaterialImage[BreakWall_Image + nowWallDamage], TRUE);

}

bool C_BreakWall::BWallPosCheck(C_Position const argPos){

	if(pos.x != argPos.x){
		return false;
	}

	if(pos.y != argPos.y){
		return false;
	}

	return true;
}

void C_BreakWall::SetWallDamage(){

	nowWallDamage++;

	C_SoundPlayer::GetInstance().PlaySE("BreakWall1");

	breakFlag = nowWallDamage > 3;

	if(breakFlag){
		C_SoundPlayer::GetInstance().PlaySE("BreakWall2");
	}

}

bool C_BreakWall::GetBreakFlag(){

	return breakFlag;
}