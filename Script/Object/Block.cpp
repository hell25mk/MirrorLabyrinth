#include "Block.h"
#include "DxLib.h"
#include "../System/Position.h"
#include "../System/SoundPlayer.h"
#include "../Define/Enum.h"

const int Reflect_Space = 14;

Block::Block(Position<int> argPos):BaseBlock(argPos){

	imageKind = Laby_Block1;
	damage = 0;
	passFlag = false;

}

Block::~Block(){
}

void Block::Update(){



}

void Block::Draw(){

	DrawGraph((pos.GetDx() * Block_Size), (pos.GetDy() * Block_Size), image[Laby_Road], TRUE);
	DrawGraph((pos.GetDx() * Block_Size), ((Reflect_Space - pos.GetDy()) * Block_Size), image[imageKind + damage], TRUE);

}

bool Block::HitAction(){

	if(passFlag){
		return passFlag;
	}

	damage++;
	SoundPlayer::GetInstance().PlaySE("Block1");

	passFlag = damage > (Laby_Block4 - Laby_Block1);
	if(passFlag){
		SoundPlayer::GetInstance().PlaySE("Block2");
	}

	return passFlag;
}