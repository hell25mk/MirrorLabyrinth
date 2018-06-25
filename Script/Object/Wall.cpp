#include "Wall.h"
#include "../Define/Enum.h"

C_Wall::C_Wall(C_Position<int> argPos):C_BaseBlock(argPos){

	imageKind = Laby_Wall;
	passFlag = false;

}

C_Wall::~C_Wall(){
}

void C_Wall::Update(){



}

void C_Wall::Draw(){

	DrawGraph((pos.x * Block_Size), (pos.y * Block_Size), image[Laby_Road], TRUE);
	DrawGraph((pos.x * Block_Size), (pos.y * Block_Size), image[imageKind], TRUE);

}

bool C_Wall::HitAction(){

	return passFlag;
}
