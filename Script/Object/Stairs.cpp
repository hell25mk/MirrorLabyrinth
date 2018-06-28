#include "Stairs.h"
#include "../System/SoundPlayer.h"
#include "../Define/Enum.h"

const int Laby_Height = 15;

C_Stairs::C_Stairs(C_Position<int> argPos):C_BaseBlock(argPos){

	imageKind = Laby_Stairs;

}

C_Stairs::~C_Stairs(){
}

void C_Stairs::Update(){



}

void C_Stairs::Draw(){

	DrawGraph((pos.GetDx() * Block_Size), (pos.GetDy() * Block_Size), image[Laby_Road], TRUE);

	//ˆêŽž“I
	DrawGraph((pos.GetDx() * Block_Size), (pos.GetDy() * Block_Size), image[imageKind], TRUE);

}

bool C_Stairs::HitAction(){

	return passFlag;
}
