#include "BreakWall.h"
#include "DxLib.h"
#include "../System/Position.h"
#include "../System/SoundPlayer.h"

const int Reflect_Space = 14;

C_BreakWall::C_BreakWall(C_Position argPos):C_BaseBlock(argPos){

	nowWallDamage = 0;
	breakFlag = false;

}

C_BreakWall::~C_BreakWall(){
}

void C_BreakWall::Update(){



}

void C_BreakWall::Draw(){

	DrawGraph((pos.x * Block_Size), ((Reflect_Space - pos.y) * Block_Size), image[BreakWall_Image + nowWallDamage], TRUE);

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