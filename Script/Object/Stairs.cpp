#include "Stairs.h"
#include "../System/SoundPlayer.h"
#include "../Define/Enum.h"

C_Stairs::C_Stairs(C_Position<int> argPos):C_BaseBlock(argPos){

	imageKind = Laby_Stairs;

}

C_Stairs::~C_Stairs(){
}

void C_Stairs::Update(){



}

void C_Stairs::Draw(){

	DrawGraph((pos.x * Block_Size), (pos.y * Block_Size), image[Laby_Road], TRUE);
	DrawGraph((pos.x * Block_Size), (pos.y * Block_Size), image[imageKind], TRUE);

}

bool C_Stairs::HitAction(){

	return passFlag;
}
