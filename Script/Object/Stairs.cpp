#include "Stairs.h"
#include "../System/SoundPlayer.h"
#include "../Define/Enum.h"

const int Laby_Height = 15;

Stairs::Stairs(Position<int> argPos):BaseBlock(argPos){

	imageKind = Laby_Stairs;

}

Stairs::~Stairs(){
}

void Stairs::Update(){



}

void Stairs::Draw(){

	DrawGraph((pos.GetDx() * Block_Size), (pos.GetDy() * Block_Size), image[Laby_Road], TRUE);

	//ˆêŽž“I
	DrawGraph((pos.GetDx() * Block_Size), (pos.GetDy() * Block_Size), image[imageKind], TRUE);

}

bool Stairs::HitAction(){

	return passFlag;
}
