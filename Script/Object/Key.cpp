#include "Key.h"
#include "DxLib.h"
#include "../System/Position.h"
#include "../System/SoundPlayer.h"

C_Key::C_Key(C_Position<int> argPos):C_BaseBlock(argPos){

	int rand = GetRand(9);

	if(rand % 2){
		keyImageKind = Key_Ruby;
	} else{
		keyImageKind = Key_Diamond;
	}

}

C_Key::~C_Key(){
}

void C_Key::Update(){



}

void C_Key::Draw(){

	//DrawGraph((pos.x * Block_Size), (pos.y * Block_Size), image[keyImageKind], TRUE);

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