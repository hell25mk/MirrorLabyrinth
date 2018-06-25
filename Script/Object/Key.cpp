#include "Key.h"
#include "DxLib.h"
#include "../System/Position.h"
#include "../System/SoundPlayer.h"
#include "../Define/Enum.h"

C_Key::C_Key(C_Position<int> argPos):C_BaseBlock(argPos){

	int rand = GetRand(9);

	if(rand % 2){
		imageKind = Laby_RubyKey;
	} else{
		imageKind = Laby_DiaKey;
	}

}

C_Key::~C_Key(){
}

void C_Key::Update(){



}

void C_Key::Draw(){

	DrawGraph((pos.x * Block_Size), (pos.y * Block_Size), image[Laby_Road], TRUE);
	DrawGraph((pos.x * Block_Size), (pos.y * Block_Size), image[imageKind], TRUE);

}

void C_Key::HitAction(){



}

bool C_Key::KeyPosCheck(C_Position<int> argPos){

	if(pos.x != argPos.x){
		return false;
	}

	if(pos.y != argPos.y){
		return false;
	}

	C_SoundPlayer::GetInstance().PlaySE("Key");

	return true;
}