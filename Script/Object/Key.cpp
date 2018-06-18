#include "Key.h"
#include "DxLib.h"
#include "../System/Position.h"
#include "../System/SoundPlayer.h"
#include <time.h>

C_Key::C_Key(C_Position argPos):C_BaseObject(argPos){

	blockMaterialImage = new int[BlockImage_X_Num * BlockImage_Y_Num];
	LoadDivGraph("Image/Object/LabyBlockMaterial.png", BlockImage_X_Num * BlockImage_Y_Num, BlockImage_X_Num, BlockImage_Y_Num, Block_Size, Block_Size, blockMaterialImage);

	SRand((int)time(NULL));
	int rand = GetRand(9);

	if(rand % 2){
		keyImageKind = Key_Ruby;
	} else{
		keyImageKind = Key_Diamond;
	}

}

C_Key::~C_Key(){
}

void C_Key::Draw(){

	DrawGraph((pos.x * Block_Size), (pos.y * Block_Size), blockMaterialImage[keyImageKind], TRUE);

}

bool C_Key::KeyPosCheck(C_Position const argPos){

	if(pos.x != argPos.x){
		return false;
	}

	if(pos.y != argPos.y){
		return false;
	}

	C_SoundPlayer::GetInstance().PlaySE("Key");

	return true;
}