#include "Block.h"
#include "DxLib.h"
#include "../System/Position.h"
#include "../System/SoundPlayer.h"

const int Reflect_Space = 14;

C_Block::C_Block(C_Position<int> argPos):C_BaseBlock(argPos){

	nowWallDamage = 0;
	breakFlag = false;

}

C_Block::~C_Block(){
}

void C_Block::Update(){



}

void C_Block::Draw(){

	DrawGraph((pos.x * Block_Size), ((Reflect_Space - pos.y) * Block_Size), image[Block_Image + nowWallDamage], TRUE);

}

bool C_Block::BlockPosCheck(C_Position<int> const argPos){

	if(pos.x != argPos.x){
		return false;
	}

	if(pos.y != argPos.y){
		return false;
	}

	return true;
}

void C_Block::SetWallDamage(){

	nowWallDamage++;

	C_SoundPlayer::GetInstance().PlaySE("Block1");

	breakFlag = nowWallDamage > 3;

	if(breakFlag){
		C_SoundPlayer::GetInstance().PlaySE("Block2");
	}

}

bool C_Block::GetBreakFlag(){

	return breakFlag;
}