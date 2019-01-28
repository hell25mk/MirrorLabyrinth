#include "Key.h"
#include "DxLib.h"
#include "../System/Position.h"
#include "../System/SoundPlayer.h"
#include "../Define/Enum.h"

Key::Key(Position<int> argPos, int *getKeyNum):BaseBlock(argPos){

	this->getKeyNum = getKeyNum;
	int rand = GetRand(9);

	if(rand % 2){
		imageKind = Laby_RubyKey;
	} else{
		imageKind = Laby_DiaKey;
	}

	getFlag = false;

}

Key::~Key(){
}

void Key::Update(){



}

void Key::Draw(){

	DrawGraph((pos.GetDx() * Block_Size), (pos.GetDy() * Block_Size), image[Laby_Road], TRUE);
	if(!getFlag){
		DrawGraph((pos.GetDx() * Block_Size), (pos.GetDy() * Block_Size), image[imageKind], TRUE);
	}

}

bool Key::HitAction(){

	if(getFlag){
		return passFlag;
	}

	*getKeyNum += 1;
	SoundPlayer::GetInstance().PlaySE("Key");

	getFlag = true;

	return passFlag;
}