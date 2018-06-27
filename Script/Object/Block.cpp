#include "Block.h"
#include "DxLib.h"
#include "../System/Position.h"
#include "../System/SoundPlayer.h"
#include "../Define/Enum.h"

const int Reflect_Space = 14;

C_Block::C_Block(C_Position<int> argPos):C_BaseBlock(argPos){

	imageKind = Laby_Block1;
	damage = 0;
	passFlag = false;

}

C_Block::~C_Block(){
}

void C_Block::Update(){



}

void C_Block::Draw(){

	DrawGraph((pos.x * Block_Size), (pos.y * Block_Size), image[Laby_Road], TRUE);
	DrawGraph((pos.x * Block_Size), ((Reflect_Space - pos.y) * Block_Size), image[imageKind + damage], TRUE);

}

bool C_Block::HitAction(){

	if(passFlag){
		return passFlag;
	}

	damage++;
	C_SoundPlayer::GetInstance().PlaySE("Block1");

	passFlag = damage > (Laby_Block4 - Laby_Block1);
	if(passFlag){
		C_SoundPlayer::GetInstance().PlaySE("Block2");
	}

	return passFlag;
}