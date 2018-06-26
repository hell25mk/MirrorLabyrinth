#include "Key.h"
#include "DxLib.h"
#include "../System/Position.h"
#include "../System/SoundPlayer.h"
#include "../Define/Enum.h"

C_Key::C_Key(C_Position<int> argPos, int *getKeyNum):C_BaseBlock(argPos){

	this->getKeyNum = getKeyNum;
	int rand = GetRand(9);

	if(rand % 2){
		imageKind = Laby_RubyKey;
	} else{
		imageKind = Laby_DiaKey;
	}

	getFlag = false;

}

C_Key::~C_Key(){
}

void C_Key::Update(){



}

void C_Key::Draw(){

	DrawGraph((pos.x * Block_Size), (pos.y * Block_Size), image[Laby_Road], TRUE);
	if(!getFlag){
		DrawGraph((pos.x * Block_Size), (pos.y * Block_Size), image[imageKind], TRUE);
	}

}

bool C_Key::HitAction(){

	if(getFlag){
		return passFlag;
	}

	*getKeyNum += 1;
	C_SoundPlayer::GetInstance().PlaySE("Key");

	getFlag = true;

	return passFlag;
}